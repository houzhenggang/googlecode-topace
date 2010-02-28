#include "DataUpdata.h"
#include "KeyInput.h"
float angleR=0.0f;
float Test3dsFrame=0.0f;
float maxFreme=100.0f;
bool Test3dsFrameSwitch=false;
extern tKeyInput KeyInput;
void DataUpdata()
{
	if(Test3dsFrameSwitch)
	{
		Test3dsFrame=Test3dsFrame+1.0f;
		if(Test3dsFrame>=maxFreme)
		{
			Test3dsFrame=maxFreme;
			Test3dsFrameSwitch=false;
		}
	}
	else
	{
		Test3dsFrame=Test3dsFrame-1.0f;
		if(Test3dsFrame<=0.0f)
		{
			Test3dsFrame=0.0f;
			Test3dsFrameSwitch=true;
		}
	}
	angleR=angleR+0.2f;
}