// CannySettingsDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "IC_VISION.h"
#include "CannySettingsDlg.h"
#include "afxdialogex.h"


// CannySettingsDlg �Ի���

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


// CannySettingsDlg ��Ϣ�������


void CannySettingsDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
	DestroyWindow();
}


void CannySettingsDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
	DestroyWindow();
}


BOOL CannySettingsDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
