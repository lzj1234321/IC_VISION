#pragma once


// RobotSettingsDlg �Ի���

class RobotSettingsDlg : public CDialogEx
{
	DECLARE_DYNAMIC(RobotSettingsDlg)

public:
	RobotSettingsDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~RobotSettingsDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
