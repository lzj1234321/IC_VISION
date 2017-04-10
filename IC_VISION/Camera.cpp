#include "stdafx.h"
//#include "Camera.h"


Camera::Camera()
{
	cameraPtr=new PylonGIGECamerStruct[MAX_CONNECT_CAMERA_NUM];
	for (int i = 0; i < MAX_CONNECT_CAMERA_NUM; i++)
	{
		cameraPtr[i].cameraSerialNum = cameraSerialNum_Load(i+1);
		cameraPtr[i].camerIP = cameraIP_Load(i+1);
		cameraPtr[i].camerSubMask = cameraSubMask_Load(i+1);
		cameraPtr[i].saveRunRecord = GetSaveRunRecord_Load(i + 1);
		cameraPtr[i].saveUnRecognizerImage = GetSaveUnrecognizerImage_Load(i + 1);
	}
}

Camera::~Camera()
{
	//delete[] cameraPtr;
}

CString Camera::GetCameraIP(const int num)const
{
	//return cameraIP_Load(num);
	return cameraPtr[num - 1].camerIP;
}

CString Camera::GetCameraSubMask(const int num)const
{
	//return cameraSubMask_Load(num);
	return cameraPtr[num - 1].camerSubMask;
}

CString Camera::GetCameraSerialNum(const int num)const
{
	//return cameraSerialNum_Load(num);
	return cameraPtr[num - 1].cameraSerialNum;
}

CString Camera::GetCameraUserDefineID(const int num)const
{
	//return cameraUserDefineID_Load(num);
	return cameraPtr[num - 1].cameraUserDefineID;
}

bool Camera::GetSaveRunRecord(const int num)const
{
	//return GetSaveRunRecord_Load(num);
	return cameraPtr[num - 1].saveRunRecord;
}

bool Camera::GetSaveUnrecognizerImage(const int num)const
{
	//return GetSaveUnrecognizerImage_Load(num);
	return cameraPtr[num - 1].saveUnRecognizerImage;
}

bool Camera::ChangeCurrentUsedCamera(const int num,CString serialNum)
{
	cameraPtr[num - 1].cameraSerialNum = serialNum;
	return true;
}

bool Camera::SetCameraIP(const int num, const CString IP)
{
	return true;
}

bool Camera::SetCameraPort(const int num, const int port)
{
	return true;
}

bool Camera::cameraINI_Load(int num)
{
	return true;
}

bool Camera::AlterCameraInfo(INT cameraNum, CString camerSerialNum, CString camerIP, CString camerSubMask, bool saveRunRecordFlag, bool saveUnRecognizeImage)
{
	cameraPtr[cameraNum-1].cameraSerialNum = camerSerialNum;
	cameraPtr[cameraNum-1].camerIP = camerIP;
	cameraPtr[cameraNum-1].camerSubMask = camerSubMask;
	cameraPtr[cameraNum-1].saveRunRecord = saveRunRecordFlag;
	cameraPtr[cameraNum-1].saveUnRecognizerImage = saveUnRecognizeImage;
	return true;
}