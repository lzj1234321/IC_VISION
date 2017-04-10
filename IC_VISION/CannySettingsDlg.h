#pragma once


// CannySettingsDlg 对话框

class CannySettingsDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CannySettingsDlg)

public:
	CannySettingsDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CannySettingsDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG6 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	virtual BOOL OnInitDialog();
};
