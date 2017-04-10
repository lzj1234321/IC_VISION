#pragma once


// RobotSettingsDlg 对话框

class RobotSettingsDlg : public CDialogEx
{
	DECLARE_DYNAMIC(RobotSettingsDlg)

public:
	RobotSettingsDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~RobotSettingsDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
