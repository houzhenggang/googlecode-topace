#ifndef HGL_COMPILER_MICROSOFT_INCLUDE
#define HGL_COMPILER_MICROSOFT_INCLUDE
//--------------------------------------------------------------------------------------------------            
#define HGL_COMPILER_NAME	L"Microsoft C/C++"

#if _MSC_VER < 1500						//Visual C++ 2008(9.0)
	#error �������汾̫�ͣ�����֧��
#endif//

#define enum_uint(name)	enum name
#define vsnwprintf _vsnwprintf
//--------------------------------------------------------------------------------------------------
#include<hgl/platform/compiler/DataTypeTypedef.H>
#include<hgl/platform/compiler/Property.H>
//--------------------------------------------------------------------------------------------------
#define _USE_MATH_DEFINES				//ʹ����ѧ��������
//--------------------------------------------------------------------------------------------------
#pragma warning(disable:4311)			// ģ�徯��
#pragma warning(disable:4800)			// int -> bool ������ʧ����
#pragma warning(disable:4244)			// double -> int ���ȶ�ʧ����
#pragma warning(disable:4804)			// ����ȫ�����ͱȽ�
#pragma warning(disable:4805)			// ����ȫ�����ͱȽ�

#pragma comment(lib,"OpenGL32.LIB")		// ����OpenGL��
#pragma comment(lib,"GLU32.LIB")		// ����OpenGL��

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif//

#ifndef _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_DEPRECATE
#endif//

#ifndef _CRT_NON_CONFORMING_SWPRINTFS
#define _CRT_NON_CONFORMING_SWPRINTFS
#endif//
//--------------------------------------------------------------------------------------------------
#endif//HGL_COMPILER_MICROSOFT_INCLUDE