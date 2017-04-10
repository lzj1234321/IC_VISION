#pragma once
class Robot :public confLoadSave,public Socket_Communicate
{
private:
	struct robotStruct* robot_struct;
	confLoadSave robotConf_Load;
public:
	Robot();
	~Robot();
	CString GetRobotIP(const int num)const;
	int GetRobotPort(const int num)const;
	bool SetRobotIP(const int num,const CString IP);
	bool SetRobotPort(const int num, const int port);
	bool sendMessageToRobot(const int num, const CString MSG);
	bool robotINI_Load(int num);
};

