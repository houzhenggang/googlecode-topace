#ifndef HGL_COMPILER_CODEGEAR_INCLUDE
#define HGL_COMPILER_CODEGEAR_INCLUDE
//--------------------------------------------------------------------------------------------------
#define HGL_COMPILER_NAME	L"CodeGear C/C++"

#if __BORLANDC__ < 0x0590
	#error �������汾̫�ͣ�����֧��
#endif//

#if __BORLANDC__ >= 0x610
	#define __cplusplus_0x__		//֧��C++0x

	#define enum_uint(name)	enum name:unsigned int
#else
	#define enum_uint(name)	enum name
#endif//

#pragma option -K                       //ǿ��char��������Ϊ�޷�����
#pragma option -6                       //��Pentium Pro/PentiumII��ʽ�Ż�
#pragma option -b                       //ǿ�ƽ�EnumתΪint
//--------------------------------------------------------------------------------------------------
#include<hgl/platform/compiler/DataTypeTypedef.H>     
#include<hgl/platform/compiler/Property.H>
//--------------------------------------------------------------------------------------------------
#endif//HGL_COMPILER_CODEGEAR_INCLUDE