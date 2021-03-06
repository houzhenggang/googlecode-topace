
#include <tchar.h>
#include <stdio.h>
#include"IniFile.h"
tSystemSet SystemSet;


char Writeini[64]={0};
void loadIniFile()
{
	FILE *IntFile=NULL;
	fopen_s(&IntFile,".\\set.ini","r");
	if (IntFile)
	{
		fclose(IntFile);

	}
	else
	{
		WritePrivateProfileString(_T("SystemSet"),_T("winW"),_T("800"),_T(".\\set.ini"));
		WritePrivateProfileString(_T("SystemSet"),_T("winH"),_T("600"),_T(".\\set.ini"));
		WritePrivateProfileString(_T("SystemSet"),_T("bits"),_T("32"),_T(".\\set.ini"));
		WritePrivateProfileString(_T("SystemSet"),_T("depth"),_T("24"),_T(".\\set.ini"));
		WritePrivateProfileString(_T("SystemSet"),_T("isFullScreem"),_T("0"),_T(".\\set.ini"));
		WritePrivateProfileString(_T("SystemSet"),_T("SYNC"),_T("0"),_T(".\\set.ini"));
		WritePrivateProfileString(_T("SystemSet"),_T("LOW"),_T("0"),_T(".\\set.ini"));
		WritePrivateProfileString(_T("SystemSet"),_T("AA"),_T("0"),_T(".\\set.ini"));
		WritePrivateProfileString(_T("SystemSet"),_T("FPS"),_T("60"),_T(".\\set.ini"));
		WritePrivateProfileString(_T("SystemSet"),_T("Light"),_T("0"),_T(".\\set.ini"));
		WritePrivateProfileString(_T("SystemSet"),_T("Water"),_T("0"),_T(".\\set.ini"));
		WritePrivateProfileString(_T("SystemSet"),_T("Bloom"),_T("0"),_T(".\\set.ini"));
		WritePrivateProfileString(_T("SystemSet"),_T("Shadow"),_T("0"),_T(".\\set.ini"));
		WritePrivateProfileString(_T("SystemSet"),_T("MoveBlur"),_T("0"),_T(".\\set.ini"));
		WritePrivateProfileString(_T("SystemSet"),_T("Cloud"),_T("0"),_T(".\\set.ini"));
		
		WritePrivateProfileString(_T("SystemSet"),_T("LineWidth"),_T("1"),_T(".\\set.ini"));
		WritePrivateProfileString(_T("SystemSet"),_T("FogColorR"),_T("255"),_T(".\\set.ini"));
		WritePrivateProfileString(_T("SystemSet"),_T("FogColorG"),_T("255"),_T(".\\set.ini"));
		WritePrivateProfileString(_T("SystemSet"),_T("FogColorB"),_T("255"),_T(".\\set.ini"));
		WritePrivateProfileString(_T("SystemSet"),_T("FogDensity"),_T("35"),_T(".\\set.ini"));
		}

		SystemSet.winW=GetPrivateProfileInt(_T("SystemSet"),_T("winW"),800,_T(".\\set.ini"));
		SystemSet.winH=GetPrivateProfileInt(_T("SystemSet"),_T("winH"),600,_T(".\\set.ini"));
		SystemSet.bits=GetPrivateProfileInt(_T("SystemSet"),_T("bits"),32,_T(".\\set.ini"));
		SystemSet.depth=GetPrivateProfileInt(_T("SystemSet"),_T("depth"),24,_T(".\\set.ini"));
		if(GetPrivateProfileInt(_T("SystemSet"),_T("isFullScreem"),0,_T(".\\set.ini"))>0)
			SystemSet.isFullScreem=true;
		else
			SystemSet.isFullScreem=false;
		if(GetPrivateProfileInt(_T("SystemSet"),_T("SYNC"),0,_T(".\\set.ini"))>0)
			SystemSet.SYNC=true;
		else
			SystemSet.SYNC=false;
		if(GetPrivateProfileInt(_T("SystemSet"),_T("LOW"),0,_T(".\\set.ini"))>0)
			SystemSet.LOW=true;
		else
			SystemSet.LOW=false;
		SystemSet.AA=GetPrivateProfileInt(_T("SystemSet"),_T("AA"),0,_T(".\\set.ini"));
		SystemSet.FPS=GetPrivateProfileInt(_T("SystemSet"),_T("FPS"),60,_T(".\\set.ini"));
		SystemSet.Light=GetPrivateProfileInt(_T("SystemSet"),_T("Light"),0,_T(".\\set.ini"));
		SystemSet.Water=GetPrivateProfileInt(_T("SystemSet"),_T("Water"),0,_T(".\\set.ini"));
		SystemSet.Bloom=GetPrivateProfileInt(_T("SystemSet"),_T("Bloom"),0,_T(".\\set.ini"));
		SystemSet.Shadow=GetPrivateProfileInt(_T("SystemSet"),_T("Shadow"),0,_T(".\\set.ini"));
		SystemSet.MoveBlur=GetPrivateProfileInt(_T("SystemSet"),_T("MoveBlur"),0,_T(".\\set.ini"));
		SystemSet.Cloud=GetPrivateProfileInt(_T("SystemSet"),_T("Cloud"),0,_T(".\\set.ini"));
		
		SystemSet.LineWidth=max(1,GetPrivateProfileInt(_T("SystemSet"),_T("LineWidth"),1,_T(".\\set.ini")));
		SystemSet.FogColorR=GetPrivateProfileInt(_T("SystemSet"),_T("FogColorR"),255,_T(".\\set.ini"));
		SystemSet.FogColorG=GetPrivateProfileInt(_T("SystemSet"),_T("FogColorG"),255,_T(".\\set.ini"));
		SystemSet.FogColorB=GetPrivateProfileInt(_T("SystemSet"),_T("FogColorB"),255,_T(".\\set.ini"));
		SystemSet.FogDensity=GetPrivateProfileInt(_T("SystemSet"),_T("FogDensity"),35,_T(".\\set.ini"));
}

void SaveIniFile()
{

	_itoa_s(SystemSet.winW,Writeini,sizeof(Writeini),10);			WritePrivateProfileString(_T("SystemSet"),_T("winW"),Writeini,_T(".\\set.ini"));
	_itoa_s(SystemSet.winH,Writeini,sizeof(Writeini),10);			WritePrivateProfileString(_T("SystemSet"),_T("winH"),Writeini,_T(".\\set.ini"));
	_itoa_s(SystemSet.bits,Writeini,sizeof(Writeini),10);			WritePrivateProfileString(_T("SystemSet"),_T("bits"),Writeini,_T(".\\set.ini"));
	_itoa_s(SystemSet.depth,Writeini,sizeof(Writeini),10);		WritePrivateProfileString(_T("SystemSet"),_T("depth"),Writeini,_T(".\\set.ini"));
	_itoa_s(SystemSet.isFullScreem,Writeini,sizeof(Writeini),10);	WritePrivateProfileString(_T("SystemSet"),_T("isFullScreem"),Writeini,_T(".\\set.ini"));
	_itoa_s(SystemSet.SYNC,Writeini,sizeof(Writeini),10);			WritePrivateProfileString(_T("SystemSet"),_T("SYNC"),Writeini,_T(".\\set.ini"));
	_itoa_s(SystemSet.LOW,Writeini,sizeof(Writeini),10);			WritePrivateProfileString(_T("SystemSet"),_T("LOW"),Writeini,_T(".\\set.ini"));
	_itoa_s(SystemSet.AA,Writeini,sizeof(Writeini),10);			WritePrivateProfileString(_T("SystemSet"),_T("AA"),Writeini,_T(".\\set.ini"));
	_itoa_s(SystemSet.FPS,Writeini,sizeof(Writeini),10);			WritePrivateProfileString(_T("SystemSet"),_T("FPS"),Writeini,_T(".\\set.ini"));
	_itoa_s(SystemSet.Light,Writeini,sizeof(Writeini),10);		WritePrivateProfileString(_T("SystemSet"),_T("Light"),Writeini,_T(".\\set.ini"));
	_itoa_s(SystemSet.Water,Writeini,sizeof(Writeini),10);		WritePrivateProfileString(_T("SystemSet"),_T("Water"),Writeini,_T(".\\set.ini"));
	_itoa_s(SystemSet.Bloom,Writeini,sizeof(Writeini),10);		WritePrivateProfileString(_T("SystemSet"),_T("Bloom"),Writeini,_T(".\\set.ini"));
	_itoa_s(SystemSet.Shadow,Writeini,sizeof(Writeini),10);		WritePrivateProfileString(_T("SystemSet"),_T("Shadow"),Writeini,_T(".\\set.ini"));
	_itoa_s(SystemSet.MoveBlur,Writeini,sizeof(Writeini),10);		WritePrivateProfileString(_T("SystemSet"),_T("MoveBlur"),Writeini,_T(".\\set.ini"));
	_itoa_s(SystemSet.Cloud,Writeini,sizeof(Writeini),10);		WritePrivateProfileString(_T("SystemSet"),_T("Cloud"),Writeini,_T(".\\set.ini"));

	_itoa_s(SystemSet.LineWidth,Writeini,sizeof(Writeini),10);		WritePrivateProfileString(_T("SystemSet"),_T("LineWidth"),Writeini,_T(".\\set.ini"));
	_itoa_s(SystemSet.FogColorR,Writeini,sizeof(Writeini),10);		WritePrivateProfileString(_T("SystemSet"),_T("FogColorR"),Writeini,_T(".\\set.ini"));
	_itoa_s(SystemSet.FogColorG,Writeini,sizeof(Writeini),10);		WritePrivateProfileString(_T("SystemSet"),_T("FogColorG"),Writeini,_T(".\\set.ini"));
	_itoa_s(SystemSet.FogColorB,Writeini,sizeof(Writeini),10);		WritePrivateProfileString(_T("SystemSet"),_T("FogColorB"),Writeini,_T(".\\set.ini"));
	_itoa_s(SystemSet.FogDensity,Writeini,sizeof(Writeini),10);		WritePrivateProfileString(_T("SystemSet"),_T("FogDensity"),Writeini,_T(".\\set.ini"));
}