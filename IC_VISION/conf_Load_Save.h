class confLoadSave
{
private:
	CString IP_ini_Path;
	CString Camera_ini_Path;
	CString settingsPath;
public:
	confLoadSave();
	~confLoadSave();
	bool confExistence();
	CString inline getConfDirectory(INT i)const;

	//robot
	CString robotIP_Load(const int num)const;
	INT robotPort_Load(const int num)const;
	bool RobotSettingsSave(INT robotNum,CString robotIP, CString robotPort);

	//camera
	CString cameraSerialNum_Load(const int num)const;
	CString cameraUserDefineID_Load(const int num)const;
	CString cameraIP_Load(const int num)const;
	CString cameraSubMask_Load(const int num)const;
	bool GetSaveRunRecord_Load(const int num)const;
	bool GetSaveUnrecognizerImage_Load(const int num)const;
	bool CameraSettingsSave(INT cameraNum,CString camerSerialNum, CString camerIP, CString camerSubMask, bool saveRunRecordFlag, bool saveUnRecognizeImage);
};