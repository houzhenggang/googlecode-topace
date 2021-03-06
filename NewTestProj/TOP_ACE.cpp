/*
When creating your project, uncheck OWL,
uncheck Class Library, select Static
instead of Dynamic and change the target
model to Console from GUI.
Also link glut.lib to your project once its done.
*/
//#define STRICT
//#define DIRECTINPUT_VERSION 0x0800
#include <windows.h>   // Standard Header For Most Programs
#include <GL/glew.h>
#include <GL/gl.h>     // The GL Header File
#include <GL/freeglut.h>   // The GL Utility Toolkit (Glut) Header
#include <pthread.h>
#include "AsciiFont.h"
#include"Textures.h"
#include"Draw.h"
#include"IniFile.h"
#include "GameInput.h"
#include "Font2D.h"
#include "Font3D.h"
#include "Glsl.h"
#include "LoadData_thread.h"	
#pragma comment( lib, "pthreadVC2.lib" )	
#pragma comment( lib, "glew32s.lib" )
#pragma comment( lib, "lib3ds-2_0.lib" )
#ifdef _DEBUG
#pragma comment( linker, "/NODEFAULTLIB:LIBCMT.lib")
#endif
#pragma comment( linker, "/NODEFAULTLIB:LIBC.lib")

float	rtri;						// Angle For The Triangle
float	rquad;						// Angle For The Quad
float   testframe1=0.0f;
int winW=800;
int winH=600;
bool DataLoop=false;
bool DataLoopDF=false;
pthread_mutex_t mutex_DataFream,mutex_LoadData;
pthread_cond_t cond_LoadData;
tLoadDataList * LoadDataList;
struct timespec delay;
Textures * ASCFontTex = NULL;
LARGE_INTEGER t1,t2,feq,feqf,DataThread,DataThreadf;
int frameNumPs=0;
int frame=0;
char showfps[256]={0};
float turn1,turn2,frametest;
char TITLE[512]={0};
extern tGameSet GameSet;
extern tSoundSet SoundSet;
extern tJoyStictKeyVal JoyStictKeyVal;
GLuint Test3DsTexID=0;
Textures * Test3DsTex = NULL;
int DebugShow01=0;
float TestPos[3]={0};
float TestRot[3]={0};
CFont3D * Font3D;

CFont2D * Font2D;
//LONGLONG LLfeq;
HWND MainhDlg;
bool UpDataInputDF=false;
bool UpDataInputDR=false;
bool testkey[11];
float testnum0=0.0f;
int ShowDFTime=0;
void* DataFream(void* Param)
{
	while(DataLoopDF)
	{
		JoyStictUpdeta();


		pthread_mutex_lock( &mutex_DataFream );
		DataLoopDF=DataLoop;
		rtri+=0.2f;	
		if(rtri>=360.0f)
			rtri=rtri-360.0f;
		rquad-=0.15f;
		if(rquad>=360.0f)
			rquad=rquad-360.0f;
		testframe1=testframe1+0.25f;
		if(testframe1>=100.0f)
			testframe1=0.0f;
		UpDataInputDF=true;
		pthread_mutex_unlock( &mutex_DataFream );
/*	if(ispad&&ispadEffect)
	{
		g_pDevice->Acquire();

                if( g_pEffect )
                    g_pEffect->Start( 1, 0 ); // Start the effect
	}*/
	//UpdateInputState(MainhDlg);

		QueryPerformanceFrequency(&feqf);
		QueryPerformanceCounter(&DataThreadf);
		delay.tv_nsec=max(10000000-int((DataThreadf.QuadPart-DataThread.QuadPart)/feqf.QuadPart*1000000000.0),100);
		pthread_delay_np( &delay );
		QueryPerformanceCounter(&DataThread);
	}
	
	return NULL;
}
void Initthread_DataFream()
{
	DataLoop=true;
	DataLoopDF=true;
	delay.tv_nsec=10000000;//1000000000
	delay.tv_sec=0;
    pthread_attr_t attr_DataFream;
    pthread_attr_init(&attr_DataFream); 
	pthread_attr_setscope(&attr_DataFream, PTHREAD_SCOPE_PROCESS);
    pthread_attr_setdetachstate(&attr_DataFream, PTHREAD_CREATE_DETACHED);
	int policy;
	int rs = pthread_attr_getschedpolicy( &attr_DataFream, &policy );
	int priority = sched_get_priority_max( policy );
	struct sched_param param;
	pthread_attr_getschedparam(&attr_DataFream,&param);
	param.sched_priority=priority*2/3;
	pthread_attr_setschedparam(&attr_DataFream,&param);
	pthread_t threadID_DataFream;
	pthread_mutex_init(&mutex_DataFream, NULL);
    pthread_create( &threadID_DataFream, &attr_DataFream, DataFream, NULL);
}
void TestLightInit()
{
	GLfloat mat_specular[]={1.0f,1.0f,1.0f,1.0f};
	GLfloat mat_ambient[]={1.0f,1.0f,1.0f,1.0f};
	GLfloat mat_diffuse[]={1.0f,1.0f,1.0f,1.0f};
	GLfloat mat_shininess[]={100.0f};
	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,mat_specular);
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,mat_ambient);
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,mat_diffuse);
	glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,mat_shininess);
	//glEnable(GL_LIGHTING);
}
void InitGL ( GLvoid )     // Create Some Everyday Functions
{

	glewInit();
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.5f, 0.5f, 0.5f);				// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA   );

	TestLightInit();
	//InitGLSL();
	/*glMatrixMode (GL_PROJECTION);										// Select The Projection Matrix
	glLoadIdentity ();													// Reset The Projection Matrix
	gluPerspective (45.0, (GLfloat)(winW)/(GLfloat)(winH),			// Calculate The Aspect Ratio Of The Window
					10.0f, 100000.0f);		
	glMatrixMode (GL_MODELVIEW);	
	*/
	Test3DsTex = new Textures;
	Test3DsTex->loadfile("Data/Model/Test3dsModel");
	Test3DsTexID=Test3DsTex->LoadToVRAM(GL_LINEAR_MIPMAP_LINEAR);
	
	ASCFontTex=new Textures;
	ASCFontTex->loadfile("Data/Font");
	ASCFontTex->LoadToVRAM(GL_LINEAR_MIPMAP_LINEAR);
	BuildFont(ASCFontTex->TexID);

	QueryPerformanceCounter(&t1);
	QueryPerformanceFrequency(&feq);
	QueryPerformanceFrequency(&feqf);
	//LLfeq=feq.QuadPart;
	sprintf(showfps,"FPS:- -");
	//Fonts.LoadFont("SimSun");

	char szPath[MAX_PATH];
	GetWindowsDirectory(szPath,sizeof(szPath));
	char FontPath[MAX_PATH];

	sprintf(FontPath,"%s/Fonts/simsun.ttc",szPath);
	//FontsTest.LoadFont(FontPath,16,16,128,128);
	//FontsTest.inputTxt("qwerttyyuioop[]");
	init3DTexTest();
	for(int i=0;i<10;i++)
		testkey[i]=false;
}

void display ( void )   // Create The Display Function
{
	QueryPerformanceFrequency(&feq);
	QueryPerformanceCounter(&t2);
	
	if(double((t2.QuadPart-t1.QuadPart)/feq.QuadPart)>=1.0)
	{
		QueryPerformanceCounter(&t1);
		frame=frameNumPs;
		frameNumPs=0;
		if(ASCFontTex->TexType==IS_DDS)
			sprintf(TITLE,"dds");
		if(ASCFontTex->TexType==IS_TGA)
			sprintf(TITLE,"TGA");
		
		//Fonts.inputTxt("ﾋﾎﾌ・23ABC");
		//FontsTest.inputTxt(showfps);

		/*if(!pthread_mutex_trylock(&mutex_LoadData))
		{
			pthread_mutex_unlock( &mutex_LoadData );
			pthread_cond_signal(&cond_LoadData);
		}*/
	}
	else
		frameNumPs=frameNumPs+1;

	sprintf(showfps,"fps:%d %s %32d",frame,TITLE,ShowDFTime);
	pthread_mutex_lock( &mutex_DataFream );


	ShowDFTime=int(delay.tv_nsec);
	UpDataInputDR=UpDataInputDF;
	UpDataInputDF=false;
	turn1=rtri;
	turn2=rquad;
	frametest=testframe1;


	pthread_mutex_unlock( &mutex_DataFream );
	if(UpDataInputDR)
	{
		if(testkey[0]) TestRot[0]=TestRot[0]-1.0f;
		if(testkey[1]) TestRot[0]=TestRot[0]+1.0f;
		if(testkey[2]) TestRot[1]=TestRot[1]-1.0f;
		if(testkey[3]) TestRot[1]=TestRot[1]+1.0f;
		if(testkey[4]) TestPos[0]=TestPos[0]-1.0f;
		if(testkey[5]) TestPos[0]=TestPos[0]+1.0f;
		if(testkey[6]) TestPos[1]=TestPos[1]+1.0f;
		if(testkey[7]) TestPos[1]=TestPos[1]-1.0f;
		if(testkey[8]) TestPos[2]=TestPos[2]+1.0f;
		if(testkey[9]) TestPos[2]=TestPos[2]-1.0f;

		for(int i=0;i<10;i++)
			testkey[i]=false;
	}
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	Draw();
	glColor3f(0.0f,1.0f,0.0f);	
	glEnable( GL_TEXTURE_2D );
	glPrints(0, winH-16, winW,winH,showfps);
	//FontsTest.DrawTXT(winW,winH,0,0,16,16,0);
	//Fonts.DrawTXT(winW,winH,150,winH-32,32,32,0);
	

	
	glutSwapBuffers ( );
  // Swap The Buffers To Not Be Left With A Clear Screen
	
}

void reshape ( int width , int height )   // Create The Reshape Function (the viewport)
{
	if (height==0)										// Prevent A Divide By Zero By
	{
		height=1;										// Making Height Equal One
	}
	glViewport(0,0,width,height);						// Reset The Current Viewport
	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix
	// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,1.0f,100000.0f);
	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									
}

void BeforeExit()
{
	pthread_mutex_lock( &mutex_DataFream );
	DataLoop=false;
	pthread_mutex_unlock( &mutex_DataFream );
		if(ASCFontTex)
		delete ASCFontTex;
	FreeJoyStict();
}
void keyboard ( unsigned char key, int x, int y )
{
	DebugShow01=key;
	//if(UpDataInputDF)
	//	return;


	testkey[10]=false;
	switch ( key ) 
	{
		case 'W':
			testkey[0]=true;
			
			break;
		case 'S':
			testkey[1]=true;
			break;
		case 'A':
			testkey[2]=true;
			break;
		case 'D':
			testkey[3]=true;
			break;
		case VK_LEFT:
			testkey[4]=true;
			break;
		case VK_RIGHT:
			testkey[5]=true;
			break;
		case VK_UP:
			testkey[6]=true;
			break;
		case VK_DOWN:
			testkey[7]=true;
			break;
		case VK_PRIOR:
			testkey[8]=true;
			testnum0=testnum0+0.1f;
			break;
		case VK_NEXT:
			testkey[9]=true;
			break;
		case VK_HOME:
			TestPos[0]=0.0f;
			TestPos[1]=0.0f;
			TestPos[2]=0.0f;
			TestRot[0]=0.0f;
			TestRot[1]=0.0f;
			TestRot[2]=0.0f;
			break;

		case VK_ESCAPE:
			BeforeExit();
			exit ( 0 );
			break;

		default:
			break;

	}

}

void arrow_keys ( int a_keys, int x, int y )  // Create Special Function (required for arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:     // When Up Arrow Is Pressed...
   //   glutFullScreen ( ); // Go Into Full Screen Mode
      break;
    case GLUT_KEY_DOWN:               // When Down Arrow Is Pressed...
	//	glutFullScreen();
	//	glutPositionWindow((GetSystemMetrics(SM_CXFULLSCREEN)-winW)/2,(GetSystemMetrics(SM_CYFULLSCREEN)-winH)/2);
      //glutReshapeWindow ( winW, winH ); // Go Into A 500 By 500 Window
	  
      break;
    default:
      break;
  }
}

void isWindow()
{
	glutInitWindowPosition((GetSystemMetrics(SM_CXFULLSCREEN)-winW)/2,(GetSystemMetrics(SM_CYFULLSCREEN)-winH)/2);
	glutInitWindowSize  ( GameSet.winW, GameSet.winH );
	glutCreateWindow    ( "TEST PROJ" );
}
void isFullScreem()
{
	char GameModeString[64]={0};
	sprintf(GameModeString,"%dx%d:%d@60",GameSet.winW, GameSet.winH,GameSet.bits);
	glutGameModeString(GameModeString);
	glutEnterGameMode();
}
void InitWindow(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	char path[_MAX_PATH];
    GetModuleFileName(hInstance, path, _MAX_PATH);
	char* argv=(char *)path;
	
	glutInit            ( &nCmdShow, &argv ); // Erm Just Write It =)
	if(GameSet.AA>0)
		glutInitDisplayMode ( GLUT_RGBA | GLUT_DOUBLE|GLUT_DEPTH|GLUT_MULTISAMPLE ); // Display Mode
	else
		glutInitDisplayMode ( GLUT_RGBA | GLUT_DOUBLE|GLUT_DEPTH );
	if(GameSet.AA>0)
		glutSetOption(GLUT_MULTISAMPLE,GameSet.AA);
	if(GameSet.isFullScreem)
		isFullScreem();
	else
		isWindow();
	if(GameSet.SYNC)
	{
		typedef BOOL (APIENTRY *PFNWGLSWAPINTERVALFARPROC)( int );
		PFNWGLSWAPINTERVALFARPROC wglSwapIntervalEXT = 0;
		wglSwapIntervalEXT = (PFNWGLSWAPINTERVALFARPROC)
		wglGetProcAddress("wglSwapIntervalEXT");
		wglSwapIntervalEXT(1);
	}
}
int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Initthread_LoadData();
	loadIniFile();
	InitWindow( hInstance,  hPrevInstance,  lpCmdLine,  nCmdShow);
	InitGL ();

	InitJoyStict(glutGetWindowData());
	bool tmpb=SetPriorityClass(GetCurrentProcess() , HIGH_PRIORITY_CLASS);

	Initthread_DataFream();

	
	glutDisplayFunc     ( display );  // Matching Earlier Functions To Their Counterparts
	glutReshapeFunc     ( reshape );
	glutKeyboardFunc    ( keyboard );
	glutSpecialFunc     ( arrow_keys );
	glutIdleFunc		  ( display );
	glutMainLoop        ( );          // Initialize The Main Loop
	

	return 0;
}
