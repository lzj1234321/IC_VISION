#pragma once
#include<opencv.hpp>
#include<cv.h>
#include<highgui.h>
#include <cxcore.hpp>
using namespace cv;
using namespace std;
#include <pylon/Device.h>
#include <pylon/PylonGUI.h>
#include <pylon/DeviceClass.h>
#include <pylon/NodeMapProxy.h>
#include <pylon/PylonIncludes.h>
#include <pylon/PylonImageBase.h>
#include <pylon/gige/_GigETLParams.h>
#include <pylon/gige/PylonGigECamera.h>
#include <pylon/gige/PylonGigEDevice.h>
#include <pylon/gige/_GigEEventParams.h>
#include <pylon/gige/_GigEStreamParams.h>
#include <pylon/gige/BaslerGigEDeviceInfo.h>
#include <pylon/gige/BaslerGigEGrabResultPtr.h>
#include <pylon/gige/_BaslerGigECameraParams.h>
#include <pylon/gige/BaslerGigEInstantCamera.h>
#include <pylon/gige/BaslerGigEImageEventHandler.h>
#include <pylon/gige/BaslerGigEInstantCameraArray.h>
#include <pylon/gige/BaslerGigECameraEventHandler.h>
#include <pylon/private/DeviceSpecificInstantCamera.h>
#include <pylon/gige/BaslerGigEConfigurationEventHandler.h>
#include<map>

//using namespace std;
class Pylon_Camera:public CameraBase,public confLoadSave
{
private:
	Mat* grabImageMat;
	bool grabFlag;
	struct PylonGIGECamerStruct* cameraPtr;
public:
	struct PylonImageFormat* imageFormatPtr;
	Pylon_Camera();
	virtual ~Pylon_Camera();
	virtual BOOL Pylon_Camera_Intialize();
	virtual UINT SnapImage(const INT cameraNum);
	virtual BOOL SaveImage(const INT cameraNum);
	virtual Mat& GetGrabImageMat(const INT cameraNum)const;
	virtual BOOL IsGrabSucced(const INT cameraNum)const;

	////camera configuration set/get
	virtual VOID cameraSettingsChange(const INT cameraNum, CString cameraSerialNum, CString cameraIP, CString cameraSubMask);
	virtual CString GetCameraIP(const int cameraNum)const;
	virtual CString GetCameraSubMask(const int cameraNum)const;
	virtual CString GetCameraSerialNum(const int cameraNum)const;
	virtual CString GetCameraUserDefineID(const int cameraNum)const;
	virtual BOOL GetCameraSaveRunRecord(const int num)const;
	virtual BOOL GetCameraSaveUnRecognizerImage(const int num)const;
	virtual BOOL ChangeCurrentUsedCamera(const int num, CString serialNum);
};

