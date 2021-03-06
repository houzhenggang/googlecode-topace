﻿#ifndef HGL_FIN_USE_DATA_CPP
#define HGL_FIN_USE_DATA_CPP

#include<hgl/FinUseData.H>
#include<hgl/Loginfo.H>
namespace hgl
{
	/**
	* 本类构造函数
	* @param value 缓冲区最大数据量
	*/
	template<typename F,typename T>
	FinUseData<F,T>::FinUseData(int value)
	{
		if(value<=0)
		{
			ErrorHint(L"FinUseData缓冲区大小被设置<=0");

			value=3;
		}

		count=0;
		max_count=value;

		start_item=NULL;
		end_item=NULL;

		hglSetPropertyRead(Count,this,this_class::GetCount);
		hglSetProperty(MaxCount,this,this_class::GetMaxCount,this_class::SetMaxCount);
	}

	template<typename F,typename T>
	FinUseData<F,T>::~FinUseData()
	{
    	Clear();
	}

	template<typename F,typename T>
	void FinUseData<F,T>::SetMaxCount(int value)
	{
		if(value<=0)
			ErrorHint(L"FinUseData缓冲区大小被设置<=0，此次设置无效！");
		else
        	max_count=value;
	}

	template<typename F,typename T>
	bool FinUseData<F,T>::Create(const F &,T &)
	{
		return true;
	}

	template<typename F,typename T>
	void FinUseData<F,T>::Clear(const F &,T &)
	{
	}

	template<typename F,typename T>
	void FinUseData<F,T>::ClearEnd()
	{    	
		FudItem<F,T> *temp=end_item->prev;

		Clear(end_item->flag,end_item->data);

		delete end_item;

		end_item=temp;

		if(end_item)					//如果只有一个数据，end_item会为NULL
			end_item->next=NULL;
		else
		{
			#ifdef _DEBUG
			if(count!=1)
			{				
            	PutError(L"FinUseData出错，end_item=NULL,count!=1");            	
			}
			#endif//
			start_item=NULL;			//如果end_item为空，start_item也应该为空
		}

		count--;
	}

	/**
	* 添加一个数据
	* @param flag 数据标识
	* @param data 数据
	*/
	template<typename F,typename T>
	FudItem<F,T> *FinUseData<F,T>::Add(const F &flag,const T &data)
	{
		FudItem<F,T> *temp;

		while(count>=max_count)ClearEnd();			//满了，清除超出的数据

		temp=new FudItem<F,T>;
		temp->flag=flag;
		temp->data=data;

		temp->prev=NULL;
		temp->next=start_item;

		if(start_item)					//如果还没有数据,start会为NULL
			start_item->prev=temp;

		start_item=temp;				//将当前数据设成start_item

		count++;

		if(!end_item)
		{
			#ifdef _DEBUG				//理由上end_item为NULL时应该是没有数据
			if(count!=1)
			{
            	PutError(L"FinUseData出错，end_item=NULL,count!=1");
			}
			else
			#endif//_DEBUG
				end_item=start_item;
		}

    	return(temp);
	}

	template<typename F,typename T>
	void FinUseData<F,T>::MoveToStart(FudItem<F,T> *item)
    {
        if(item!=start_item)						//不是首节点,这个情况下count肯定>1
        {
            if(item!=end_item)						//也不是尾节点,这个情况下count肯定>2
            {
                if(item->next)
                    item->next->prev=item->prev;

                if(item->prev)
                    item->prev->next=item->next;

                start_item->prev=item;

                item->prev=NULL;
                item->next=start_item;

                start_item=item;
            }
            else		//为尾节点
            {
                end_item=end_item->prev;
                end_item->next=NULL;

                item->prev=NULL;
                item->next=start_item;

                start_item->prev=item;

                start_item=item;
            }
        }
    }

	/**
	* 取得一个数据,在没有数据时,不自动创建数据,返回false
	* @param flag 数据标识
	* @param data 数据存放地
	* @param mts 是否对数据调频
	* @return 是否取得数据成功
	*/
	template<typename F,typename T>
	bool FinUseData<F,T>::Find(const F &flag,T &data,bool mts)
	{
		if(count<=0)return(false);

		int n=count;
		FudItem<F,T> *temp=start_item;

		while(n--)
		{
			if(temp->flag==flag)
			{
				data=temp->data;

				if(mts)
	                MoveToStart(temp);

				return(true);
			}
			else
				temp=temp->next;
		}

		return(false);
	}

    /**
	* 取得一个数据,如果数据不存在,调用Create创建数据,如失败返回false
	* @param flag 数据标识
	* @param data 数据存放地       
	* @param mts 是否对数据动态调频
	* @return 是否取得数据 true/false
	*/
	template<typename F,typename T>
	bool FinUseData<F,T>::Get(const F &flag,T &data,bool mts)
	{
		if(Find(flag,data,mts))
			return(true);

		while(count>=max_count)ClearEnd();			//满了，清除超出的数据

		if(Create(flag,data))
		{
			Add(flag,data);

			return(true);
		}

        return(false);
    }

	/**
	* 清数所有数据
	*/
	template<typename F,typename T>
	void FinUseData<F,T>::Clear()
	{
		if(count<=0)return;

        int n=0;
		FudItem<F,T> *temp=start_item;

		while(temp)
		{
			FudItem<F,T> *obj=temp;

			Clear(obj->flag,obj->data);

			temp=obj->next;

			delete obj;
            n++;
		}

        if(n!=count)
        {
            ErrorHint(L"FinUseData Count=%d,Clear=%d",count,n);
        }

		count=0;
		start_item=NULL;
		end_item=NULL;
	}

	template<typename F,typename T>
	void FinUseData<F,T>::Delete(FudItem<F,T> *obj)
	{
		if(!obj)return;
		
		Clear(obj->flag,obj->data);

		if(count>1)
		{
			if(obj==start_item)
			{
				start_item=obj->next;

				start_item->prev=NULL;
			}
			else
			if(obj==end_item)
			{
				end_item=obj->prev;

				end_item->next=NULL;
			}
			else
			{
				obj->prev->next=obj->next;

				obj->next->prev=obj->prev;
			}
		}
		else
		{
			start_item=NULL;
			end_item=NULL;
		}

		delete obj;

		count--;
	}

	template<typename F,typename T>
	void FinUseData<F,T>::DeleteByFlag(const F &flag)
	{
		if(count<=0)return;

		int n=count;
		FudItem<F,T> *temp=start_item;

		while(n--)
		{                       
			if(temp->flag==flag)
			{
				Delete(temp);
				return;
			}

			temp=temp->next;
		}    	
	}
	
	template<typename F,typename T>
	void FinUseData<F,T>::DeleteByData(T &data)
	{
		if(count<=0)return;

		int n=count;
		FudItem<F,T> *temp=start_item;

		while(n--)
		{
			if(temp->data==data)
			{
				Delete(temp);
				return;
			}

			temp=temp->next;
		}    	
	}

	template<typename F,typename T>
	bool FinUseData<F,T>::Update(const F &flag,T &data)
	{
		if(Find(flag,data,false))
		{           
			FudItem<F,T> *obj=temp;
                              
			Clear(obj->flag,obj->data);

			Create(obj->flag,obj->data);
			       	
			return(true);
		}

		if(Create(flag,data))
		{
			Add(flag,data);

			return(true);
		}

        return(false);
    }
}

#endif//HGL_FIN_USE_DATA_CPP
