// ThresholdSettingsDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "IC_VISION.h"
#include "ThresholdSettingsDlg.h"
#include "afxdialogex.h"


// ThresholdSettingsDlg 对话框

IMPLEMENT_DYNAMIC(ThresholdSettingsDlg, CDialogEx)

ThresholdSettingsDlg::ThresholdSettingsDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG4, pParent)
{

}

ThresholdSettingsDlg::~ThresholdSettingsDlg()
{
}

void ThresholdSettingsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, combo1);
}


BEGIN_MESSAGE_MAP(ThresholdSettingsDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &ThresholdSettingsDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &ThresholdSettingsDlg::OnBnClickedCancel)
	ON_WM_KILLFOCUS()
	ON_BN_CLICKED(IDC_BUTTON1, &ThresholdSettingsDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// ThresholdSettingsDlg 消息处理程序


void ThresholdSettingsDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void ThresholdSettingsDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
	DestroyWindow();
}


BOOL ThresholdSettingsDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	combo1.InsertString(0, TEXT("CV_THRESH_BINARY"));
	combo1.InsertString(1, TEXT("CV_THRESH_BINARY_INV"));
	combo1.InsertString(2, TEXT("CV_THRESH_TRUNC"));
	combo1.InsertString(3, TEXT("CV_THRESH_TOZERO"));
	combo1.InsertString(4, TEXT("CV_THRESH_TOZERO_INV"));
	combo1.SetCurSel(0);

	CEdit* max_value = (CEdit*)GetDlgItem(IDC_EDIT4);
	max_value->SetWindowText(TEXT("255"));

	CEdit* threshold = (CEdit*)GetDlgItem(IDC_EDIT2);
	threshold->SetWindowText(INT_ToCString(theApp.imgProcess->threshold));

	//ON_EN_KILLFOCUS(threshold);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


//void ThresholdSettingsDlg::OnKillFocus(CWnd* pNewWnd)
//{
//	CDialogEx::OnKillFocus(pNewWnd);
//
//	// TODO: 在此处添加消息处理程序代码
//}


void ThresholdSettingsDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
	int nIndex = combo1.GetCurSel();
	int thresholdType;
	int INT_threshold, INT_max_value;
	switch (nIndex)
	{
	case 0:
		thresholdType = CV_THRESH_BINARY;
		break;
	case 1:
		thresholdType = CV_THRESH_BINARY_INV;
		break;
	case 2:
		thresholdType = CV_THRESH_TRUNC;
		break;
	case 3:
		thresholdType = CV_THRESH_TOZERO;
		break;
	case 4:
		thresholdType = CV_THRESH_TOZERO_INV;
		break;
	default:
		break;
	}
	theApp.imgProcess->threshold_type = thresholdType;

	CEdit* pBoxOne;
	CString threshold;
	pBoxOne = (CEdit*)GetDlgItem(IDC_EDIT2);
	pBoxOne->GetWindowText(threshold);
	INT_threshold = CStringToINT(threshold);

	CEdit* pBoxTwo;
	CString max_value;
	pBoxTwo = (CEdit*)GetDlgItem(IDC_EDIT4);
	pBoxTwo->GetWindowText(max_value);
	INT_max_value = CStringToINT(max_value);

	if (INT_threshold > INT_max_value)
	{
		AfxMessageBox(TEXT("threshold cant bigger than max_value!"));
		pBoxOne->SetSel(0, -1);
		pBoxOne->SetFocus();
	}
	else
	{
		theApp.imgProcess->threshold = INT_threshold;
		theApp.imgProcess->max_value = INT_max_value;
		CDialog::EndDialog(IDD_DIALOG4);
	}
}
