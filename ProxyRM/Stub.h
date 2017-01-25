#pragma once
#include "ITake.h"
#include <WinSock2.h>
#pragma comment(lib, "ws2_32")

class Stub
{
	ITake *itake;
	SOCKET sock;
	
public:
	Stub(SOCKET dosock, ITake *itake);
	void Do();
	~Stub(void);

private:
	void TakeProc();
	void ChangeProc();
	void GetProc();
};
