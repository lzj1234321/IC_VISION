#pragma once
#include "afxwin.h"


// SmoothSettingsDlg �Ի���

class SmoothSettingsDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SmoothSettingsDlg)

public:
	SmoothSettingsDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~SmoothSettingsDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG7 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	virtual BOOL OnInitDialog();
	CComboBox smoothType_Combo;
};
