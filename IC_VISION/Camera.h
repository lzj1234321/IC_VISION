#pragma once
class Camera:public confLoadSave
{
private:
	struct PylonGIGECamerStruct* cameraPtr;
public:
	Camera();
	~Camera();
	virtual CString GetCameraIP(const int num)const;
	virtual CString GetCameraSerialNum(const int num)const;
	virtual CString GetCameraUserDefineID(const int num)const;
	virtual CString GetCameraSubMask(const int num)const;
	virtual bool GetSaveRunRecord(const int num)const;
	virtual bool GetSaveUnrecognizerImage(const int num)const;
	virtual bool ChangeCurrentUsedCamera(const int num,CString serialNum);
	virtual bool SetCameraIP(const int num, const CString IP);
	virtual bool SetCameraPort(const int num, const int port);
	virtual bool cameraINI_Load(int num);
	virtual bool AlterCameraInfo(INT cameraNum, CString camerSerialNum, CString cameraIP, CString cameraSubMask, bool saveRunRecordFlag, bool saveUnRecognizeImage);
};

