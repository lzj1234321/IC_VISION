// CannySettingsDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "IC_VISION.h"
#include "CannySettingsDlg.h"
#include "afxdialogex.h"


// CannySettingsDlg 对话框

IMPLEMENT_DYNAMIC(CannySettingsDlg, CDialogEx)

CannySettingsDlg::CannySettingsDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG6, pParent)
{

}

CannySettingsDlg::~CannySettingsDlg()
{
}

void CannySettingsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CannySettingsDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CannySettingsDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CannySettingsDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CannySettingsDlg 消息处理程序


void CannySettingsDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	DestroyWindow();
}


void CannySettingsDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
	DestroyWindow();
}


BOOL CannySettingsDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
