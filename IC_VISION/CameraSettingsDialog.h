#pragma once


// CameraSettingsDialog 对话框

class CameraSettingsDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CameraSettingsDialog)

public:
	CameraSettingsDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CameraSettingsDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
