public: //�¼�

	DefEvent(bool,OnMouseMove            ,(int,int,uint));                ///<����ƶ���
	DefEvent(bool,OnMouseWheel           ,(int,int, int));                ///<������ת����
	DefEvent(bool,OnMouseLeftDown        ,(int,int,uint));                ///<������������
	DefEvent(bool,OnMouseLeftUp          ,(int,int,uint));                ///<������������
	DefEvent(bool,OnMouseLeftDoubleClick ,(int,int,uint));                ///<������˫����
	DefEvent(bool,OnMouseMidDown         ,(int,int,uint));                ///<����м�������
	DefEvent(bool,OnMouseMidUp           ,(int,int,uint));                ///<����м�������
	DefEvent(bool,OnMouseMidDoubleClick  ,(int,int,uint));                ///<����м�˫����
	DefEvent(bool,OnMouseRightDown       ,(int,int,uint));                ///<����Ҽ�������
	DefEvent(bool,OnMouseRightUp         ,(int,int,uint));                ///<����Ҽ�������
	DefEvent(bool,OnMouseRightDoubleClick,(int,int,uint));                ///<����Ҽ�˫����

	DefEvent(bool,OnJoystickDown,	(uint));								///<��Ϸ�˰�ť������
	DefEvent(bool,OnJoystickPress,	(uint));								///<��Ϸ�˰�ť������
	DefEvent(bool,OnJoystickUp,		(uint));								///<��Ϸ�˰�ť������

	DefEvent(bool,OnKeyDown          ,(uint));                            ///<�а���������
	DefEvent(bool,OnKeyPress         ,(uint));                            ///<�а���������
	DefEvent(bool,OnKeyUp            ,(uint));                            ///<�а���������

	DefEvent(bool,OnChar             ,(wchar_t));                           ///<���ַ�������

	DefEvent(bool,OnEvent            ,(int,void *));                        ///<���Զ����¼���