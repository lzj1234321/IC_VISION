#pragma once


// CameraSettingsDialog �Ի���

class CameraSettingsDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CameraSettingsDialog)

public:
	CameraSettingsDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CameraSettingsDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
