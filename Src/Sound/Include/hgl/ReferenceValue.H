#ifndef HGL_REFERENCEVALUE_INCLUDE
#define HGL_REFERENCEVALUE_INCLUDE

namespace hgl
{
	class ReferenceValue                                                                            ///�ο���
	{
	public:

		float cur;      ///<��ǰ��
		float max;      ///<�����

	public:

		ReferenceValue()
		{
			cur=0;
			max=0;
		}
	};
}

#endif//HGL_REFERENCEVALUE_INCLUDE