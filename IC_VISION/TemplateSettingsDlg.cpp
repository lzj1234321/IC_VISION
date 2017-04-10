// TemplateSettingsDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "IC_VISION.h"
#include "TemplateSettingsDlg.h"
#include "afxdialogex.h"


// TemplateSettingsDlg �Ի���

IMPLEMENT_DYNAMIC(TemplateSettingsDlg, CDialogEx)

TemplateSettingsDlg::TemplateSettingsDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG5, pParent)
{

}

TemplateSettingsDlg::~TemplateSettingsDlg()
{
}

void TemplateSettingsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, templateMatchMethodCombo);
}


BEGIN_MESSAGE_MAP(TemplateSettingsDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &TemplateSettingsDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &TemplateSettingsDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON1, &TemplateSettingsDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// TemplateSettingsDlg ��Ϣ�������


void TemplateSettingsDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();


	templateMatchMethodCombo.InsertString(0, TEXT("CV_TM_SQDIFF"));
	templateMatchMethodCombo.InsertString(1, TEXT("CV_TM_SQDIFF_NORMED"));
	templateMatchMethodCombo.InsertString(2, TEXT("CV_TM_CCORR"));
	templateMatchMethodCombo.InsertString(3, TEXT("CV_TM_CCORR_NORMED"));
	templateMatchMethodCombo.InsertString(4, TEXT("CV_TM_CCOEFF"));
	templateMatchMethodCombo.InsertString(5, TEXT("CV_TM_CCOEFF_NORMED"));



	int nIndex = templateMatchMethodCombo.GetCurSel();
	int templateMatchMethod=0;
	int INT_threshold, INT_max_value;
	switch (nIndex)
	{
	case 0:
		templateMatchMethod = CV_TM_SQDIFF;
		break;
	case 1:
		templateMatchMethod = CV_TM_SQDIFF_NORMED;
		break;
	case 2:
		templateMatchMethod = CV_TM_CCORR;
		break;
	case 3:
		templateMatchMethod = CV_TM_CCORR_NORMED;
		break;
	case 4:
		templateMatchMethod = CV_TM_CCOEFF;
		break;
	case 5:
		templateMatchMethod = CV_TM_CCOEFF_NORMED;
		break;
		break;
	default:
		break;
	}
	theApp.imgProcess->img_TemplateMatch_Param->templateMatchMethod = templateMatchMethod;
	DestroyWindow();
}


void TemplateSettingsDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
	DestroyWindow();
}


BOOL TemplateSettingsDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	templateMatchMethodCombo.InsertString(0, TEXT("CV_TM_SQDIFF"));
	templateMatchMethodCombo.InsertString(1, TEXT("CV_TM_SQDIFF_NORMED"));
	templateMatchMethodCombo.InsertString(2, TEXT("CV_TM_CCORR"));
	templateMatchMethodCombo.InsertString(3, TEXT("CV_TM_CCORR_NORMED"));
	templateMatchMethodCombo.InsertString(4, TEXT("CV_TM_CCOEFF"));
	templateMatchMethodCombo.InsertString(5, TEXT("CV_TM_CCOEFF_NORMED"));
	templateMatchMethodCombo.SetCurSel(theApp.imgProcess->img_TemplateMatch_Param->templateMatchMethod - 1);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void TemplateSettingsDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	cvNamedWindow("test");
	Mat test = imread("C:/Users/ONLY/Desktop/����PIC/1.bmp");
	imshow("test", test);
	cvWaitKey(0);
}
