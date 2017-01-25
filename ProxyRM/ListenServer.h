#pragma once
#include <WinSock2.h>
#pragma comment(lib, "ws2_32")
#include <Windows.h>
#include "Stub.h"

class ListenServer
{
public:
	ListenServer(ITake *itake);

private:
	static DWORD WINAPI DoIt(LPVOID pin);
};