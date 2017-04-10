
// IC_VISION.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// VISIONApp: 
// �йش����ʵ�֣������ IC_VISION.cpp
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


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern VISIONApp theApp;