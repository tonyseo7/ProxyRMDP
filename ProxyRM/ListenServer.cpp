#include "stdafx.h"
#include "ListenServer.h"

ListenServer::ListenServer(ITake *itake)
{
	SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	SOCKADDR_IN servaddr = { 0, };
	servaddr.sin_family = PF_INET;
	servaddr.sin_addr.s_addr = inet_addr("192.168.35.54");
	servaddr.sin_port = htons(10200);
	bind(sock, (SOCKADDR *)&servaddr, sizeof(servaddr));
	listen(sock, 5);

	SOCKADDR_IN clientaddr;
	int len = sizeof(clientaddr);
	SOCKET dosock;
	DWORD ThreadID;
	Stub *stub = 0;

	while (1)
	{
		dosock = accept(sock, (SOCKADDR *)&clientaddr, &len);
		stub = new Stub(dosock, itake);
		CloseHandle(CreateThread(0, 0, DoIt, stub, 0, &ThreadID));
	}
}

DWORD WINAPI ListenServer::DoIt(LPVOID pin)
{
	Stub *stub = (Stub *)pin;
	stub->Do();
	delete stub;
	return 0;
}