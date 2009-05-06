#ifndef HGL_DATATYPE_INCLUDE
#define HGL_DATATYPE_INCLUDE

#include<hgl/platform/Platform.H>				// ƽ̨����
#include<hgl/SmartPointer.H>

#ifndef NULL
#define NULL 0
#endif//

#ifndef M_PI
#define M_PI        3.14159265358979323846
#endif//

#define SAFE_DELETE(name)	{	\
								if(name)	\
									delete name;	\
							}

#define SAFE_CLEAR(name)	{	\
								if(name)	\
								{	\
									delete name;	\
									name=NULL;	\
								}	\
							}

#define SAFE_DELETE_ARRAY(name)	{	\
									if(name)	\
										delete[] name;	\
								}
								
#define SAFE_CLEAR_ARRAY(name)	{	\
									if(name)	\
									{	\
										delete[] name;	\
										name=NULL;	\
									}	\
                            	}

#define CLEAR_OBJECT_ARRAY(name,num)	{	\
											int clear_object_array_number=num;	\
											\
											while(clear_object_array_number--)	\
												delete name[clear_object_array_number];	\
											\
											delete[] name;	\
											name=NULL;	\
										}

#define SAFE_CLEAR_OBJECT_ARRAY(name,num)	{	\
												if(name)	\
												{	\
													int safe_clear_object_array_number=num;	\
													\
													while(safe_clear_object_array_number--)	\
														delete name[safe_clear_object_array_number];	\
													\
													delete[] name;	\
													name=NULL;	\
												}	\
											}

#define FREE_OBJECT_ARRAY(name,num)	{	\
										int free_object_array_number=num;	\
										\
										while(free_object_array_number--)	\
											delete name[free_object_array_number];	\
										\
										hgl_free(name);	\
										name=NULL;	\
									}

#define SAFE_FREE_OBJECT_ARRAY(name,num)	{	\
												if(name)	\
													FREE_OBJECT_ARRAY(name,num);	\
											}

#define SAFE_RECREATE(name,code)	{	\
										if(name)	\
											delete name;	\
										\
										name=code;	\
									}

#define ARRAY_CALL(name,num,code)	{	\
										int array_call_number=num;	\
										\
										while(array_call_number--)	\
											name[array_call_number]->code;	\
									}

#define LOAD_FUNC(type,func)	type func(void *buf,int buf_size)	\
								{	\
									if(!buf||buf_size<=0)return 0;	\
									\
									MemStream ms(buf,buf_size);	\
									\
									return(func(&ms));	\
								}	\
								\
								type func(const String &filename)	\
								{	\
									FileStream fs;	\
									\
									if(fs.Open(filename))	\
										return(func(&fs));	\
									else	\
										return 0;	\
								}	\
								\
								type func(HAC *hac,const String &filename)	\
								{	\
									if(!hac)return 0;	\
									\
									Stream *s=hac->LoadFile(filename);	\
									\
									if(s)	\
									{	\
										type result=func(s);	\
										\
										delete s;	\
										return(result);	\
									}	\
									\
									return 0;	\
								}

#define SAVE_FUNC(type,func)	bool func(type data,void *buf,int buf_size)	\
								{	\
									if(!buf||buf_size<=0)return(false);	\
									\
									MemStream ms(buf,buf_size);	\
									\
									return(func(data,&ms));	\
								}	\
								\
								bool func(type data,const String &filename)	\
								{	\
									FileStream fs;	\
									\
									if(fs.Create(filename))	\
										return(func(data,&fs));	\
									else	\
										return(false);	\
								}	
//--------------------------------------------------------------------------------------------------
namespace hgl                           				///������Ϸ��������ʹ�õ����ֿռ�
{
	namespace info										//�ڲ����ܣ��벻Ҫʹ��
	{
		void InitString();								//��ʼ����־�ַ���
		void ClearString();								//�����־�ַ���
		void SetString(int,const wchar_t *);			//���ñ�־�ַ���

		void InitPointer();								//��ʼ����־ָ��
		void SetPointer(int,void *);					//���ñ�־ָ��
	}

	namespace info
	{
		/**
		* ���±�־�ִ�ö��
		* @see GetString
		*/
		enum_uint(HGLFlagString)
		{
			hfsNone=0,				///<��ʼ���壬������

			hfsName,              	///<��������
			hfsEnglishName,         ///<Ӣ������
			hfsVersion,             ///<�汾�ִ�

			hfsAuthor,              ///<������

			hfsCMGDKPath,			///<CMGDK·��
			hfsPlugInPath,			///<CMGDK���·��
			hfsGUIPath,				///<CMGDK GUI·��
			hfsStartPath,			///<��������·��
			
			hfsOSPath,				///<�û�����ϵͳ
			hfsDesktopPath,			///<�û�����·��
			hfsTempPath,			///<�û���ʱ�ļ�·��
			hfsUserData,			///<�û��ļ�·��(�ҵ�����),(Win2000/XP/2003:Application Data,WinVista/2008/7:AppData\Roaming)
			hfsUserPath,			///<�û��ļ�·��(�ҵ��ĵ�)
			hfsUserPicsPath,		///<�û��ļ�·��(�ҵ�ͼƬ)
			hfsUserProgramPath,		///<�û�����·��(��ʼ�˵�)

			hfsAppFileName,			///<��ǰ�����ļ���

			hfsEnd,					///<�������壬������
		};

		const wchar_t *GetString(HGLFlagString);                                                    ///<ȡ�ù��±���ַ���

		/**
		* ���±�־ָ��ö��
		* @see GetPointer
		*/
		enum_uint(HGLFlagPointer)
		{
			hfpNone=0,				///<��ʼ���壬������

			hfpApplication,			///<��ͬ��Application
			hfpFont,				///<ȱʡ����(TileFone *����)
			hfpFlow,				///<��ǰ�����

			hfpEnd					///<�������壬������
		};

		const void *GetPointer(HGLFlagPointer);
	}
	
	using namespace info;
}

//#ifndef _DEBUG

	#define hgl_malloc	malloc
	#define hgl_realloc	realloc
	#define hgl_free	free

	#include<malloc.h>
/*
#else

	void *hgl_log_malloc(unsigned int);
	void *hgl_log_realloc(void *,unsigned int);
	void  hgl_log_free(void *);

	void *hgl_log_malloc(unsigned int,const char *,const char *,unsigned long);
	void *hgl_log_realloc(void *,unsigned int,const char *,const char *,unsigned long);
	void  hgl_log_free(void *,const char *,const char *,unsigned long);

	#define hgl_malloc(size) 		hgl_log_malloc(size,__FILE__,__FUNC__,__LINE__)
	#define hgl_realloc(ptr,size)	hgl_log_realloc(ptr,size,__FILE__,__FUNC__,__LINE__)
	#define hgl_free(ptr)           hgl_log_free(ptr,__FILE__,__FUNC__,__LINE__)

	void * operator new(unsigned int s){return hgl_log_malloc(s);}
	void * operator new[](unsigned int s){return hgl_log_malloc(s);}
	void operator delete(void *p){hgl_log_free(p);}
	void operator delete[](void *p){hgl_log_free(p);}
#endif//_DEBUG
*/
//--------------------------------------------------------------------------------------------------
#endif//HGL_DATATYPE_INCLUDE