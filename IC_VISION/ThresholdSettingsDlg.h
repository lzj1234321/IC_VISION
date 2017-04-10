#pragma once
#include "afxwin.h"


// ThresholdSettingsDlg 对话框

class ThresholdSettingsDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ThresholdSettingsDlg)

public:
	ThresholdSettingsDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ThresholdSettingsDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	virtual BOOL OnInitDialog();
	CComboBox combo1;
//	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnBnClickedButton1();
};
