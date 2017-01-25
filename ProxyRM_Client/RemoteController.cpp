#include "stdafx.h"
#include "RemoteController.h"


string RemoteController::TakeAPicture()
{
	SOCKET sock = Connect(TAKE);
	char buf[256];
	recv(sock, buf, 256, 0);
	closesocket(sock);

	return buf;
}

void RemoteController::ChangeMode(bool mode)
{
	SOCKET sock = Connect(CHANGE);
	send(sock, (char *)&mode, sizeof(mode), 0);
	closesocket(sock);

}

bool RemoteController::GetMode()
{
	SOCKET sock = Connect(GET);
	bool mode;
	recv(sock, (char *)&mode, sizeof(mode), 0);
	closesocket(sock);

	return mode;
}


SOCKET RemoteController::Connect(int msgid)
{
	SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	SOCKADDR_IN servaddr = { 0, };
	servaddr.sin_family = PF_INET;
	servaddr.sin_addr.s_addr = inet_addr("192.168.35.54");
	servaddr.sin_port = htons(10200);
	connect(sock, (SOCKADDR *)&msgid, sizeof(msgid));
	send(sock, (char *)&msgid, sizeof(msgid), 0);

	return sock;

}