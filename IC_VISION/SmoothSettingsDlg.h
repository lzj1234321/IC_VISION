#pragma once
#include "afxwin.h"


// SmoothSettingsDlg 对话框

class SmoothSettingsDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SmoothSettingsDlg)

public:
	SmoothSettingsDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~SmoothSettingsDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG7 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	virtual BOOL OnInitDialog();
	CComboBox smoothType_Combo;
};
