#pragma once


// CameraChooseDlg �Ի���

class CameraChooseDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CameraChooseDlg)

public:
	CameraChooseDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CameraChooseDlg();
	INT ChoosedCameraNum=-1;

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnBnClickedRadio5();
};
