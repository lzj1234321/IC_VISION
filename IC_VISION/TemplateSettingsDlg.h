#pragma once
#include "afxwin.h"


// TemplateSettingsDlg �Ի���

class TemplateSettingsDlg : public CDialogEx
{
	DECLARE_DYNAMIC(TemplateSettingsDlg)

public:
	TemplateSettingsDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~TemplateSettingsDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	CComboBox templateMatchMethodCombo;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
};
