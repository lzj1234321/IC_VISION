#include "stdafx.h"
using namespace Pylon;

Pylon_Camera::Pylon_Camera()
{
	grabFlag = false;
	PylonInitialize();
	cameraPtr = new PylonGIGECamerStruct[MAX_CONNECT_CAMERA_NUM];
	for (int i = 0; i < MAX_CONNECT_CAMERA_NUM; i++)
	{
		cameraPtr[i].cameraSerialNum = cameraSerialNum_Load(i + 1);
		cameraPtr[i].camerIP = cameraIP_Load(i + 1);
		cameraPtr[i].camerSubMask = cameraSubMask_Load(i + 1);
		cameraPtr[i].saveRunRecord = GetSaveRunRecord_Load(i + 1);
		cameraPtr[i].saveUnRecognizerImage = GetSaveUnrecognizerImage_Load(i + 1);
	}
	imageFormatPtr = new PylonImageFormat[MAX_CONNECT_CAMERA_NUM];
	grabImageMat = new Mat[MAX_CONNECT_CAMERA_NUM];
}

Pylon_Camera::~Pylon_Camera()
{
	PylonTerminate();
	delete[] cameraPtr;
	delete[] grabImageMat;
}

BOOL Pylon_Camera::Pylon_Camera_Intialize()
{
	return true;
}

VOID Pylon_Camera::cameraSettingsChange(const INT cameraNum, CString camerSerialNum, CString camerIP, CString camerSubMask)
{
	cameraPtr[cameraNum-1].cameraSerialNum = camerSerialNum;
	cameraPtr[cameraNum-1].camerIP = camerIP;
	cameraPtr[cameraNum-1].camerSubMask = camerSubMask;
}

UINT Pylon_Camera::SnapImage(const INT cameraNum)
{
	CGrabResultPtr ptrGrabResult;
	CTlFactory& tlFactory = CTlFactory::GetInstance();
	if(true)
	{
		try
		{
			Global_GigeCameraArray[cameraNum - 1].GrabOne(1000, ptrGrabResult, TimeoutHandling_ThrowException);
			if(ptrGrabResult->GrabSucceeded()&&ptrGrabResult)
			{
				grabFlag = true;
				int rows = ptrGrabResult->GetHeight();
				int columns = ptrGrabResult->GetWidth();

				imageFormatPtr[cameraNum - 1].width = columns;
				imageFormatPtr[cameraNum - 1].height = rows;
				imageFormatPtr[cameraNum - 1].bufferSize = ptrGrabResult->GetImageSize();
				imageFormatPtr[cameraNum - 1].pixFormat = ptrGrabResult->GetPixelType();

				grabImageMat[cameraNum - 1] = Mat(rows, columns, CV_8U);
				int nCols = rows*columns;
				UCHAR* p;
				const uint8_t *pImageBuffer = (uint8_t *)ptrGrabResult->GetBuffer();
				p = (grabImageMat[cameraNum - 1]).ptr<uchar>(0);
				if (grabImageMat[cameraNum - 1].isContinuous())
				{
					for (int i = 0; i < nCols; i++)
						p[i] = pImageBuffer[i];
				}
				return 1;
			}
			else
			{
				grabFlag = false;
				return 0;
			}
		}
		catch (ETimeoutHandling timeoutHandling)
		{
			if (timeoutHandling == TimeoutHandling_ThrowException)
			{
				AfxMessageBox(TEXT("Grab TimeOut!"));
			}
			grabFlag = false;
			return 0;
		}
	}
	else
	{
		AfxMessageBox(TEXT("UNDETECTED ANY CAMERA!"));
		return 0;
	}
}

BOOL Pylon_Camera::SaveImage(const INT cameraNum)
{
	return true;
}

Mat& Pylon_Camera::GetGrabImageMat(const INT cameraNum)const
{
	return grabImageMat[cameraNum-1];
}

BOOL Pylon_Camera::IsGrabSucced(const INT cameraNum)const
{
	return grabFlag;
}

CString Pylon_Camera::GetCameraIP(const int num)const
{
	//return cameraIP_Load(num);
	return cameraPtr[num - 1].camerIP;
}

CString Pylon_Camera::GetCameraSubMask(const int num)const
{
	//return cameraSubMask_Load(num);
	return cameraPtr[num - 1].camerSubMask;
}

CString Pylon_Camera::GetCameraSerialNum(const int num)const
{
	//return cameraSerialNum_Load(num);
	return cameraPtr[num - 1].cameraSerialNum;
}

CString Pylon_Camera::GetCameraUserDefineID(const int num)const
{
	//return cameraUserDefineID_Load(num);
	return cameraPtr[num - 1].cameraUserDefineID;
}

BOOL Pylon_Camera::GetCameraSaveRunRecord(const int num)const
{
	return cameraPtr[num - 1].saveRunRecord;
}

BOOL Pylon_Camera::GetCameraSaveUnRecognizerImage(const int num)const
{
	return cameraPtr[num - 1].saveUnRecognizerImage;
}

BOOL Pylon_Camera::ChangeCurrentUsedCamera(const int num, CString serialNum)
{
	cameraPtr[num - 1].cameraSerialNum = serialNum;
	return true;
}



