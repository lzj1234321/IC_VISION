#include "stdafx.h"

Socket_Communicate::Socket_Communicate()
{
	AfxSocketInit();
	robotConnectStatus = false;
}

Socket_Communicate::~Socket_Communicate()
{
}

bool Socket_Communicate::Socket_Create()
{
	return(robotSocketX.Create());
}

bool Socket_Communicate::Socket_Connect(const CString robotIP=TEXT("127.0.0.1"),const int robotPort=8888)
{
	if (robotSocketX.Connect(robotIP, robotPort))
	{
		robotConnectStatus = true;
		return true;
	}
	else
		return false;
}

bool Socket_Communicate::Socket_SendMsg(const CString MSG=TEXT("connect test"))
{
	char* t_msg=CStringToCHAR(MSG);
	if (robotSocketX.Send(t_msg, sizeof(t_msg)) != SOCKET_ERROR)
	{
		delete[] t_msg;
		return true;
	}
	else
	{
		delete[] t_msg;
		return false;
	}
}

bool Socket_Communicate::Socket_Recv()
{
	char* recvMSG[1024];
	robotSocketX.Receive(recvMSG, 1024);
	return true;
}

bool Socket_Communicate::Socket_Close()
{
	robotSocketX.Close();
	return true;
}
