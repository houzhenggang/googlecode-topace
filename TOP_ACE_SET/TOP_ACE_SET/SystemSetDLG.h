#pragma once
#include "afxwin.h"


// CSystemSetDLG dialog

class CSystemSetDLG : public CDialog
{
	DECLARE_DYNAMIC(CSystemSetDLG)

public:
	CSystemSetDLG(CWnd* pParent = NULL);   // standard constructor
	virtual ~CSystemSetDLG();

// Dialog Data
	enum { IDD = IDD_DIALOG_SET_SYS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	void InitUI(void);
	CComboBox m_COMBOBOX_Resolution;
	int ResolutionSet;
	
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnCbnSelchangeCombo1();
	CEdit m_EDIT_w;
	CEdit m_EDIT_h;
	afx_msg void OnEnKillfocusEdit1();
	afx_msg void OnEnKillfocusEdit2();
	CComboBox m_COMBOBOX_ColorBit;
	void Init_COMBOBOX_Resolution(void);
	void Init_COMBOBOX_ColorBit(void);
	afx_msg void OnCbnSelchangeCombo3();
	CButton m_CHECK_SYNC;
	afx_msg void OnBnClickedCheck2();
	CComboBox m_COMBOBOX_AA;
	void Init_COMBOBOX_AA(void);
	afx_msg void OnCbnSelchangeCombo2();
	CEdit m_EDIT_FPS_Set;
	afx_msg void OnEnKillfocusEdit3();
};
