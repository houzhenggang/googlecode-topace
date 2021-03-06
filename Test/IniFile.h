#ifndef _INIFILE_H
#define _INIFILE_H
#include <windows.h>

#define IniFileChar ".\\set.ini"
struct tSystemSet
{
	int winW;
	int winH;
	int bits;
	int depth;
	bool isFullScreem;
	bool SYNC;
	bool LOW;
	int AA;
	int FPS;
	int Light;
	int Water;
	int Bloom;
	int Shadow;
	int MoveBlur;
	int Cloud;
	int LineWidth;
	int FogColorR;
	int FogColorG;
	int FogColorB;
	int FogDensity;
};


void loadIniFile();
void SaveIniFile();
#endif