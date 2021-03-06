﻿#ifndef HGL_PRIVATE_STRING_INCLUDE
#define HGL_PRIVATE_STRING_INCLUDE

namespace hgl
{
	class PrivateString
	{
	public:

		int count;
		int length;
		int malloc_length;		//实际分配长度

		wchar_t *str;

	public:

    	PrivateString();
		PrivateString(const wchar_t *,int,bool);
		~PrivateString();

        void AddRef();
        bool Release();

		void Insert(int,wchar_t);
		void Insert(int,const wchar_t *);

		void Append(wchar_t);
		void Append(const wchar_t *,int=-1);

		void Delete(int,int);
	};
}//namespace hgl
#endif//HGL_PRIVATE_STRING_INCLUDE
