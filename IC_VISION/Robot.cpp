#include "stdafx.h"


Robot::Robot()
{
	robot_struct = new robotStruct[MAX_CONNECT_ROBOT_NUM];
	for (int i = 0; i < MAX_CONNECT_ROBOT_NUM; i++)
	{
		robotINI_Load(i);
	}
}


Robot::~Robot()
{
	delete[] robot_struct;
}

CString Robot::GetRobotIP(const int num)const
{
	return robot_struct[num-1].robotIP;
}

int Robot::GetRobotPort(const int num)const
{
	return robot_struct[num-1].robotPort;
}

bool Robot::SetRobotIP(const int num, const CString IP)
{
	robot_struct[num-1].robotIP = IP;
	return true;
}

bool Robot::SetRobotPort(const int num, const int Port)
{
	robot_struct[num-1].robotPort = Port;
	return true;
}

bool Robot::sendMessageToRobot(const int num,const CString MSG)
{
	Socket_Create();
	Socket_Connect(robot_struct[num-1].robotIP, robot_struct[num-1].robotPort);
	Socket_SendMsg(MSG);
	Socket_Close();
	return true;
}

bool Robot::robotINI_Load(const int num)
{
	robot_struct[num].robotIP=robotConf_Load.robotIP_Load(num+1);
	robot_struct[num].robotPort=robotConf_Load.robotPort_Load(num+1);
	return true;
}
