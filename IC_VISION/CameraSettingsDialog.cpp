// CameraSettingsDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "IC_VISION.h"
#include "CameraSettingsDialog.h"
#include "afxdialogex.h"


// CameraSettingsDialog �Ի���

IMPLEMENT_DYNAMIC(CameraSettingsDialog, CDialogEx)

CameraSettingsDialog::CameraSettingsDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CameraSettingsDialog::~CameraSettingsDialog()
{
}

void CameraSettingsDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CameraSettingsDialog, CDialogEx)
	ON_BN_CLICKED(IDOK, &CameraSettingsDialog::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CameraSettingsDialog::OnBnClickedCancel)
END_MESSAGE_MAP()


// CameraSettingsDialog ��Ϣ�������


BOOL CameraSettingsDialog::OnInitDialog()
{
	CEdit* pBoxOne;
	CEdit* pBoxTwo;
	CEdit* pBoxThree;
	CButton* pBoxFour;
	CButton* pBoxFive;
	pBoxOne = (CEdit*)GetDlgItem(IDC_EDIT1);
	pBoxTwo = (CEdit*)GetDlgItem(IDC_IPADDRESS1);
	pBoxThree= (CEdit*)GetDlgItem(IDC_IPADDRESS2);
	pBoxFour = (CButton*)GetDlgItem(IDC_CHECK2);
	pBoxFive = (CButton*)GetDlgItem(IDC_CHECK3);
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	pBoxOne->SetWindowText(theApp.pyloncamer->GetCameraSerialNum(CAM1));
	pBoxTwo->SetWindowText(theApp.pyloncamer->GetCameraIP(CAM1));
	pBoxThree->SetWindowText(theApp.pyloncamer->GetCameraSubMask(CAM1));
	if (Global_Camera_Run_Record_Save[CAM1])
		pBoxFour->SetCheck(BST_CHECKED);
	if (Global_UnRecognizeImage_Save[CAM1])
		pBoxFive->SetCheck(BST_CHECKED);
	//��������
	return TRUE;  
	// return TRUE unless you set the focus to a control
    // �쳣: OCX ����ҳӦ���� FALSE
}


void CameraSettingsDialog::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CEdit* pBoxOne;
	CEdit* pBoxTwo;
	CEdit* pBoxThree;
	CButton* pBoxFour;
	CButton* pBoxFive;

	CString camerIP;
	CString camerSubMask;
	CString camerSerialNum;

	pBoxOne = (CEdit*)GetDlgItem(IDC_EDIT1);
	pBoxTwo = (CEdit*)GetDlgItem(IDC_IPADDRESS1);
	pBoxThree = (CEdit*)GetDlgItem(IDC_IPADDRESS2);
	pBoxFour = (CButton*)GetDlgItem(IDC_CHECK2);
	pBoxFive = (CButton*)GetDlgItem(IDC_CHECK3);

	pBoxOne->GetWindowText(camerSerialNum);
	pBoxTwo->GetWindowText(camerIP);
	pBoxThree->GetWindowText(camerSubMask);

	theApp.pyloncamer->cameraSettingsChange(CAM1, camerSerialNum, camerIP, camerSubMask);

	if (pBoxFour->GetCheck() == BST_CHECKED)
		Global_Camera_Run_Record_Save[CAM1] = true;
	else
		Global_Camera_Run_Record_Save[CAM1] = false;

	if (pBoxFive->GetCheck() == BST_CHECKED)
		Global_UnRecognizeImage_Save[CAM1] = true;
	else
		Global_UnRecognizeImage_Save[CAM1] = false;

	theApp.pyloncamer->CameraSettingsSave(CAM1, camerSerialNum, camerIP, camerSubMask, Global_Camera_Run_Record_Save[CAM1], Global_UnRecognizeImage_Save[CAM1]);
	CDialogEx::OnOK();
	DestroyWindow();
}


void CameraSettingsDialog::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
	DestroyWindow();
}
