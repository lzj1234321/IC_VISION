#include"stdafx.h"
#define CamerINI_Src 1
#define RobotINI_Src 2

confLoadSave::confLoadSave()
{
}

confLoadSave::~confLoadSave()
{}

bool confLoadSave::confExistence()
{
	return true;
}

inline CString confLoadSave::getConfDirectory(const INT i)const
{
	CString dirSrc;
	WCHAR src[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, src);
	//if (src == TEXT("C:\\Users\\ONLY\Documents\\Visual Studio 2015\\Projects\\IC_VISION\\x64\\Debug")&&i==1)
	//	return TEXT("C:\\Users\\ONLY\\Documents\\Visual Studio 2015\\Projects\\IC_VISION\\IC_VISION\\configuration\\CameraSetting.ini");
	//else if(src == TEXT("C:\\Users\\ONLY\Documents\\Visual Studio 2015\\Projects\\IC_VISION\\x64\\Debug") && i == 2)
	//	return TEXT("C:\\Users\\ONLY\\Documents\\Visual Studio 2015\\Projects\\IC_VISION\\IC_VISION\\configuration\\RobotSetting.ini");
	for (unsigned int i = 0; i<wcslen(src); i++)
		dirSrc.AppendChar(src[i]);
	WCHAR ex1[MAX_PATH] = TEXT("\\configuration\\CameraSetting.ini");
	WCHAR ex2[MAX_PATH] = TEXT("\\configuration\\RobotSetting.ini");
	if(i==1)
		dirSrc.Append(ex1);
	else if(i==2)
		dirSrc.Append(ex2);
	return dirSrc;
}

bool confLoadSave::RobotSettingsSave(INT robotNum,CString robotIP, CString robotPort)
{
	CString NUM;
	NUM.Format(_T("%d"), robotNum);
	CString dirSrc=getConfDirectory(RobotINI_Src);
	WritePrivateProfileString(TEXT("Robot"+ NUM), TEXT("Port"), robotPort, dirSrc);
	WritePrivateProfileString(TEXT("Robot"+ NUM), TEXT("IPAddress"), robotIP, dirSrc);
	return true;
}

bool confLoadSave::CameraSettingsSave(INT cameraNum,CString camerSerialNum, CString camerIP, CString camerSubMask, bool saveRunRecordFlag, bool saveUnRecognizeImage)
{
	CString NUM;
	NUM.Format(_T("%d"), cameraNum);
	CString SaveRunRecord;
	CString SaveUnrecognizerImage;
	CString dirSrc = getConfDirectory(CamerINI_Src);


	if (saveRunRecordFlag)
		SaveRunRecord = "1";
	else
		SaveRunRecord = "0";
	if (saveUnRecognizeImage)
		SaveUnrecognizerImage = "1";
	else
		SaveUnrecognizerImage = "0";
	WritePrivateProfileString(TEXT("Camera"+ NUM), TEXT("CameraSerialNum"), camerSerialNum, dirSrc);
	WritePrivateProfileString(TEXT("Camera"+ NUM), TEXT("IPAddress"), camerIP, dirSrc);
	WritePrivateProfileString(TEXT("Camera"+ NUM), TEXT("SubnetMask"), camerSubMask, dirSrc);
	WritePrivateProfileString(TEXT("Camera"+ NUM), TEXT("SaveRunRecord"), SaveRunRecord, dirSrc);
	WritePrivateProfileString(TEXT("Camera"+ NUM), TEXT("SaveUnrecognizerImage"), SaveUnrecognizerImage, dirSrc);
	//AfxMessageBox(dirSrc+TEXT("   ")+"Camera"+NUM);
	return true;
}

CString confLoadSave::robotIP_Load(const int num)const
{
	CString NUM;
	NUM.Format(_T("%d"), num);
	CString IPAddress;
	CString dirSrc = getConfDirectory(RobotINI_Src);
	GetPrivateProfileString(TEXT("Robot"+ NUM), TEXT("IPAddress"), TEXT("0.0.0.0"), IPAddress.GetBuffer(MAX_PATH), MAX_PATH, dirSrc);
	return IPAddress;
}

int confLoadSave::robotPort_Load(const int num)const
{
	CString NUM;
	NUM.Format(_T("%d"), num);
	int Port;
	CString dirSrc = getConfDirectory(RobotINI_Src);
	Port=GetPrivateProfileInt(TEXT("Robot"+ NUM), TEXT("Port"), 0, dirSrc);
	return Port;
}

CString confLoadSave::cameraSerialNum_Load(const int num)const
{
	CString NUM;
	NUM.Format(_T("%d"), num);
	CString camerSerialNUM;
	CString dirSrc = getConfDirectory(CamerINI_Src);
	GetPrivateProfileString(TEXT("Camera"+ NUM), TEXT("CameraSerialNum"), TEXT("N/A"), camerSerialNUM.GetBuffer(MAX_PATH), MAX_PATH, dirSrc);
	return camerSerialNUM;
}

CString confLoadSave::cameraUserDefineID_Load(const int num)const
{
	CString NUM;
	NUM.Format(_T("%d"), num);
	CString cameraUserDefineID;
	CString dirSrc = getConfDirectory(CamerINI_Src);
	GetPrivateProfileString(TEXT("Camera" + NUM), TEXT("IPAddress"), TEXT("N/A"), cameraUserDefineID.GetBuffer(MAX_PATH), MAX_PATH, dirSrc);
	return cameraUserDefineID;
}

CString confLoadSave::cameraIP_Load(const int num)const
{
	CString NUM;
	NUM.Format(_T("%d"), num);
	CString IPAddress;
	CString dirSrc = getConfDirectory(CamerINI_Src);
	GetPrivateProfileString(TEXT("Camera"+ NUM), TEXT("IPAddress"), TEXT("0.0.0.0"), IPAddress.GetBuffer(MAX_PATH), MAX_PATH, dirSrc);
	return IPAddress;
}

CString confLoadSave::cameraSubMask_Load(const int num)const
{
	CString NUM;
	NUM.Format(_T("%d"), num);
	CString SubnetMask;
	CString dirSrc = getConfDirectory(CamerINI_Src);
	GetPrivateProfileString(TEXT("Camera"+ NUM), TEXT("SubnetMask"), TEXT("0.0.0.0"), SubnetMask.GetBuffer(MAX_PATH), MAX_PATH, dirSrc);
	return SubnetMask;
}

bool confLoadSave::GetSaveRunRecord_Load(const int num)const
{
	CString NUM;
	NUM.Format(_T("%d"), num);
	CString SaveRunRecord;
	CString dirSrc = getConfDirectory(CamerINI_Src);
	GetPrivateProfileString(TEXT("Camera"+ NUM), TEXT("SaveRunRecord"), TEXT("0"), SaveRunRecord.GetBuffer(MAX_PATH), MAX_PATH, dirSrc);
	if (SaveRunRecord == "1")
		return true;
	else
		return false;
}

bool confLoadSave::GetSaveUnrecognizerImage_Load(const int num)const
{
	CString NUM;
	NUM.Format(_T("%d"), num);
	CString SaveUnrecognizerImage;
	CString dirSrc = getConfDirectory(CamerINI_Src);
	GetPrivateProfileString(TEXT("Camera"+ NUM), TEXT("SaveUnrecognizerImage"), TEXT("0"), SaveUnrecognizerImage.GetBuffer(MAX_PATH), MAX_PATH, dirSrc);
	if (SaveUnrecognizerImage == "1")
		return true;
	else
		return false;
}


