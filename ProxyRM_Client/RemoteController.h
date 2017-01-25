#pragma once
#include "ITake.h"
#include <WinSock2.h>
#pragma comment(lib, "ws2_32")
#include <Windows.h>

class RemoteController : public ITake
{
public:
	virtual string TakeAPicture();
	virtual void ChangeMode(bool mode);
	virtual bool GetMode();
	
private:
	SOCKET Connect(int msgid);
};
