
// VISIONDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"


// VISIONDlg 对话框
class VISIONDlg : public CDialogEx
{
// 构造
public:
	VISIONDlg(CWnd* pParent = NULL);	// 标准构造函数

	//创建三个子窗口
	CameraSettingsDialog* Camera_settingsDialog;
	RobotSettingsDlg * Robot_settingsDialog;
	CameraChooseDlg* Camera_ChooseDlg;

	//创建图像处理设置窗口
	ThresholdSettingsDlg* Threshold_settingsDlg;
	CannySettingsDlg* Canny_settingsDlg;
	SmoothSettingsDlg* Smooth_settingsDlg;
	TemplateSettingsDlg* TemplateMatch_settingsDlg;

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_IC_VISION_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
private:
	CBitmapButton cameraStatusBitmap;
	CBitmapButton robotStatusBitmap;
public:
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();

	int ShowMat(cv::Mat img, HWND hWndDisplay);
	afx_msg void OnBnClickedMfcmenubutton1();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton13();
	afx_msg void OnBnClickedButton14();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton15();
	afx_msg void OnBnClickedButton16();
	CSliderCtrl imgProcessSlider;
	afx_msg void OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMReleasedcaptureSlider1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnTRBNThumbPosChangingSlider1(NMHDR *pNMHDR, LRESULT *pResult);
//	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
