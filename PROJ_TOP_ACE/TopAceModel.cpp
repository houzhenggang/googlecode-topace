#include "TopAceModel.h"//文件头

CTopAceModel::CTopAceModel(void)
{
}

CTopAceModel::~CTopAceModel(void)
{
}

bool CTopAceModel::ReadFile(unsigned char * FileName)
{
	return false;
}

_TAM_Mesh * CTopAceModel::TAM_Get_Mesh(unsigned int MeshID)
{
	return NULL;
}

_TAM_Bone * CTopAceModel::TAM_Get_Bone(unsigned int BoneID)
{
	return NULL;
}

_TAM_Light * CTopAceModel::TAM_Get_Light(unsigned int LightID)
{
	return NULL;
}

_TAM_Bone_Frame * CTopAceModel::TAM_Get_Bone_Frame(unsigned int BoneFrameID,unsigned int BoneID,_TAM_Bone_Frame_Type TAM_Bone_Frame_Type)
{
	return NULL;
}
_TAM_Bone_Frame * CTopAceModel::TAM_Get_Bone_Frame(unsigned int BoneFrameID,_TAM_Bone * TAM_Bone,_TAM_Bone_Frame_Type TAM_Bone_Frame_Type)
{
	return NULL;
}
_TAM_Bone_Frame * CTopAceModel::TAM_Get_Bone_PreviousFrame(unsigned int BoneFrameID,unsigned int BoneID,_TAM_Bone_Frame_Type TAM_Bone_Frame_Type)
{
	return NULL;
}
_TAM_Bone_Frame * CTopAceModel::TAM_Get_Bone_PreviousFrame(unsigned int BoneFrameID,_TAM_Bone * TAM_Bone,_TAM_Bone_Frame_Type TAM_Bone_Frame_Type)
{
	return NULL;
}

_TAM_Light_Frame * CTopAceModel::TAM_Get_Light_Frame(unsigned int LightFrameID,unsigned int LightID,_TAM_Light_Frame_Type TAM_Light_Frame_Type)
{
	return NULL;
}
_TAM_Light_Frame * CTopAceModel::TAM_Get_Light_Frame(unsigned int LightFrameID,_TAM_Light * TAM_Light,_TAM_Light_Frame_Type TAM_Light_Frame_Type)
{
	return NULL;
}
_TAM_Light_Frame * CTopAceModel::TAM_Get_Light_PreviousFrame(unsigned int LightFrameID,unsigned int LightID,_TAM_Light_Frame_Type TAM_Light_Frame_Type)
{
	return NULL;
}
_TAM_Light_Frame * CTopAceModel::TAM_Get_Light_PreviousFrame(unsigned int LightFrameID,_TAM_Light * TAM_Light,_TAM_Light_Frame_Type TAM_Light_Frame_Type)
{
	return NULL;
}

_TAM_Bone * CTopAceModel::TAM_Get_NextBone(unsigned int BoneID)
{
	return NULL;
}
_TAM_Bone * CTopAceModel::TAM_Get_NextBone(_TAM_Bone * TAM_Bone)
{
	return NULL;
}

_TAM_Bone * CTopAceModel::TAM_Get_ChildBone(unsigned int BoneID)
{
	return NULL;
}
_TAM_Bone * CTopAceModel::TAM_Get_ChildBone(_TAM_Bone * TAM_Bone)
{
	return NULL;
}