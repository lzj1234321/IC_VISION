#pragma once
#include <afxsock.h>
class Socket_Communicate
{
private:
	CSocket robotSocketX;
	BOOL robotConnectStatus;
public:
	Socket_Communicate();
	~Socket_Communicate();
	bool Socket_Create();
	bool Socket_Connect(const CString robotIP ,const int robotPort);
	bool Socket_SendMsg(const CString MSG);
	bool Socket_Recv();
	bool Socket_Close();
};

