// CameraChooseDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "IC_VISION.h"
#include "CameraChooseDlg.h"
#include "afxdialogex.h"


// CameraChooseDlg 对话框

IMPLEMENT_DYNAMIC(CameraChooseDlg, CDialogEx)

CameraChooseDlg::CameraChooseDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{
	ChoosedCameraNum = MAX_CONNECT_CAMERA_NUM;
}

CameraChooseDlg::~CameraChooseDlg()
{
}

void CameraChooseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CameraChooseDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CameraChooseDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CameraChooseDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_RADIO1, &CameraChooseDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CameraChooseDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CameraChooseDlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &CameraChooseDlg::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_RADIO5, &CameraChooseDlg::OnBnClickedRadio5)
END_MESSAGE_MAP()


// CameraChooseDlg 消息处理程序


void CameraChooseDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	CString choosedCamerSerialNum=TEXT("N/A");
	if (ChoosedCameraNum < 5&&ChoosedCameraNum>-1)
	{
		CEdit** SerialNum_Edit = new CEdit*[5];
		SerialNum_Edit[0] = (CEdit*)GetDlgItem(IDC_EDIT1);
		SerialNum_Edit[1] = (CEdit*)GetDlgItem(IDC_EDIT2);
		SerialNum_Edit[2] = (CEdit*)GetDlgItem(IDC_EDIT3);
		SerialNum_Edit[3] = (CEdit*)GetDlgItem(IDC_EDIT4);
		SerialNum_Edit[4] = (CEdit*)GetDlgItem(IDC_EDIT5);
		theApp.choosedCameraNum = ChoosedCameraNum;
		SerialNum_Edit[ChoosedCameraNum]->GetWindowText(choosedCamerSerialNum);
		theApp.pyloncamer->ChangeCurrentUsedCamera(CAM1, choosedCamerSerialNum);
		CTlFactory& tlFactory = CTlFactory::GetInstance();
		CDeviceInfo cameraInfo;
		cameraInfo.SetSerialNumber((String_t)choosedCamerSerialNum);
		Global_GigeCameraArray[CAM1-1].DetachDevice();
		Global_GigeCameraArray[CAM1-1].Attach(tlFactory.CreateDevice(cameraInfo));
		Global_CameraConnect_Statu[CAM1 - 1] = TRUE;
	}
	DestroyWindow();
}


BOOL CameraChooseDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CDialogEx::OnInitDialog();
	ChoosedCameraNum = -1;
	// TODO:  在此添加额外的初始化
	CEdit* staticText;
	CEdit** IP_Edit = new CEdit*[10];
	CEdit** SerialNum_Edit = new CEdit*[5];
	CButton** cameraChoose_Edit = new CButton*[5];
	SerialNum_Edit[0] = (CEdit*)GetDlgItem(IDC_EDIT1);
	SerialNum_Edit[1] = (CEdit*)GetDlgItem(IDC_EDIT2);
	SerialNum_Edit[2] = (CEdit*)GetDlgItem(IDC_EDIT3);
	SerialNum_Edit[3] = (CEdit*)GetDlgItem(IDC_EDIT4);
	SerialNum_Edit[4] = (CEdit*)GetDlgItem(IDC_EDIT5);

	if (true)
	{

		IP_Edit[0] = (CEdit*)GetDlgItem(IDC_IPADDRESS1);
		IP_Edit[1] = (CEdit*)GetDlgItem(IDC_IPADDRESS3);
		IP_Edit[2] = (CEdit*)GetDlgItem(IDC_IPADDRESS5);
		IP_Edit[3] = (CEdit*)GetDlgItem(IDC_IPADDRESS7);
		IP_Edit[4] = (CEdit*)GetDlgItem(IDC_IPADDRESS9);
		IP_Edit[5] = (CEdit*)GetDlgItem(IDC_IPADDRESS2);
		IP_Edit[6] = (CEdit*)GetDlgItem(IDC_IPADDRESS4);
		IP_Edit[7] = (CEdit*)GetDlgItem(IDC_IPADDRESS6);
		IP_Edit[8] = (CEdit*)GetDlgItem(IDC_IPADDRESS8);
		IP_Edit[9] = (CEdit*)GetDlgItem(IDC_IPADDRESS10);
	}

	cameraChoose_Edit[0] = (CButton*)GetDlgItem(IDC_RADIO1);
	cameraChoose_Edit[1] = (CButton*)GetDlgItem(IDC_RADIO2);
	cameraChoose_Edit[2] = (CButton*)GetDlgItem(IDC_RADIO3);
	cameraChoose_Edit[3] = (CButton*)GetDlgItem(IDC_RADIO4);
	cameraChoose_Edit[4] = (CButton*)GetDlgItem(IDC_RADIO5);
	staticText = (CEdit*)GetDlgItem(IDC_STATIC);

	switch (theApp.detectedCameraNum)
	{
	case 0:
	{
		for (int i = 0; i < 5; i++)
			cameraChoose_Edit[i]->ShowWindow(FALSE);
		staticText->ShowWindow(TRUE);
	}
	break;
	case 1:
	{
		cameraChoose_Edit[0]->EnableWindow(TRUE);
		cameraChoose_Edit[1]->EnableWindow(FALSE);
		cameraChoose_Edit[2]->EnableWindow(FALSE);
		cameraChoose_Edit[3]->EnableWindow(FALSE);
		cameraChoose_Edit[4]->EnableWindow(FALSE);
		staticText->ShowWindow(FALSE);
	}
	break;
	case 2:
	{
		cameraChoose_Edit[0]->EnableWindow(TRUE);
		cameraChoose_Edit[1]->EnableWindow(TRUE);
		cameraChoose_Edit[2]->EnableWindow(FALSE);
		cameraChoose_Edit[3]->EnableWindow(FALSE);
		cameraChoose_Edit[4]->EnableWindow(FALSE);
		staticText->ShowWindow(FALSE);
	}
	break;
	case 3:
	{
		cameraChoose_Edit[0]->EnableWindow(TRUE);
		cameraChoose_Edit[1]->EnableWindow(TRUE);
		cameraChoose_Edit[2]->EnableWindow(TRUE);
		cameraChoose_Edit[3]->EnableWindow(FALSE);
		cameraChoose_Edit[4]->EnableWindow(FALSE);
		staticText->ShowWindow(FALSE);
	}
	break;
	case 4:
	{
		cameraChoose_Edit[0]->EnableWindow(TRUE);
		cameraChoose_Edit[1]->EnableWindow(TRUE);
		cameraChoose_Edit[2]->EnableWindow(TRUE);
		cameraChoose_Edit[3]->EnableWindow(TRUE);
		cameraChoose_Edit[4]->EnableWindow(FALSE);
		staticText->ShowWindow(FALSE);
	}
	break;
	case 5:
	{
		for (int i = 0; i < 5; i++)
			cameraChoose_Edit[i]->EnableWindow(TRUE);
		staticText->ShowWindow(FALSE);
	}
	break;
	}

	for (int i = 0; i < theApp.detectedCameraNum; i++)
	{
		IP_Edit[i]->SetWindowText((CString)theApp.Detected_GIGE_CamerInfo[i].GetIpAddress());
	}
	for (int i = 0, j = 5; i < theApp.detectedCameraNum; i++, j++)
	{
		IP_Edit[j]->SetWindowText((CString)theApp.Detected_GIGE_CamerInfo[i].GetSubnetMask());
	}
	for (int i = 0; i < theApp.detectedCameraNum; i++)
	{
		SerialNum_Edit[i]->SetWindowText((CString)theApp.Detected_GIGE_CamerInfo[i].GetSerialNumber());
		if ((CString)theApp.Detected_GIGE_CamerInfo[i].GetSerialNumber() == theApp.pyloncamer->GetCameraSerialNum(CAM1)&&Global_CameraConnect_Statu[i]==TRUE)
			cameraChoose_Edit[i]->SetCheck(1);
	}
	return TRUE;
	// return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CameraChooseDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
	DestroyWindow();
}


void CameraChooseDlg::OnBnClickedRadio1()
{
	// TODO: 在此添加控件通知处理程序代码
	ChoosedCameraNum = 0;
}


void CameraChooseDlg::OnBnClickedRadio2()
{
	// TODO: 在此添加控件通知处理程序代码
	ChoosedCameraNum = 1;
}


void CameraChooseDlg::OnBnClickedRadio3()
{
	// TODO: 在此添加控件通知处理程序代码
	ChoosedCameraNum = 2;
}


void CameraChooseDlg::OnBnClickedRadio4()
{
	// TODO: 在此添加控件通知处理程序代码
	ChoosedCameraNum = 3;
}


void CameraChooseDlg::OnBnClickedRadio5()
{
	// TODO: 在此添加控件通知处理程序代码
	ChoosedCameraNum = 4;
}
