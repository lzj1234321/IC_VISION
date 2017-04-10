// SmoothSettingsDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "IC_VISION.h"
#include "SmoothSettingsDlg.h"
#include "afxdialogex.h"


// SmoothSettingsDlg 对话框

IMPLEMENT_DYNAMIC(SmoothSettingsDlg, CDialogEx)

SmoothSettingsDlg::SmoothSettingsDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG7, pParent)
{

}

SmoothSettingsDlg::~SmoothSettingsDlg()
{
}

void SmoothSettingsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, smoothType_Combo);
}


BEGIN_MESSAGE_MAP(SmoothSettingsDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &SmoothSettingsDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &SmoothSettingsDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// SmoothSettingsDlg 消息处理程序
void SmoothSettingsDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
	DestroyWindow();
}

void SmoothSettingsDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	int nIndex = smoothType_Combo.GetCurSel();
	int smoothType;
	CString param1_str, param2_str, param3_str, param4_str;
	int param1_int, param2_int;
	double param3_df, param4_df;
	switch (nIndex)
	{
	case 0:
		smoothType = CV_BLUR;
		break;
	case 1:
		smoothType = CV_MEDIAN;
		break;
	case 2:
		smoothType = CV_GAUSSIAN;
		break;
	case 3:
		smoothType = CV_BILATERAL;
		break;
	default:
		break;
	}

	CEdit* param1_edit;
	CEdit* param2_edit;
	CEdit* param3_edit;
	CEdit* param4_edit;
	param1_edit = (CEdit*)GetDlgItem(IDC_EDIT1);
	param2_edit = (CEdit*)GetDlgItem(IDC_EDIT2);
	param3_edit = (CEdit*)GetDlgItem(IDC_EDIT3);
	param4_edit = (CEdit*)GetDlgItem(IDC_EDIT4);

	param1_edit->GetWindowText(param1_str);
	param2_edit->GetWindowText(param2_str);
	param3_edit->GetWindowText(param3_str);
	param4_edit->GetWindowText(param4_str);
	param1_int = CStringToINT(param1_str);
	param2_int = CStringToINT(param2_str);
	param3_df = CStringToINT(param3_str);
	param4_df = CStringToINT(param4_str);
	
	//theApp.imgProcess->img_Smooth_Param.param1 = param1_int;
	//theApp.imgProcess->img_Smooth_Param.param2 = param2_int;
	//theApp.imgProcess->img_Smooth_Param.param3 = param3_df;
	//theApp.imgProcess->img_Smooth_Param.param4 = param4_df;
	//theApp.imgProcess->img_Smooth_Param.smooth_Type = smoothType;
	theApp.imgProcess->img_Smooth_Param->param1 = param1_int;
	theApp.imgProcess->img_Smooth_Param->param2 = param2_int;
	theApp.imgProcess->img_Smooth_Param->param3 = param3_df;
	theApp.imgProcess->img_Smooth_Param->param4 = param4_df;
	theApp.imgProcess->img_Smooth_Param->smooth_Type = smoothType;

	DestroyWindow();
}


BOOL SmoothSettingsDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	smoothType_Combo.InsertString(0, TEXT("CV_BLUR"));
	//smoothType_Combo.InsertString(1, TEXT("CV_BLUR_NO_SCALE"));
	smoothType_Combo.InsertString(1, TEXT("CV_GAUSSIAN"));
	smoothType_Combo.InsertString(2, TEXT("CV_MEDIAN"));
	smoothType_Combo.InsertString(3, TEXT("CV_BILATERAL"));
	smoothType_Combo.SetCurSel(theApp.imgProcess->img_Smooth_Param->smooth_Type-1);

	CEdit* param1_edit;
	CEdit* param2_edit;
	CEdit* param3_edit;
	CEdit* param4_edit;
	param1_edit = (CEdit*)GetDlgItem(IDC_EDIT1);
	param2_edit = (CEdit*)GetDlgItem(IDC_EDIT2);
	param3_edit = (CEdit*)GetDlgItem(IDC_EDIT3);
	param4_edit = (CEdit*)GetDlgItem(IDC_EDIT4);

	param1_edit->SetWindowText(TEXT("3"));
	param2_edit->SetWindowText(TEXT("0"));
	param3_edit->SetWindowText(TEXT("0"));
	param4_edit->SetWindowText(TEXT("0"));


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
