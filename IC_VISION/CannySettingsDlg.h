#pragma once


// CannySettingsDlg �Ի���

class CannySettingsDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CannySettingsDlg)

public:
	CannySettingsDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CannySettingsDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG6 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	virtual BOOL OnInitDialog();
};
