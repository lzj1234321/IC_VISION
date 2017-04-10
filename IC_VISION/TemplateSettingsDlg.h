#pragma once
#include "afxwin.h"


// TemplateSettingsDlg 对话框

class TemplateSettingsDlg : public CDialogEx
{
	DECLARE_DYNAMIC(TemplateSettingsDlg)

public:
	TemplateSettingsDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~TemplateSettingsDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	CComboBox templateMatchMethodCombo;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
};
