#ifndef HGL_AUDIO_BUFFER_INCLUDE
#define HGL_AUDIO_BUFFER_INCLUDE

#include<hgl/stream.h>
#include<hgl/HAC.H>
#include<hgl/ObjectBuffer.H>
namespace hgl
{
	/**
	* ��Ƶ�ļ���ʽ
	*/
	enum AudioFileType
	{
		aftNone=0,			///<��ʼ���壬��ʹ�ñ�ʾ�Զ�������չ��ʶ��

		aftWAV,             ///<Wav�����ļ�
		aftOGG,             ///<Vorbis OGG�ļ�

		aftEnd
	};

	typedef AudioFileType AFT;

	/**
	* AudioBuffer��һ���򵥵���Ƶ���ݹ�����
	*/
	class AudioBuffer                                                                               ///��Ƶ���ݻ�������
	{
		bool ok;

		void InitPrivate();

	public:

		uint 	Index;
		double 	Time;                                                                          		///<����������Ƶ���ݿ��Բ��ŵ�ʱ��(��)
		uint 	Size;																				///<����������Ƶ���ݵ����ֽ���

	public:

		AudioBuffer(void *,int,AFT);                                                                ///<���๹�캯��
		AudioBuffer(Stream *,AFT);                                                                  ///<���๹�캯��
		AudioBuffer(const wchar_t *filename=0,AFT=aftNone);                                         ///<���๹�캯��
		AudioBuffer(HAC *,const wchar_t *,AFT=aftNone);	   											///<���๹�캯��
		virtual ~AudioBuffer();                                                                     ///<������������

		bool Load(void *,int,AFT);                                                        			///<���ڴ��м�����Ƶ����
		bool Load(Stream *,AFT);                                                          			///<�����м�����Ƶ����
		bool Load(const wchar_t *,AFT=aftNone);                                                     ///<���ļ��м�����Ƶ����
		bool Load(HAC *,const wchar_t *,AFT=aftNone);												///<��HAC�����ļ��м�����Ƶ����

		void Clear();                                                                               ///<�������
	};

	typedef ObjectBuffer<AudioBuffer> 			AudioBufferBuffer;									///<AudioBuffer���������
	typedef ObjectBufferFromHAC<AudioBuffer> 	AudioBufferHAC;										///<AudioBuffer���������(��HAC����ȡ���ļ�)
}

#endif//AUDIO_BUFFER_INCLUDE