// SystemSetDLG.cpp : implementation file
//

#include "stdafx.h"
#include "TOP_ACE_SET.h"
#include "SystemSetDLG.h"
#include"IniFile.h"

// CSystemSetDLG dialog

IMPLEMENT_DYNAMIC(CSystemSetDLG, CTopAceDialog)
extern tGameSet GameSet;
extern tSoundSet SoundSet;
extern tJoyStictSet JoyStictSet;

CSystemSetDLG::CSystemSetDLG(CWnd* pParent /*=NULL*/)
	: CTopAceDialog(CSystemSetDLG::IDD, pParent)
	, ResolutionSet(-1)
{

}

CSystemSetDLG::~CSystemSetDLG()
{
}

void CSystemSetDLG::DoDataExchange(CDataExchange* pDX)
{
	CTopAceDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_COMBOBOX_Resolution);
	DDX_Control(pDX, IDC_EDIT1, m_EDIT_w);
	DDX_Control(pDX, IDC_EDIT2, m_EDIT_h);
	DDX_Control(pDX, IDC_COMBO3, m_COMBOBOX_ColorBit);
	DDX_Control(pDX, IDC_CHECK2, m_CHECK_SYNC);
	DDX_Control(pDX, IDC_COMBO2, m_COMBOBOX_AA);
	DDX_Control(pDX, IDC_EDIT3, m_EDIT_FPS_Set);
	DDX_Control(pDX, IDC_CHECK_BLOOM, m_CHECK_Bloom);
	DDX_Control(pDX, IDC_STATIC_FPS, m_LTEXT_FPS);
	DDX_Control(pDX, IDC_STATIC_AA, m_LTEXT_AA);
	DDX_Control(pDX, IDC_STATIC_WIN_WARING, m_LTEXT_WIN_WARING);
	DDX_Control(pDX, IDC_STATIC_WINW, m_LTEXT_winw);
	DDX_Control(pDX, IDC_STATIC_WINH, m_LTEXT_winh);
	DDX_Control(pDX, IDC_STATIC_WIND, m_LTEXT_wind);
	DDX_Control(pDX, IDC_STATIC_Resolution, m_GROUPBOX_Resolution);
	DDX_Control(pDX, IDC_STATIC_SHADOW, m_LTEXT_SHADOW);
	DDX_Control(pDX, IDC_COMBO_SHADOW, m_COMBOBOX_SHADOW);
	DDX_Control(pDX, IDC_STATIC_LIHGT, m_LTEXT_LIGHT);
	DDX_Control(pDX, IDC_COMBO_LIGHT, m_COMBOBOX_LIGHT);
}


BEGIN_MESSAGE_MAP(CSystemSetDLG, CTopAceDialog)
	ON_BN_CLICKED(IDC_RADIO1, &CSystemSetDLG::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CSystemSetDLG::OnBnClickedRadio2)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CSystemSetDLG::OnCbnSelchangeCombo1)
	ON_EN_KILLFOCUS(IDC_EDIT1, &CSystemSetDLG::OnEnKillfocusEdit1)
	ON_EN_KILLFOCUS(IDC_EDIT2, &CSystemSetDLG::OnEnKillfocusEdit2)
	ON_CBN_SELCHANGE(IDC_COMBO3, &CSystemSetDLG::OnCbnSelchangeCombo3)
	ON_BN_CLICKED(IDC_CHECK2, &CSystemSetDLG::OnBnClickedCheck2)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CSystemSetDLG::OnCbnSelchangeCombo2)
	ON_EN_KILLFOCUS(IDC_EDIT3, &CSystemSetDLG::OnEnKillfocusEdit3)
	ON_BN_CLICKED(IDC_CHECK_BLOOM, &CSystemSetDLG::OnBnClickedCheckBloom)
	ON_CBN_SELCHANGE(IDC_COMBO_SHADOW, &CSystemSetDLG::OnCbnSelchangeComboShadow)
END_MESSAGE_MAP()


// CSystemSetDLG message handlers

void CSystemSetDLG::InitUI(void)
{
	ResolutionSet=-1;
	
	Init_COMBOBOX_Resolution();
	Init_COMBOBOX_ColorBit();
	Init_COMBOBOX_AA();
	Init_COMBOBOX_SHADOW();
	CString cSetEdit;
	cSetEdit.Format(_T("%d"),GameSet.winW);
	m_EDIT_w.SetWindowText(cSetEdit);
	cSetEdit.Empty();
	cSetEdit.Format(_T("%d"),GameSet.winH);
	m_EDIT_h.SetWindowText(cSetEdit);
	cSetEdit.Empty();
	cSetEdit.Format(_T("%d"),GameSet.FPS);
	m_EDIT_FPS_Set.SetWindowText(cSetEdit);
	((CButton *)GetDlgItem(IDC_RADIO1))->SetWindowText(_T("全屏"));
	((CButton *)GetDlgItem(IDC_RADIO2))->SetWindowText(_T("窗口"));
	m_GROUPBOX_Resolution.SetWindowText(_T("分辨率"));
	m_LTEXT_winw.SetWindowText(_T("宽"));
	m_LTEXT_winh.SetWindowText(_T("高"));
	m_LTEXT_wind.SetWindowText(_T("色深"));
	m_CHECK_SYNC.SetCheck(GameSet.SYNC);
	m_CHECK_SYNC.SetWindowText(_T("垂直同步"));
	m_LTEXT_FPS.SetWindowText(_T("FPS限制"));
	m_LTEXT_AA.SetWindowText(_T("反锯齿"));
	m_LTEXT_WIN_WARING.SetWindowText(_T("窗口模式高宽必须都是4的倍数"));
	m_LTEXT_SHADOW.SetWindowText(_T("阴影"));

	//m_EDIT_FPS_Set.SetWindowText(_T("xFPS限制"));
	m_CHECK_Bloom.SetCheck(GameSet.Bloom>0?true:false);
	if(ResolutionSet>=0)
	{
		m_COMBOBOX_Resolution.SetCurSel(ResolutionSet);
		CheckRadioButton(IDC_RADIO1,IDC_RADIO2,IDC_RADIO1);
		m_COMBOBOX_Resolution.EnableWindow(true);
		m_EDIT_w.EnableWindow(false);
		m_EDIT_h.EnableWindow(false);
		m_COMBOBOX_ColorBit.EnableWindow(false);
	}
	else
	{
		m_COMBOBOX_Resolution.SetCurSel(0);
		CheckRadioButton(IDC_RADIO1,IDC_RADIO2,IDC_RADIO2);
		OnBnClickedRadio2();
	}
	
}

void CSystemSetDLG::OnBnClickedRadio1()
{
	// TODO: Add your control notification handler code here
	GameSet.isFullScreem=true;
	m_COMBOBOX_Resolution.EnableWindow(true);
	m_EDIT_w.EnableWindow(false);
	m_EDIT_h.EnableWindow(false);
	m_COMBOBOX_ColorBit.EnableWindow(false);
	OnCbnSelchangeCombo1();
}

void CSystemSetDLG::OnBnClickedRadio2()
{
	// TODO: Add your control notification handler code here
	ResolutionSet=-1;
	GameSet.isFullScreem=false;
	m_COMBOBOX_Resolution.EnableWindow(false);
	m_EDIT_w.EnableWindow(true);
	m_EDIT_h.EnableWindow(true);
	m_COMBOBOX_ColorBit.EnableWindow(true);
	OnEnKillfocusEdit1();
	OnEnKillfocusEdit2();
}

void CSystemSetDLG::OnCbnSelchangeCombo1()
{
	// TODO: Add your control notification handler code here
	CString getResolutionSet;
	ResolutionSet=m_COMBOBOX_Resolution.GetCurSel();
	if(ResolutionSet<0)
	{
		ResolutionSet=0;
		m_COMBOBOX_Resolution.SetCurSel(0);
	}
	m_COMBOBOX_Resolution.GetLBText(ResolutionSet,getResolutionSet);
	if(getResolutionSet.IsEmpty())
		return;
	swscanf_s(getResolutionSet.GetBuffer(),_T("%d X %d %dbit"),&GameSet.winW,&GameSet.winH,&GameSet.bits);
}

void CSystemSetDLG::OnEnKillfocusEdit1()
{
	// TODO: Add your control notification handler code here
	CString getResolutionSet,setResolutionSet;
	m_EDIT_w.GetWindowTextW(getResolutionSet);
	if(getResolutionSet.IsEmpty())
		return;
	swscanf_s(getResolutionSet.GetBuffer(),_T("%d"),&GameSet.winW);
	GameSet.winW=GameSet.winW-GameSet.winW%4;
	setResolutionSet.Format(_T("%d"),GameSet.winW);
	m_EDIT_w.SetWindowText(setResolutionSet);
}

void CSystemSetDLG::OnEnKillfocusEdit2()
{
	// TODO: Add your control notification handler code here
	CString getResolutionSet,setResolutionSet;
	m_EDIT_h.GetWindowTextW(getResolutionSet);
	if(getResolutionSet.IsEmpty())
		return;
	swscanf_s(getResolutionSet.GetBuffer(),_T("%d"),&GameSet.winH);
	GameSet.winH=GameSet.winH-GameSet.winH%4;
	setResolutionSet.Format(_T("%d"),GameSet.winH);
	m_EDIT_h.SetWindowText(setResolutionSet);
}

void CSystemSetDLG::Init_COMBOBOX_Resolution(void)
{
	DEVMODE   lpDevMode;
	int iModeNum=0;
	unsigned int ResolutionPels=0;
	m_COMBOBOX_Resolution.ResetContent();
	while( EnumDisplaySettings(NULL,iModeNum,&lpDevMode))
	{
		iModeNum=iModeNum+1;
		CString cDevMode;
		if(lpDevMode.dmBitsPerPel>8)
		{
			if(ResolutionPels!=lpDevMode.dmBitsPerPel)
			{
				cDevMode.Format(_T("%d X %d %dbit"),lpDevMode.dmPelsWidth,lpDevMode.dmPelsHeight,lpDevMode.dmBitsPerPel);
				if(ResolutionPels>(lpDevMode.dmPelsWidth*lpDevMode.dmPelsHeight))
					m_COMBOBOX_Resolution.AddString(cDevMode);
				else
					m_COMBOBOX_Resolution.InsertString(0,cDevMode);
				ResolutionPels=lpDevMode.dmBitsPerPel;
			}
		}
	}
	iModeNum=0;
	if(GameSet.isFullScreem)
	for(int i=0;i<m_COMBOBOX_Resolution.GetCount();i++)
	{
		CString ctestResolutionSet1,ctestResolutionSet12;
		ctestResolutionSet1.Format(_T("%d X %d %dbit"),GameSet.winW,GameSet.winH,GameSet.bits);
		m_COMBOBOX_Resolution.GetLBText(i,ctestResolutionSet12);
		if(ctestResolutionSet12.IsEmpty())
			break;
		if(ctestResolutionSet1==ctestResolutionSet12)
		{
			ResolutionSet=i;
			break;
		}
	}
}

void CSystemSetDLG::Init_COMBOBOX_ColorBit(void)
{
	m_COMBOBOX_ColorBit.ResetContent();
	m_COMBOBOX_ColorBit.AddString(_T("32bit"));
	m_COMBOBOX_ColorBit.AddString(_T("16bit"));
	for(int i=0;i<m_COMBOBOX_ColorBit.GetCount();i++)
	{
		CString ctestColorBitSet1,ctestColorBitSet12;
		ctestColorBitSet1.Format(_T("%dbit"),GameSet.bits);
		m_COMBOBOX_ColorBit.GetLBText(i,ctestColorBitSet12);
		if(ctestColorBitSet12.IsEmpty())
			break;
		if(ctestColorBitSet1==ctestColorBitSet12)
		{
			m_COMBOBOX_ColorBit.SetCurSel(i);
			break;
		}
	}
}

void CSystemSetDLG::OnCbnSelchangeCombo3()
{
	CString getColorBitSet;
	int ColorBitSet=m_COMBOBOX_ColorBit.GetCurSel();
	if(ColorBitSet<0)
		return;
	m_COMBOBOX_ColorBit.GetLBText(ColorBitSet,getColorBitSet);
	if(getColorBitSet.IsEmpty())
		return;
	swscanf_s(getColorBitSet.GetBuffer(),_T("%dbit"),&GameSet.bits);
}

void CSystemSetDLG::OnBnClickedCheck2()
{
	if(m_CHECK_SYNC.GetCheck()>0)
		GameSet.SYNC=true;
	else
		GameSet.SYNC=false;
}

void CSystemSetDLG::Init_COMBOBOX_AA(void)
{
	m_COMBOBOX_AA.ResetContent();
	
	m_COMBOBOX_AA.AddString(_T("2X"));
	m_COMBOBOX_AA.AddString(_T("4X"));
	m_COMBOBOX_AA.AddString(_T("6X"));
	m_COMBOBOX_AA.AddString(_T("8X"));
	m_COMBOBOX_AA.InsertString(0,_T("关闭"));

	switch (GameSet.AA)
	{
	case 0:
		m_COMBOBOX_AA.SetCurSel(0);
		break;
	case 2:
		m_COMBOBOX_AA.SetCurSel(1);
		break;
	case 4:
		m_COMBOBOX_AA.SetCurSel(2);
		break;
	case 6:
		m_COMBOBOX_AA.SetCurSel(3);
		break;
	case 8:
		m_COMBOBOX_AA.SetCurSel(4);
		break;

	}

}

void CSystemSetDLG::OnCbnSelchangeCombo2()
{
	switch (m_COMBOBOX_AA.GetCurSel())
	{
	case 0:
		GameSet.AA=0;
		break;
	case 1:
		GameSet.AA=2;
		break;
	case 2:
		GameSet.AA=4;
		break;
	case 3:
		GameSet.AA=6;
		break;
	case 4:
		GameSet.AA=8;
		break;
	}
}

void CSystemSetDLG::OnEnKillfocusEdit3()
{
	CString getFPSSet;
	m_EDIT_FPS_Set.GetWindowTextW(getFPSSet);
	if(getFPSSet.IsEmpty())
		return;
	swscanf_s(getFPSSet.GetBuffer(),_T("%d"),&GameSet.FPS);
}


void CSystemSetDLG::OnBnClickedCheckBloom()
{
	GameSet.Bloom=m_CHECK_Bloom.GetCheck()>0?1:0;
}


void CSystemSetDLG::Init_COMBOBOX_SHADOW(void)
{
	m_COMBOBOX_SHADOW.ResetContent();
	m_COMBOBOX_SHADOW.AddString(_T("低"));
	m_COMBOBOX_SHADOW.AddString(_T("中"));
	m_COMBOBOX_SHADOW.AddString(_T("高"));
	m_COMBOBOX_SHADOW.InsertString(0,_T("关闭"));
	switch (GameSet.Shadow)
	{
	case 0:m_COMBOBOX_SHADOW.SetCurSel(0);break;
	case 1:m_COMBOBOX_SHADOW.SetCurSel(1);break;
	case 2:m_COMBOBOX_SHADOW.SetCurSel(2);break;
	case 3:m_COMBOBOX_SHADOW.SetCurSel(3);break;
	}
}


void CSystemSetDLG::OnCbnSelchangeComboShadow()
{
	GameSet.Shadow=max(0,m_COMBOBOX_SHADOW.GetCurSel());
}
