// RobotSettingsDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "IC_VISION.h"
#include "RobotSettingsDlg.h"
#include "afxdialogex.h"


// RobotSettingsDlg 对话框

IMPLEMENT_DYNAMIC(RobotSettingsDlg, CDialogEx)

RobotSettingsDlg::RobotSettingsDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

RobotSettingsDlg::~RobotSettingsDlg()
{
}

void RobotSettingsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(RobotSettingsDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &RobotSettingsDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &RobotSettingsDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// RobotSettingsDlg 消息处理程序


BOOL RobotSettingsDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CEdit* pBoxOne;
	CEdit* pBoxTwo;
	CString port;
	char Port[20] = { '\0' };
	sprintf_s(Port, "%d", theApp.robot[ROBOT1 - 1].GetRobotPort(ROBOT1));
	pBoxOne = (CEdit*)GetDlgItem(IDC_EDIT1);
	pBoxTwo = (CEdit*)GetDlgItem(IDC_IPADDRESS1);
	pBoxOne->SetWindowText(CString(Port));
	pBoxTwo->SetWindowText(theApp.robot[ROBOT1 - 1].GetRobotIP(1));
	// TODO:  在此添加额外的初始化
	//加载设置
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void RobotSettingsDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	CEdit* pBoxOne;
	CEdit* pBoxTwo;
	CString robotIP;
	CString robotPort;
	pBoxOne = (CEdit*)GetDlgItem(IDC_EDIT1);
	pBoxTwo = (CEdit*)GetDlgItem(IDC_IPADDRESS1);
	pBoxOne->GetWindowText(robotPort);
	pBoxTwo->GetWindowText(robotIP);

	char* port;
	int len = WideCharToMultiByte(CP_ACP, 0, robotPort, -1, NULL, 0, NULL, NULL);
	port = new char[len + 1];
	WideCharToMultiByte(CP_ACP, 0, robotPort, -1, port, len, NULL, NULL);

	theApp.robot[ROBOT1 - 1].SetRobotPort(ROBOT1,atoi(port));
	theApp.robot[ROBOT1 - 1].SetRobotIP(ROBOT1, robotIP);

	theApp.robot[ROBOT1 - 1].RobotSettingsSave(ROBOT1,robotIP, robotPort);
	DestroyWindow();
}

void RobotSettingsDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
	DestroyWindow();
}
