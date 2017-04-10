// RobotSettingsDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "IC_VISION.h"
#include "RobotSettingsDlg.h"
#include "afxdialogex.h"


// RobotSettingsDlg �Ի���

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


// RobotSettingsDlg ��Ϣ�������


BOOL RobotSettingsDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CEdit* pBoxOne;
	CEdit* pBoxTwo;
	CString port;
	char Port[20] = { '\0' };
	sprintf_s(Port, "%d", theApp.robot[ROBOT1 - 1].GetRobotPort(ROBOT1));
	pBoxOne = (CEdit*)GetDlgItem(IDC_EDIT1);
	pBoxTwo = (CEdit*)GetDlgItem(IDC_IPADDRESS1);
	pBoxOne->SetWindowText(CString(Port));
	pBoxTwo->SetWindowText(theApp.robot[ROBOT1 - 1].GetRobotIP(1));
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//��������
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void RobotSettingsDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
	DestroyWindow();
}
