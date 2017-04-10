
// VISIONDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "IC_VISION.h"
#include "IC_VISIONDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// VISIONDlg 对话框



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


// VISIONDlg 消息处理程序

BOOL VISIONDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	//picture控件添加图片显示
	namedWindow("view", WINDOW_AUTOSIZE);
	char TrackbarName[50];
	int min = 0;
	int max = 255;


	BEENCHOOSED_ELEMENTNUM = -1;

	HWND hWnd = (HWND)cvGetWindowHandle("view");
	HWND hParent = ::GetParent(hWnd);
	::SetParent(hWnd, GetDlgItem(IDC_PIC)->m_hWnd);
	::ShowWindow(hParent, SW_HIDE);

	//创建设置窗口
	Camera_settingsDialog = new CameraSettingsDialog(this);
	Robot_settingsDialog = new RobotSettingsDlg(this);
	Camera_ChooseDlg = new CameraChooseDlg(this);

	//创建图像处理设置窗口
	Threshold_settingsDlg = new ThresholdSettingsDlg(this);
	Canny_settingsDlg = new CannySettingsDlg(this);
	Smooth_settingsDlg = new SmoothSettingsDlg(this);
	TemplateMatch_settingsDlg = new TemplateSettingsDlg(this);

	//创建机器人
	theApp.robot = new Robot[MAX_CONNECT_ROBOT_NUM];

	//初始化各窗口显示图像大小为0
	for (int i = 0; i < 5; i++)
	{
		Global_ShowImageSize[i].height = 0;
		Global_ShowImageSize[i].width = 0;
	}

	//初始化相机,机器人连接状态为false
	for (int i = 0; i < MAX_CONNECT_CAMERA_NUM; i++)
		Global_CameraConnect_Statu[i] = FALSE;
	for (int i = 0; i < MAX_CONNECT_ROBOT_NUM; i++)
		Global_RobotConnect_Statu[i] = FALSE;

	//加载初始化状态指示位图
	cameraStatusBitmap.LoadBitmaps(IDB_BITMAP6);
	cameraStatusBitmap.SubclassDlgItem(IDC_BUTTON3, this);
	cameraStatusBitmap.SizeToContent();
	robotStatusBitmap.LoadBitmaps(IDB_BITMAP6);
	robotStatusBitmap.SubclassDlgItem(IDC_BUTTON5, this);
	robotStatusBitmap.SizeToContent();

	//创建PYLON相机
	theApp.pyloncamer = new Pylon_Camera();
	CameraBase* testCamera = new Pylon_Camera();
	//加载robot信息
	for (int i = 0; i < MAX_CONNECT_ROBOT_NUM; i++)
		theApp.robot[ROBOT1 - 1].robotINI_Load(i);

	//创建已连接相机
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


	//加载INI相机信息，并根据已连接相机信息进行判断是否可以创建
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
	//初始化相机对应关系
	for (int i = 0; i < MAX_CONNECT_CAMERA_NUM; i++)
	{
		Globa_Camera_Choose[i] = i + 1;
	}

	Global_Camera_Run_Record_Save[CAM1] = theApp.pyloncamer->GetCameraSaveRunRecord(CAM1);
	Global_UnRecognizeImage_Save[CAM1] = theApp.pyloncamer->GetCameraSaveUnRecognizerImage(CAM1);

	//获取显示图像PIC控件SIZE
	CRect rect;
	CWnd* pWnd = GetDlgItem(IDC_PIC);//IDC_picture为picture控件ID
	pWnd->GetClientRect(&rect);//rc为控件的大小。
	int x = rect.Height();
	int y = rect.Width();
	theApp.PIC_SIZE = Size(y, x);

	//初始化显示矩阵
	Global_PIC_Size_ShowMat = Mat(theApp.PIC_SIZE, CV_8UC3, Scalar(255, 0, 0));
	Global_PIC_intializeMat = Mat(theApp.PIC_SIZE, CV_8UC3, Scalar(255, 0, 0));

	//初始化PIC_CONTROL显示控件
	//theApp.intializePIC_Mat = Mat(theApp.PIC_SIZE, CV_8UC3, Scalar(255, 0, 0));
	//imshow("view", Global_PIC_intializeMat);
	imgDraw.originalMat = Global_PIC_Size_ShowMat;

	//设置显示画面鼠标事件
	theApp.currentShowMat = new Mat(theApp.PIC_SIZE, CV_8U);
	cvSetMouseCallback("view", ImageMouseClickEvent, &Global_PIC_Size_ShowMat);
	imshow("view", Global_PIC_Size_ShowMat);
	theApp.imgProcess = new Img_Process;

	//设置slider属性
	imgProcessSlider.SetRange(0, 20); 
	imgProcessSlider.SetTicFreq(300);   // 每10个单位画一刻度.  
	//imgProcessSlider.SetPos(1000);      // 设置默认单消间隔时间为1秒.

	imgX = (CEdit*)GetDlgItem(IDC_EDIT2);
	imgY = (CEdit*)GetDlgItem(IDC_EDIT3);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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


// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void VISIONDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
		CDialog::UpdateWindow();
		//ShowImage(TheImage, IDC_PIC);

	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
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
			CWnd* pWnd = GetDlgItem(IDC_PIC);//IDC_picture为picture控件ID
			pWnd->GetClientRect(&rect);//rc为控件的大小。
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
	// TODO: 在此添加控件通知处理程序代码
	BOOL isOpen = TRUE;     //是否打开(否则为保存)  
	CString defaultDir;   //默认打开的文件路径  
	CString fileName = L"";         //默认打开的文件名  
	CString filter = L"文件 (*.bmp; *.jpeg)|*.bmp;*.jpeg||";   //文件过虑的类型  
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
	// TODO: 在此添加控件通知处理程序代码
	Camera_settingsDialog->DoModal();
	//Camera_settingsDialog->Create(IDD_DIALOG1, this);
}


void VISIONDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
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

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void VISIONDlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	//Robot_settingsDialog->Create(IDD_DIALOG2, this);
	Robot_settingsDialog->DoModal();
}


void VISIONDlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
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

	//构造将要显示的Mat版本图片  
	RECT rect;
	::GetClientRect(hWndDisplay, &rect);
	cv::Mat imgShow(abs(rect.top - rect.bottom), abs(rect.right - rect.left), CV_8UC3);
	resize(img, imgShow, imgShow.size());

	//在控件上显示要用到的CImage类图片  
	ATL::CImage CI;
	int w = imgShow.cols;//宽    
	int h = imgShow.rows;//高    
	int channels = imgShow.channels();//通道数    
	CI.Create(w, h, 8 * channels);

	//CI像素的复制  
	uchar *pS;
	uchar *pImg = (uchar *)CI.GetBits();//得到CImage数据区地址    
	int step = CI.GetPitch();
	for (int i = 0; i < h; i++)
	{
		pS = imgShow.ptr<uchar>(i);
		for (int j = 0; j < w; j++)
		{
			for (int k = 0; k < 3; k++)
				*(pImg + i*step + j * 3 + k) = pS[j * 3 + k];
			//注意到这里的step不用乘以3    
		}
	}

	//在控件显示图片  
	HDC dc;
	dc = ::GetDC(hWndDisplay);
	CI.Draw(dc, 0, 0);
	::ReleaseDC(hWndDisplay, dc);
	CI.Destroy();

	return 0;
}

void CAboutDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnClose();
	DestroyWindow();
}


void CAboutDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	AfxMessageBox(TEXT("123"));
	CDialogEx::OnOK();
	DestroyWindow();
}


void CAboutDlg::OnIdcancel()
{
	// TODO: 在此添加命令处理程序代码
	DestroyWindow();
}


void VISIONDlg::OnBnClickedButton11()
{
	// TODO: 在此添加控件通知处理程序代码
	//Threshold_settingsDlg->DoModal();
	Mat test=imgDraw.REDO().clone();
	Global_PIC_Size_ShowMat = test.clone();
	imshow("view", test);
	//Threshold_settingsDlg->Create(IDD_DIALOG4, this);
}


void VISIONDlg::OnBnClickedButton12()
{
	// TODO: 在此添加控件通知处理程序代码
	//Canny_settingsDlg->Create(IDD_DIALOG6, this);
	//Canny_settingsDlg->DoModal();
	Mat test = imgDraw.UNDO().clone();
	Global_PIC_Size_ShowMat = test.clone();
	imshow("view", test);
}


void VISIONDlg::OnBnClickedButton13()
{
	// TODO: 在此添加控件通知处理程序代码
	//Smooth_settingsDlg->Create(IDD_DIALOG7, this);
	Smooth_settingsDlg->DoModal();
}


void VISIONDlg::OnBnClickedButton14()
{
	// TODO: 在此添加控件通知处理程序代码
	//TemplateMatch_settingsDlg->Create(IDD_DIALOG5, this);
	TemplateMatch_settingsDlg->DoModal();
}


void VISIONDlg::OnBnClickedButton10()
{
	// TODO: 在此添加控件通知处理程序代码;
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

	Mat g_findImage = imread("C:/Users/ONLY/Desktop/安检PIC/1.bmp");
	Mat modeImage1 = imread("C:/Users/ONLY/Desktop/安检PIC/temp.bmp");
	Mat modeImage = Mat(CvSize(modeImage1.rows, modeImage1.cols), CV_8UC1);

	//int x = rect.Height();
	//int y = rect.Width();
	//theApp.PIC_SIZE = Size(y, x);
	//resize(findImage, Global_PIC_Size_ShowMat, theApp.PIC_SIZE);
	resize(modeImage1, modeImage, CvSize(modeImage.rows, modeImage.cols));

	Mat findImage;
	g_findImage.copyTo(findImage);

	//创建输出图像，输出图像的宽度 = 被查找到额图像的宽度 - 模版图像的宽度 + 1， 高度同样符合  
	Mat dstImage;
	dstImage.create(findImage.rows - modeImage.rows + 1, findImage.cols - modeImage.cols + 1, CV_8UC1);

	//进行模版匹配，首先是方式0（平方差匹配法）  
	matchTemplate(findImage, modeImage, dstImage, 0);
	normalize(dstImage, dstImage, 0, 1, 32);

	//绘制矩形方便显示  
	//首先是从得到的 输出矩阵中得到 最大或最小值（平方差匹配方式是越小越好，所以在这种方式下，找到最小位置）  
	//找矩阵的最小位置的函数是 minMaxLoc函数
	Point minPoint;
	minMaxLoc(dstImage, 0, 0, &minPoint, 0);

	//开始正式绘制  
	//其构造函数的初始化可以传入一个64位的整型参数作为随机数产生器的初值。
	//	next可以取出下一个随机数，uniform函数可以返回指定范围的随机数，
	//	gaussian函数返回一个高斯随机数，fill则用随机数填充矩阵。
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
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码

	//Mat test = imread("C:/Users/ONLY/Desktop/11wq1.bmp");
	//Mat test2 = Mat(theApp.PIC_SIZE,test.type());
	//resize(test, test2,theApp.PIC_SIZE);
	//imshow("view", test2);

	*pResult = 0;
}


void VISIONDlg::OnNMReleasedcaptureSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
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
	// 此功能要求 Windows Vista 或更高版本。
	// _WIN32_WINNT 符号必须 >= 0x0600。
	NMTRBTHUMBPOSCHANGING *pNMTPC = reinterpret_cast<NMTRBTHUMBPOSCHANGING *>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码

	//Mat test = imread("C:/Users/ONLY/Desktop/saveTest.bmp");
	//Mat test2 = Mat(theApp.PIC_SIZE, test.type());
	//resize(test, test2, theApp.PIC_SIZE);
	//imshow("view", test2);

	*pResult = 0;
}


//void VISIONDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
//{
//	// TODO: 在此添加消息处理程序代码和/或调用默认值
//	if (nFlags == VK_DELETE)
//		imgDraw.Vec_imgElement.pop_back();
//	Global_PIC_Size_ShowMat=imgDraw.reDraw().clone();
//	imshow("view", Global_PIC_Size_ShowMat);
//	CDialogEx::OnKeyDown(nChar, nRepCnt, nFlags);
//}


BOOL VISIONDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	
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
