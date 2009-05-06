#ifndef HGL_INDEX_DATA_CPP
#define HGL_INDEX_DATA_CPP

#include<hgl/IndexData.H>
#include<hgl/Stream.H>
#include<hgl/TDF.H>
namespace hgl
{
	template<typename F,typename T,typename data_struct>
	_IndexData<F,T,data_struct>::_IndexData()
	{
		OnSaveToStream=NULL;
		OnLoadFromStream=NULL;

		hglSetPropertyRead(Count,this,this_calss::GetCount);
	}

	/**
	* ���������Ƿ����
	* @param flag ���ݱ�ʶ
	* @return ��������������-1��ʾ������
	*/
	template<typename F,typename T,typename data_struct>
	int _IndexData<F,T,data_struct>::Find(const F &flag)
	{
		int left=0,right=data_list.Count-1;				//ʹ��left,right����ʹ��min,max��Ϊ���ô����ܹ����õ��Ķ���
		int mid;

		while(left<=right)
		{
			if(data_list[left ]->flag==flag)return(left);
			if(data_list[right]->flag==flag)return(right);

			mid=(right+left)/2;

			if(data_list[mid]->flag==flag)return(mid);

			if(data_list[mid]->flag>flag)
			{
				left++;
				right=mid-1;
			}
			else
			{
				right--;
				left=mid+1;
			}
		}

		return(-1);
	}
	
	template<typename F,typename T,typename data_struct>
	int _IndexData<F,T,data_struct>::FindPos(const F &flag)
	{
		int left=0,right=data_list.Count-1;
		int mid;

		while(left<=right)
		{
			if(flag<=data_list[left ]->flag)return(left);
			if(flag>=data_list[right]->flag)return(right+1);

			mid=(right+left)/2;

			if(data_list[mid]->flag==flag)return(mid);

			if(data_list[mid]->flag>flag)
			{
				if(data_list[mid-1]->flag<=flag)return(mid);

				left++;
				right=mid-1;
			}
			else
			{
				if(data_list[mid+1]->flag>=flag)return(mid+1);

				right--;
				left=mid+1;
			}
		}

		return(-1);
	}

	template<typename F,typename T,typename data_struct>
	int _IndexData<F,T,data_struct>::FindByData(const T &data)
	{
		int n=data_list.Count;

		while(n--)
			if(data_list[n]->data==data)
				return(n);

		return -1;
	}

	/**
	* ����һ������
	* @param flag ���ݱ�ʶ
	* @param data ����
	*/
	template<typename F,typename T,typename data_struct>
	data_struct *_IndexData<F,T,data_struct>::Add(const F &flag,const T &data)
	{
		data_struct *ds=data_list.Insert(FindPos(flag));

		ds->flag	=flag;
		ds->data	=data;

		return(ds);
	}
	
	/**
	* ����һ������
	* @param flag ���ݱ�ʶ
	* @return �����õ�����
	*/
	template<typename F,typename T,typename data_struct>
	T &_IndexData<F,T,data_struct>::Add(const F &flag)
	{
		data_struct *ds=data_list.Insert(FindPos(flag));

		ds->flag	=flag;

		return ds->data;
	}

	/**
	* ����һ������
	* @param obj ����
	*/
	template<typename F,typename T,typename data_struct>
	void _IndexData<F,T,data_struct>::Add(data_struct *obj)
	{
		data_list.Insert(FindPos(obj->flag),obj);
	}
	
 	/**
	* ȡ������
	* @param flag ���ݱ�ʶ
	* @param data ���ݴ�Ŵ�
	* @return �Ƿ�ȡ�óɹ�
	*/
	template<typename F,typename T,typename data_struct>
	bool _IndexData<F,T,data_struct>::Get(const F &flag,T &data)
	{
		int result=Find(flag);

		if(result!=-1)
		{
			data=data_list[result]->data;

			return(true);
		}
		else
			return(false);
	}

	template<typename F,typename T,typename data_struct>
	bool _IndexData<F,T,data_struct>::Get(int index,F &f,T &t)
	{
		if(index<0||index>=data_list.Count)return(false);

		data_struct *ds=data_list[index];

		f=ds->flag;
		t=ds->data;

		return(true);
	}

	/**
	* ��������,���ָ����ʶ�����ݲ����ڣ��򴴽�����
	* @param flag ���ݱ�ʶ
	* @param data ����
	*/
	template<typename F,typename T,typename data_struct>
	void _IndexData<F,T,data_struct>::Set(const F &flag,T &data)
	{
		int result=Find(flag);

		if(result!=-1)
			data_list[result]->data=data;
		else
			Add(flag,data);
	}

	/**
	* ɾ��һ������
	* @param flag Ҫɾ�������ݱ�ʶ
	*/
	template<typename F,typename T,typename data_struct>
	void _IndexData<F,T,data_struct>::DeleteByIndex(const F &flag)
	{
		int result=Find(flag);

		if(result!=-1)
			data_list.Delete(result);
	}

	/**
	* ɾ��һ������
	* @param tp Ҫɾ��������
	*/
	template<typename F,typename T,typename data_struct>
	void _IndexData<F,T,data_struct>::DeleteByData(T &tp)
	{
		int n=data_list.Count;

		while(n--)
			if(data_list[n]->data==tp)
			{
				data_list.Delete(n);
				return;
			}
	}


	/**
	* ɾ��һ������
	* @param index Ҫɾ������������
	*/
	template<typename F,typename T,typename data_struct>
	void _IndexData<F,T,data_struct>::DeleteBySerial(int index)
	{
    	data_list.Delete(index);
	}

	/**
	* ��������,������ĺ�Set��ͬ,��Ҫ��ָ����ʶ�����ݱ�����ڣ����ͻ����ʧ��
	* @param flag ���ݱ�ʶ
	* @param data �µ���������
	* @param return �Ƿ���ĳɹ�
	*/
	template<typename F,typename T,typename data_struct>
	bool _IndexData<F,T,data_struct>::Change(const F &flag,T &data)
	{
		int result=Find(flag);

		if(result!=-1)
		{
			data_list[result]->data=data;

			return(true);
		}
		else
        	return(false);
	}

	/**
	* �����������
	*/
	template<typename F,typename T,typename data_struct>
	void _IndexData<F,T,data_struct>::Clear()
	{
		data_list.Clear();
	}
	
	/**
	* ���������б�������
	* @param str Ҫ�������
	* @return �Ƿ񱣴�ɹ�
	*/
	template<typename F,typename T,typename data_struct>
	bool _IndexData<F,T,data_struct>::SaveToStream(Stream *str)
	{
		if(!str||OnSaveToStream==NULL)return(false);

		int n=data_list.Count;

		str->WriteInt32(n);
		for(int i=0;i<n;i++)
		{
			data_struct *obj=data_list[i];

			if(CallEvent(OnSaveToStream,(str,obj->flag,obj->data))==false)
            	return(false);
		}

		return(true);
	}

	/**
	* �����м��������б�
	* @param str Ҫ�������
	* @return �Ƿ񱣴�ɹ�
	*/
	template<typename F,typename T,typename data_struct>
	bool _IndexData<F,T,data_struct>::LoadFromStream(Stream *str)
	{
		Clear();
		
		if(!str||OnLoadFromStream==NULL)return(false);

		int n;

		str->ReadInt32(n);

		if(n<0)return(false);
		
		for(int i=0;i<n;i++)
		{
			F flag;
			T data;

			if(CallEvent(OnLoadFromStream,(str,flag,data)))
				Add(flag,data);
			else
            	return(false);
		}

		return(true);
	}
}

namespace hgl
{
	/**
	* ����һ������,���ָ���ı�Ǵ��ڣ��򷵻��Ѵ��ڵ�����
	* @param flag ���
	* @return �ñ�ǵ�����ָ��
	*/                         
	template<typename F,typename T,typename data_struct>
	T *_IndexObject<F,T,data_struct>::Create(const F &flag)
	{                
		int index=Find(flag);

		if(index!=-1)
		{
			return data_list[index]->data;
		}
		else
		{
			T *result=new T;
			
			Add(flag,result);

			return result;
		}
	}

	/**
	* ��������,���ָ����ʶ�����ݲ����ڣ��򴴽�����
	* @param flag ���ݱ�ʶ
	* @param data ����
	*/
	template<typename F,typename T,typename data_struct>
	void _IndexObject<F,T,data_struct>::Set(const F &flag,T *data)
	{
		int index=Find(flag);

		if(index!=-1)
		{
			delete data_list[index]->data;

			data_list[index]->data=data;
		}
		else
			Add(flag,data);
	}

	/**
	* ɾ��һ������
	* @param flag Ҫɾ�������ݱ�ʶ
	*/
	template<typename F,typename T,typename data_struct>
	void _IndexObject<F,T,data_struct>::DeleteByIndex(const F &flag)
	{
		int index=Find(flag);

		if(index!=-1)
		{
			delete data_list[index]->data;
			
			data_list.Delete(index);
		}
	}

 	template<typename F,typename T,typename data_struct>
	int _IndexObject<F,T,data_struct>::FindByData(T *tp)
	{
		int n=data_list.Count;

		while(n--)
			if(data_list[n]->data==tp)
				return(n);

		return(-1);
	}

	/**
	* ɾ��һ������
	* @param tp Ҫɾ��������
	*/
	template<typename F,typename T,typename data_struct>
	void _IndexObject<F,T,data_struct>::DeleteByData(T *tp)
	{
		int index=FindByData(tp);

		if(index!=-1)
		{
			delete data_list[index]->data;

			data_list.Delete(index);
		}
	}

	/**
	* ɾ��һ������
	* @param index Ҫɾ�������ݵ����к�
	*/
	template<typename F,typename T,typename data_struct>
	void _IndexObject<F,T,data_struct>::DeleteBySerial(int index)
	{
		if(index>=0||index<data_list.Count)
		{
			delete data_list[index]->data;

			data_list.Delete(index);
		}
	}

	/**
	* ��������,������ĺ�Set��ͬ,��Ҫ��ָ����ʶ�����ݱ�����ڣ����ͻ����ʧ��
	* @param flag ���ݱ�ʶ
	* @param data �µ���������
	* @param return �Ƿ���ĳɹ�
	*/
	template<typename F,typename T,typename data_struct>
	bool _IndexObject<F,T,data_struct>::Change(const F &flag,T *data)
	{
		int index=Find(flag);

		if(index!=-1)
		{                              
			delete data_list[index]->data;
			
			data_list[index]->data=data;

			return(true);
		}
		else
        	return(false);
	}

	/**
	* �����������
	*/
	template<typename F,typename T,typename data_struct>
	void _IndexObject<F,T,data_struct>::Clear()
	{
		int n=data_list.Count;

		while(n--)
			delete data_list[n]->data;

		data_list.Clear();
	}
}
#endif//HGL_INDEX_DATA_CPP