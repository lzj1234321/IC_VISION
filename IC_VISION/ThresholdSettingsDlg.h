#pragma once
#include "afxwin.h"


// ThresholdSettingsDlg �Ի���

class ThresholdSettingsDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ThresholdSettingsDlg)

public:
	ThresholdSettingsDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ThresholdSettingsDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	virtual BOOL OnInitDialog();
	CComboBox combo1;
//	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnBnClickedButton1();
};
