#pragma once
class CameraBase
{
public:
	CameraBase();
	virtual ~CameraBase();
	//camera configuration set/get
	virtual CString GetCameraIP(const int cameraNum)const=0;
	virtual CString GetCameraSubMask(const int cameraNum)const = 0;
	virtual CString GetCameraSerialNum(const int cameraNum)const=0;
	virtual CString GetCameraUserDefineID(const int cameraNum)const = 0;

	//camera operation
	virtual BOOL SaveImage(const int cameraNum) = 0;
	virtual UINT SnapImage(const int cameraNum) = 0;
	virtual BOOL IsGrabSucced(const int cameraNum)const=0;
};

