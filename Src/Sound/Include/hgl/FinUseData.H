#ifndef HGL_FIN_USE_DATA_INCLUDE
#define HGL_FIN_USE_DATA_INCLUDE

#include<hgl/List.H>
namespace hgl
{
	template<typename F,typename T> struct FudItem
	{
		F flag;					//ʶ���ʶ

		T data;					//����

		FudItem<F,T> 	*prev,		//ǰһ����
						*next;		//��һ����
	};

	/**
	* ����������ģ��(����������ʱ�����ʱ��û��ʹ�õ����)<br>
	* �����ģ��ʹ��˫ͷ������ÿ�����ӻ�ʹ�õ����ݻᱻ�Ƶ���������ǰ�ˡ�<br>
	* ����ʹ������͵����ݻᱻ������������ĩ�ˣ�����������ʱ����ĩ�˵����ݽ��ᱻ�����
	*/
	template<typename F,typename T> class FinUseData:public Object									///����������ģ��(������ʹ��ʱ��Ϊ��׼)
	{
		typedef FinUseData<F,T> this_class;

	protected:

		FudItem<F,T> 	*start_item,	//������
						*end_item;		//β����

		int count,max_count;

				int GetCount(){return count;}

				int  GetMaxCount(){return max_count;}
		virtual void SetMaxCount(int);

	protected:

		virtual bool Create(const F &,T &);															///<��������
		virtual void Clear(const F &,T &);															///<�������

				void MoveToStart(FudItem<F,T> *);													///<�ƶ�ĳһ�����ݵ���ǰ��

				void Delete(FudItem<F,T> *);														///<���ĳһ������

            	void ClearEnd();																	///<������һ������

	public:	//����

		Property<int> Count;        																///<��ǰ��������������
		Property<int> MaxCount;                                                                     ///<��ǰ���������ֵ

    public:

        FinUseData(int);
        virtual ~FinUseData();

		virtual FudItem<F,T> *	Add		(const F &,const T &);	  									///<����һ������
		virtual bool			Find	(const F &,T &,bool=true);									///<ȡ��һ������(���û�в����Զ�����)
		virtual bool 			Get		(const F &,T &,bool=true); 									///<ȡ��һ������(���û�л��Զ�����)
				void 			Clear	();						  									///<�����������

				void			DeleteByFlag(const F &);
				void 			DeleteByData(T &);
				bool			Update		(const F &,T &);										///<��������
	};
}

#include<hgl/template/FinUseData.CPP>
#endif//HGL_FIN_USE_DATA_INCLUDE