
// IC_VISION.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// VISIONApp: 
// 有关此类的实现，请参阅 IC_VISION.cpp
//

class VISIONApp : public CWinApp
{
public:
	VISIONApp();

	//pylon camer
	Pylon_Camera *pyloncamer;
	
	INT detectedCameraNum;
	DeviceInfoList_t CamerasInfoList;
	CBaslerGigEDeviceInfo* Detected_GIGE_CamerInfo;
	CDeviceInfo ChoosedCameraInfo;

	Mat intializePIC_Mat;

	//robot 
	Robot *robot;

	//pic size
	Size PIC_SIZE;

	//current show mat
	Mat* currentShowMat;

	//camera choose num
	INT choosedCameraNum;

	//Img_process
	Img_Process* imgProcess;


// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern VISIONApp theApp;