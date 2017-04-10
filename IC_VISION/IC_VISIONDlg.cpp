
// VISIONDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "IC_VISION.h"
#include "IC_VISIONDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnClose();
	//	afx_msg void OnCancelMode();
	afx_msg void OnBnClickedOk();
	afx_msg void OnIdcancel();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_WM_CLOSE()
	ON_WM_CANCELMODE()
	ON_BN_CLICKED(IDOK, &CAboutDlg::OnBnClickedOk)
	ON_COMMAND(IDCANCEL, &CAboutDlg::OnIdcancel)
END_MESSAGE_MAP()


// VISIONDlg �Ի���



VISIONDlg::VISIONDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_IC_VISION_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void VISIONDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER1, imgProcessSlider);
}

BEGIN_MESSAGE_MAP(VISIONDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &VISIONDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &VISIONDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &VISIONDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON6, &VISIONDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &VISIONDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &VISIONDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &VISIONDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON11, &VISIONDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &VISIONDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &VISIONDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &VISIONDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON10, &VISIONDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON15, &VISIONDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON16, &VISIONDlg::OnBnClickedButton16)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &VISIONDlg::OnNMCustomdrawSlider1)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER1, &VISIONDlg::OnNMReleasedcaptureSlider1)
	ON_NOTIFY(TRBN_THUMBPOSCHANGING, IDC_SLIDER1, &VISIONDlg::OnTRBNThumbPosChangingSlider1)
//	ON_WM_KEYDOWN()
END_MESSAGE_MAP()


// VISIONDlg ��Ϣ�������

BOOL VISIONDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	//picture�ؼ����ͼƬ��ʾ
	namedWindow("view", WINDOW_AUTOSIZE);
	char TrackbarName[50];
	int min = 0;
	int max = 255;


	BEENCHOOSED_ELEMENTNUM = -1;

	HWND hWnd = (HWND)cvGetWindowHandle("view");
	HWND hParent = ::GetParent(hWnd);
	::SetParent(hWnd, GetDlgItem(IDC_PIC)->m_hWnd);
	::ShowWindow(hParent, SW_HIDE);

	//�������ô���
	Camera_settingsDialog = new CameraSettingsDialog(this);
	Robot_settingsDialog = new RobotSettingsDlg(this);
	Camera_ChooseDlg = new CameraChooseDlg(this);

	//����ͼ�������ô���
	Threshold_settingsDlg = new ThresholdSettingsDlg(this);
	Canny_settingsDlg = new CannySettingsDlg(this);
	Smooth_settingsDlg = new SmoothSettingsDlg(this);
	TemplateMatch_settingsDlg = new TemplateSettingsDlg(this);

	//����������
	theApp.robot = new Robot[MAX_CONNECT_ROBOT_NUM];

	//��ʼ����������ʾͼ���СΪ0
	for (int i = 0; i < 5; i++)
	{
		Global_ShowImageSize[i].height = 0;
		Global_ShowImageSize[i].width = 0;
	}

	//��ʼ�����,����������״̬Ϊfalse
	for (int i = 0; i < MAX_CONNECT_CAMERA_NUM; i++)
		Global_CameraConnect_Statu[i] = FALSE;
	for (int i = 0; i < MAX_CONNECT_ROBOT_NUM; i++)
		Global_RobotConnect_Statu[i] = FALSE;

	//���س�ʼ��״ָ̬ʾλͼ
	cameraStatusBitmap.LoadBitmaps(IDB_BITMAP6);
	cameraStatusBitmap.SubclassDlgItem(IDC_BUTTON3, this);
	cameraStatusBitmap.SizeToContent();
	robotStatusBitmap.LoadBitmaps(IDB_BITMAP6);
	robotStatusBitmap.SubclassDlgItem(IDC_BUTTON5, this);
	robotStatusBitmap.SizeToContent();

	//����PYLON���
	theApp.pyloncamer = new Pylon_Camera();
	CameraBase* testCamera = new Pylon_Camera();
	//����robot��Ϣ
	for (int i = 0; i < MAX_CONNECT_ROBOT_NUM; i++)
		theApp.robot[ROBOT1 - 1].robotINI_Load(i);

	//�������������
	DeviceInfoList_t CamerasInfoList;
	CTlFactory& Intialize_DetectedCamera_Factory = CTlFactory::GetInstance();
	theApp.detectedCameraNum = Intialize_DetectedCamera_Factory.EnumerateDevices(CamerasInfoList);
	theApp.Detected_GIGE_CamerInfo = new CBaslerGigEDeviceInfo[theApp.detectedCameraNum];
	CBaslerGigEInstantCamera *gigeCamera = new CBaslerGigEInstantCamera[theApp.detectedCameraNum];
	for (size_t i = 0; i < theApp.detectedCameraNum; ++i)
	{
		gigeCamera[i].Attach(Intialize_DetectedCamera_Factory.CreateDevice(CamerasInfoList[i]));
		theApp.Detected_GIGE_CamerInfo[i] = gigeCamera[i].GetDeviceInfo();
	}


	//����INI�����Ϣ�������������������Ϣ�����ж��Ƿ���Դ���
	CTlFactory& tlFactory = CTlFactory::GetInstance();
	CDeviceInfo cameraInfo;
	for (int i = 0; i < MAX_CONNECT_CAMERA_NUM; i++)
	{
		cameraInfo.SetSerialNumber((String_t)theApp.pyloncamer->GetCameraSerialNum(i + 1));
		for (int i = 0; i < theApp.detectedCameraNum; i++)
		{
			if (cameraInfo.GetSerialNumber() == theApp.Detected_GIGE_CamerInfo[i].GetSerialNumber())
			{
				Global_GigeCameraArray[i].Attach(tlFactory.CreateDevice(cameraInfo));
				Global_CameraConnect_Statu[i] = TRUE;
			}
		}
	}
	if (!Global_CameraConnect_Statu[0])
	{
		cameraStatusBitmap.LoadBitmaps(IDB_BITMAP2);
		cameraStatusBitmap.Invalidate();
	}
	//��ʼ�������Ӧ��ϵ
	for (int i = 0; i < MAX_CONNECT_CAMERA_NUM; i++)
	{
		Globa_Camera_Choose[i] = i + 1;
	}

	Global_Camera_Run_Record_Save[CAM1] = theApp.pyloncamer->GetCameraSaveRunRecord(CAM1);
	Global_UnRecognizeImage_Save[CAM1] = theApp.pyloncamer->GetCameraSaveUnRecognizerImage(CAM1);

	//��ȡ��ʾͼ��PIC�ؼ�SIZE
	CRect rect;
	CWnd* pWnd = GetDlgItem(IDC_PIC);//IDC_pictureΪpicture�ؼ�ID
	pWnd->GetClientRect(&rect);//rcΪ�ؼ��Ĵ�С��
	int x = rect.Height();
	int y = rect.Width();
	theApp.PIC_SIZE = Size(y, x);

	//��ʼ����ʾ����
	Global_PIC_Size_ShowMat = Mat(theApp.PIC_SIZE, CV_8UC3, Scalar(255, 0, 0));
	Global_PIC_intializeMat = Mat(theApp.PIC_SIZE, CV_8UC3, Scalar(255, 0, 0));

	//��ʼ��PIC_CONTROL��ʾ�ؼ�
	//theApp.intializePIC_Mat = Mat(theApp.PIC_SIZE, CV_8UC3, Scalar(255, 0, 0));
	//imshow("view", Global_PIC_intializeMat);
	imgDraw.originalMat = Global_PIC_Size_ShowMat;

	//������ʾ��������¼�
	theApp.currentShowMat = new Mat(theApp.PIC_SIZE, CV_8U);
	cvSetMouseCallback("view", ImageMouseClickEvent, &Global_PIC_Size_ShowMat);
	imshow("view", Global_PIC_Size_ShowMat);
	theApp.imgProcess = new Img_Process;

	//����slider����
	imgProcessSlider.SetRange(0, 20); 
	imgProcessSlider.SetTicFreq(300);   // ÿ10����λ��һ�̶�.  
	//imgProcessSlider.SetPos(1000);      // ����Ĭ�ϵ������ʱ��Ϊ1��.

	imgX = (CEdit*)GetDlgItem(IDC_EDIT2);
	imgY = (CEdit*)GetDlgItem(IDC_EDIT3);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void VISIONDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}


// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void VISIONDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
		CDialog::UpdateWindow();
		//ShowImage(TheImage, IDC_PIC);

	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR VISIONDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void VISIONDlg::OnBnClickedButton1()
{
	cameraStatusBitmap.LoadBitmaps(IDB_BITMAP4);
	cameraStatusBitmap.Invalidate();
	//if (theApp.choosedCameraNum < 5)
	if (Global_CameraConnect_Statu[0])
	{
		//if (theApp.pyloncamer->snapImage(CAM1))
		if (theApp.pyloncamer->SnapImage(CAM1))
		{
			cameraStatusBitmap.LoadBitmaps(IDB_BITMAP3);
			cameraStatusBitmap.Invalidate();
			CRect rect;
			CWnd* pWnd = GetDlgItem(IDC_PIC);//IDC_pictureΪpicture�ؼ�ID
			pWnd->GetClientRect(&rect);//rcΪ�ؼ��Ĵ�С��
			int x = rect.Height();
			int y = rect.Width();
			Size dsize = Size(y, x);

			resize(theApp.pyloncamer->GetGrabImageMat(CAM1), Global_PIC_Size_ShowMat, theApp.PIC_SIZE);
			imshow("view", Global_PIC_Size_ShowMat);
			Global_ShowImageSize->width = theApp.pyloncamer->GetGrabImageMat(CAM1).cols;
			Global_ShowImageSize->height = theApp.pyloncamer->GetGrabImageMat(CAM1).rows;

			//Mat imageShow = Mat(dsize, CV_8U);
			//resize(theApp.pyloncamer->GetGrabImageMat(CAM1), imageShow, dsize);

			//imshow("view", imageShow);
			CEdit* t1 = (CEdit*)GetDlgItem(IDC_EDIT1);
			CEdit* t2 = (CEdit*)GetDlgItem(IDC_EDIT2);
			CEdit* t3 = (CEdit*)GetDlgItem(IDC_EDIT3);
			CEdit* t4 = (CEdit*)GetDlgItem(IDC_EDIT4);
			//CEdit* t5 = (CEdit*)GetDlgItem(IDC_EDIT5);
			CString width;
			CString height;
			CString pixFormat;
			CString bufferSize;
			//CString exposeTime;
			width.Format(_T("%d"), theApp.pyloncamer->imageFormatPtr[CAM1 - 1].width);
			height.Format(_T("%d"), theApp.pyloncamer->imageFormatPtr[CAM1 - 1].height);
			pixFormat.Format(_T("%d"), theApp.pyloncamer->imageFormatPtr[CAM1 - 1].pixFormat);
			bufferSize.Format(_T("%d"), theApp.pyloncamer->imageFormatPtr[CAM1 - 1].bufferSize);
			//exposeTime.Format(_T("%d"), theApp.pyloncamer->imageFormatPtr[CAM1 - 1].exposeTime);
			if (theApp.pyloncamer->imageFormatPtr->pixFormat == PixelType_Mono8)
				t1->SetWindowText(TEXT("PixelType_Mono8"));
			else
				t1->SetWindowText(TEXT("not mono8"));
			t2->SetWindowText(width);
			t3->SetWindowText(height);
			t4->SetWindowText(bufferSize);
			//t5->SetWindowText(exposeTime);
		}
	}
	else
	{
		cameraStatusBitmap.LoadBitmaps(IDB_BITMAP2);
		cameraStatusBitmap.Invalidate();
		AfxMessageBox(TEXT("Please choose a camera!"));
	}
}


void VISIONDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	BOOL isOpen = TRUE;     //�Ƿ��(����Ϊ����)  
	CString defaultDir;   //Ĭ�ϴ򿪵��ļ�·��  
	CString fileName = L"";         //Ĭ�ϴ򿪵��ļ���  
	CString filter = L"�ļ� (*.bmp; *.jpeg)|*.bmp;*.jpeg||";   //�ļ����ǵ�����  
	CFileDialog openFileDlg(isOpen, defaultDir, fileName, OFN_HIDEREADONLY | OFN_READONLY, filter, NULL);
	INT_PTR result = openFileDlg.DoModal();
	CString filePath;
	if (result == IDOK) {
		filePath = openFileDlg.GetPathName();
		char* picSrc;
		int len = WideCharToMultiByte(CP_ACP, 0, filePath, -1, NULL, 0, NULL, NULL);
		picSrc = new char[len + 1];
		WideCharToMultiByte(CP_ACP, 0, filePath, -1, picSrc, len, NULL, NULL);
		//new
		Global_PIC_Original_Mat = imread(picSrc);
		Global_PIC_Show_Mat = imread(picSrc);
		//new
		Global_ShowImageSize[CAM1 - 1].width = Global_PIC_Show_Mat.cols;
		Global_ShowImageSize[CAM1 - 1].height = Global_PIC_Show_Mat.rows;


		resize(Global_PIC_Show_Mat, Global_PIC_Size_ShowMat, theApp.PIC_SIZE);
		imshow("view", Global_PIC_Size_ShowMat);


		CEdit* t1 = (CEdit*)GetDlgItem(IDC_EDIT1);
		CEdit* t2 = (CEdit*)GetDlgItem(IDC_EDIT2);
		CEdit* t3 = (CEdit*)GetDlgItem(IDC_EDIT3);
		CEdit* t4 = (CEdit*)GetDlgItem(IDC_EDIT4);
		CButton* b1 = (CButton*)GetDlgItem(IDC_BUTTON16);

		CString width_str;
		CString height_str;
		CString pixFormat_str;
		CString bufferSize_str;

		INT img_size;
		INT width_int;
		INT height_int;
		INT img_channels;
		INT img_depth;
		//CString exposeTime;
		//width_int = theApp.pyloncamer->GetGrabImageMat(CAM1).cols;

		width_int = Global_PIC_Show_Mat.cols;
		height_int = Global_PIC_Show_Mat.rows;
		img_channels = Global_PIC_Show_Mat.channels();
		img_depth = Global_PIC_Show_Mat.depth();

		img_size = width_int*height_int;

		width_str.Format(_T("%d"), width_int);
		height_str.Format(_T("%d"), height_int);
		//pixFormat_str.Format(_T("%d"), theApp.pyloncamer->showImageMat[CAM1].channels);
		bufferSize_str.Format(_T("%d"), img_size);
		//exposeTime.Format(_T("%d"), theApp.pyloncamer->imageFormatPtr[CAM1 - 1].exposeTime);
		if (img_channels == 3)
			t1->SetWindowText(TEXT("gray8"));
		else
			t1->SetWindowText(TEXT("not gray8"));
		t2->SetWindowText(width_str);
		t3->SetWindowText(height_str);
		t4->SetWindowText(bufferSize_str);
		//t5->SetWindowText(exposeTime);
		b1->EnableWindow(true);
		delete[] picSrc;
	}
}


void VISIONDlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Camera_settingsDialog->DoModal();
	//Camera_settingsDialog->Create(IDD_DIALOG1, this);
}


void VISIONDlg::OnBnClickedButton6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (theApp.pyloncamer->IsGrabSucced(CAM1))
	{
		imwrite("C:\\Users\\ONLY\\Desktop\\saveTest.bmp", theApp.pyloncamer->GetGrabImageMat(CAM1));
	}
	else
	{
		AfxMessageBox(TEXT("save failed!"));
	}
}


void VISIONDlg::OnBnClickedButton7()
{

	DeviceInfoList_t CamerasInfoList;
	static const size_t c_maxCamerasToUse = MAX_CONNECT_CAMERA_NUM;
	CTlFactory& tlFactory = CTlFactory::GetInstance();
	theApp.detectedCameraNum = tlFactory.EnumerateDevices(CamerasInfoList);
	theApp.Detected_GIGE_CamerInfo = new CBaslerGigEDeviceInfo[theApp.detectedCameraNum];
	if (theApp.detectedCameraNum == 0)
	{
		//throw PylonCamera_Exception(UnDetectedCamera);
		//Camera_ChooseDlg->Create(IDD_DIALOG3, this);
		Camera_ChooseDlg->DoModal();
	}
	else if (theApp.detectedCameraNum > 5)
	{
		CInstantCameraArray cameras(min(theApp.CamerasInfoList.size(), c_maxCamerasToUse));
		AfxMessageBox(TEXT("TOOMUCH CAMERA DETECTED!"));
		//throw PylonCamera_Exception(CamerNumOverThrow);
		Camera_ChooseDlg->Create(IDD_DIALOG3, this);
	}
	else
	{
		CBaslerGigEInstantCamera *gigeCamera = new CBaslerGigEInstantCamera[theApp.detectedCameraNum];
		for (size_t i = 0; i < theApp.detectedCameraNum; ++i)
		{
			gigeCamera[i].Attach(tlFactory.CreateDevice(CamerasInfoList[i]));
			//if (gigeCamera[i].IsGigE())
			theApp.Detected_GIGE_CamerInfo[i] = gigeCamera[i].GetDeviceInfo();
			//theApp.Detected_GIGE_CamerInfo[i] = Global_GigeCameraArray[i].GetDeviceInfo();
		}
		Camera_ChooseDlg->Create(IDD_DIALOG3, this);
	}
}


BOOL CAboutDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void VISIONDlg::OnBnClickedButton8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//Robot_settingsDialog->Create(IDD_DIALOG2, this);
	Robot_settingsDialog->DoModal();
}


void VISIONDlg::OnBnClickedButton9()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString ip;
	int port = 8888;
	CString MSG = TEXT("asdsda");
	if (theApp.robot[ROBOT1 - 1].Socket_Create())
	{
		Sleep(500);
	}
	else
	{
		robotStatusBitmap.LoadBitmaps(IDB_BITMAP2);
		robotStatusBitmap.Invalidate();
		Sleep(500);
	}

	if (theApp.robot[ROBOT1 - 1].Socket_Connect(theApp.robot[ROBOT1 - 1].GetRobotIP(ROBOT1), theApp.robot[ROBOT1 - 1].GetRobotPort(ROBOT1)))
	{
		robotStatusBitmap.LoadBitmaps(IDB_BITMAP4);
		robotStatusBitmap.Invalidate();
		Sleep(500);
	}
	else
	{
		robotStatusBitmap.LoadBitmaps(IDB_BITMAP2);
		robotStatusBitmap.Invalidate();
		Sleep(500);
	}

	if (theApp.robot[ROBOT1 - 1].Socket_SendMsg(MSG))
	{
		robotStatusBitmap.LoadBitmaps(IDB_BITMAP3);
		robotStatusBitmap.Invalidate();
		Sleep(500);
	}
	else
	{
		robotStatusBitmap.LoadBitmaps(IDB_BITMAP2);
		robotStatusBitmap.Invalidate();
		Sleep(500);
	}

	theApp.robot[ROBOT1 - 1].Socket_Close();
}

int VISIONDlg::ShowMat(cv::Mat img, HWND hWndDisplay)
{
	if (img.channels() < 3)
	{
		return -1;
	}

	//���콫Ҫ��ʾ��Mat�汾ͼƬ  
	RECT rect;
	::GetClientRect(hWndDisplay, &rect);
	cv::Mat imgShow(abs(rect.top - rect.bottom), abs(rect.right - rect.left), CV_8UC3);
	resize(img, imgShow, imgShow.size());

	//�ڿؼ�����ʾҪ�õ���CImage��ͼƬ  
	ATL::CImage CI;
	int w = imgShow.cols;//��    
	int h = imgShow.rows;//��    
	int channels = imgShow.channels();//ͨ����    
	CI.Create(w, h, 8 * channels);

	//CI���صĸ���  
	uchar *pS;
	uchar *pImg = (uchar *)CI.GetBits();//�õ�CImage��������ַ    
	int step = CI.GetPitch();
	for (int i = 0; i < h; i++)
	{
		pS = imgShow.ptr<uchar>(i);
		for (int j = 0; j < w; j++)
		{
			for (int k = 0; k < 3; k++)
				*(pImg + i*step + j * 3 + k) = pS[j * 3 + k];
			//ע�⵽�����step���ó���3    
		}
	}

	//�ڿؼ���ʾͼƬ  
	HDC dc;
	dc = ::GetDC(hWndDisplay);
	CI.Draw(dc, 0, 0);
	::ReleaseDC(hWndDisplay, dc);
	CI.Destroy();

	return 0;
}

void CAboutDlg::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CDialogEx::OnClose();
	DestroyWindow();
}


void CAboutDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	AfxMessageBox(TEXT("123"));
	CDialogEx::OnOK();
	DestroyWindow();
}


void CAboutDlg::OnIdcancel()
{
	// TODO: �ڴ���������������
	DestroyWindow();
}


void VISIONDlg::OnBnClickedButton11()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//Threshold_settingsDlg->DoModal();
	Mat test=imgDraw.REDO().clone();
	Global_PIC_Size_ShowMat = test.clone();
	imshow("view", test);
	//Threshold_settingsDlg->Create(IDD_DIALOG4, this);
}


void VISIONDlg::OnBnClickedButton12()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//Canny_settingsDlg->Create(IDD_DIALOG6, this);
	//Canny_settingsDlg->DoModal();
	Mat test = imgDraw.UNDO().clone();
	Global_PIC_Size_ShowMat = test.clone();
	imshow("view", test);
}


void VISIONDlg::OnBnClickedButton13()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//Smooth_settingsDlg->Create(IDD_DIALOG7, this);
	Smooth_settingsDlg->DoModal();
}


void VISIONDlg::OnBnClickedButton14()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//TemplateMatch_settingsDlg->Create(IDD_DIALOG5, this);
	TemplateMatch_settingsDlg->DoModal();
}


void VISIONDlg::OnBnClickedButton10()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������;
	/*threshold
	Mat threshold_Mat=Mat(theApp.imgProcess->Img_Threshold(Global_PIC_Show_Mat));
	resize(threshold_Mat, Global_PIC_Size_ShowMat, theApp.PIC_SIZE);
	Global_PIC_Show_Mat = Mat(threshold_Mat);
	imshow("view", Global_PIC_Size_ShowMat);
	*/

	/*canny
	Mat canny_Mat = Mat(theApp.imgProcess->Img_Canny(Global_PIC_Show_Mat));
	resize(canny_Mat, Global_PIC_Size_ShowMat, theApp.PIC_SIZE);
	Global_PIC_Show_Mat = Mat(canny_Mat);
	imshow("view", Global_PIC_Size_ShowMat);
	*/

	Mat g_findImage = imread("C:/Users/ONLY/Desktop/����PIC/1.bmp");
	Mat modeImage1 = imread("C:/Users/ONLY/Desktop/����PIC/temp.bmp");
	Mat modeImage = Mat(CvSize(modeImage1.rows, modeImage1.cols), CV_8UC1);

	//int x = rect.Height();
	//int y = rect.Width();
	//theApp.PIC_SIZE = Size(y, x);
	//resize(findImage, Global_PIC_Size_ShowMat, theApp.PIC_SIZE);
	resize(modeImage1, modeImage, CvSize(modeImage.rows, modeImage.cols));

	Mat findImage;
	g_findImage.copyTo(findImage);

	//�������ͼ�����ͼ��Ŀ�� = �����ҵ���ͼ��Ŀ�� - ģ��ͼ��Ŀ�� + 1�� �߶�ͬ������  
	Mat dstImage;
	dstImage.create(findImage.rows - modeImage.rows + 1, findImage.cols - modeImage.cols + 1, CV_8UC1);

	//����ģ��ƥ�䣬�����Ƿ�ʽ0��ƽ����ƥ�䷨��  
	matchTemplate(findImage, modeImage, dstImage, 0);
	normalize(dstImage, dstImage, 0, 1, 32);

	//���ƾ��η�����ʾ  
	//�����Ǵӵõ��� ��������еõ� ������Сֵ��ƽ����ƥ�䷽ʽ��ԽСԽ�ã����������ַ�ʽ�£��ҵ���Сλ�ã�  
	//�Ҿ������Сλ�õĺ����� minMaxLoc����
	Point minPoint;
	minMaxLoc(dstImage, 0, 0, &minPoint, 0);

	//��ʼ��ʽ����  
	//�乹�캯���ĳ�ʼ�����Դ���һ��64λ�����Ͳ�����Ϊ������������ĳ�ֵ��
	//	next����ȡ����һ���������uniform�������Է���ָ����Χ���������
	//	gaussian��������һ����˹�������fill���������������
	rectangle(findImage, minPoint, Point(minPoint.x + modeImage.cols, minPoint.y + modeImage.rows)
		, Scalar(theRNG().uniform(0, 255), theRNG().uniform(0, 255), theRNG().uniform(0, 255)), 3, 8);
	//resize(findImage, Global_PIC_Size_ShowMat, theApp.PIC_SIZE);
	cvNamedWindow("test", CV_WINDOW_AUTOSIZE);
	imshow("test", findImage);
	//imshow("view", Global_PIC_Size_ShowMat);



	//rectangle(dstImage, minPoint, Point(minPoint.x + modeImage.cols, minPoint.y + modeImage.rows)
	//	, Scalar(theRNG().uniform(0, 255), theRNG().uniform(0, 255), theRNG().uniform(0, 255)), 3, 8);

	circle(dstImage, Point(minPoint.x + modeImage.cols, minPoint.y + modeImage.rows), 100, CvScalar(255, 0, 0), 1, 8, 0);

	resize(dstImage, Global_PIC_Size_ShowMat, theApp.PIC_SIZE);
	imshow("view", Global_PIC_Size_ShowMat);

}


void VISIONDlg::OnBnClickedButton15()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	INT X1, X2, Y1, Y2;
	CString x1, x2, y1, y2;
	CEdit** point = new CEdit*[4];
	point[0] = (CEdit*)GetDlgItem(IDC_EDIT6);
	point[1] = (CEdit*)GetDlgItem(IDC_EDIT5);
	point[2] = (CEdit*)GetDlgItem(IDC_EDIT7);
	point[3] = (CEdit*)GetDlgItem(IDC_EDIT8);

	point[0]->GetWindowText(x1);
	point[1]->GetWindowText(y1);
	point[2]->GetWindowText(x2);
	point[3]->GetWindowText(y2);

	if (x1.IsEmpty() || x2.IsEmpty() || y1.IsEmpty() || y2.IsEmpty())
	{
		AfxMessageBox(TEXT("cannt accept empty input!"));
	}
	else
	{
		X1 = CStringToINT(x1);
		Y1 = CStringToINT(y1);
		X2 = CStringToINT(x2);
		Y2 = CStringToINT(y2);

		//cv::Rectangle(&theApp.intializePIC_Mat, CvPoint(X1, Y1), CvPoint(X2, Y2), CvScalar(0, 0, 255),1,8,0);
		cv::rectangle(*theApp.currentShowMat, CvPoint(X1, Y1), CvPoint(X2, Y2), CV_RGB(255, 200, 100), 1, 8, 0);
		imshow("view", *theApp.currentShowMat);
	}
}


void VISIONDlg::OnBnClickedButton16()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//new
	//cvCopy(Global_PIC_Original_Mat, Global_PIC_CurrentShowMat);
	Global_ShowImageSize[CAM1 - 1].width = Global_PIC_Original_Mat.cols;
	Global_ShowImageSize[CAM1 - 1].height = Global_PIC_Original_Mat.rows;
	resize(Global_PIC_Original_Mat, Global_PIC_Size_ShowMat, theApp.PIC_SIZE);
	imshow("view", Global_PIC_Size_ShowMat);
}


void VISIONDlg::OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//Mat test = imread("C:/Users/ONLY/Desktop/11wq1.bmp");
	//Mat test2 = Mat(theApp.PIC_SIZE,test.type());
	//resize(test, test2,theApp.PIC_SIZE);
	//imshow("view", test2);

	*pResult = 0;
}


void VISIONDlg::OnNMReleasedcaptureSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Mat test = imread("C:/Users/ONLY/Desktop/3.bmp");
	Mat test11 = imread("C:/Users/ONLY/Desktop/1.bmp");
	Mat test2 = Mat(theApp.PIC_SIZE, test.type());
	resize(test, test2, theApp.PIC_SIZE);
	Mat test3= Mat(theApp.PIC_SIZE, test.type());
	resize(test11, test3, theApp.PIC_SIZE);
	int sliderPosition = imgProcessSlider.GetPos() % 2;
	switch (sliderPosition)
	{
	case 0:
		imshow("view", test2);
		break;
	case 1:
		imshow("view", test3);
		break;
	default:
		break;
	}
	*pResult = 0;
}


void VISIONDlg::OnTRBNThumbPosChangingSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// �˹���Ҫ�� Windows Vista ����߰汾��
	// _WIN32_WINNT ���ű��� >= 0x0600��
	NMTRBTHUMBPOSCHANGING *pNMTPC = reinterpret_cast<NMTRBTHUMBPOSCHANGING *>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//Mat test = imread("C:/Users/ONLY/Desktop/saveTest.bmp");
	//Mat test2 = Mat(theApp.PIC_SIZE, test.type());
	//resize(test, test2, theApp.PIC_SIZE);
	//imshow("view", test2);

	*pResult = 0;
}


//void VISIONDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
//{
//	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
//	if (nFlags == VK_DELETE)
//		imgDraw.Vec_imgElement.pop_back();
//	Global_PIC_Size_ShowMat=imgDraw.reDraw().clone();
//	imshow("view", Global_PIC_Size_ShowMat);
//	CDialogEx::OnKeyDown(nChar, nRepCnt, nFlags);
//}


BOOL VISIONDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	
	if (pMsg->wParam == VK_DELETE&&pMsg->message==WM_KEYUP)
	{
		if (imgDraw.currentPointToNode->Vec_operationList.size() > 0)
		{
			imgDraw.currentPointToNode->Vec_operationList.pop_back();
			Global_PIC_Size_ShowMat = imgDraw.reDraw().clone();
			imshow("view", Global_PIC_Size_ShowMat);
		}
		return true;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
