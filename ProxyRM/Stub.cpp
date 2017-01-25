#include "stdafx.h"
#include "Stub.h"


Stub::Stub(SOCKET dosock, ITake *itake)
{
	sock = dosock;
	this->itake = itake;
}

void Stub::Do()
{
	int msgid = 0;
	recv(sock, (char *)&msgid, sizeof(msgid), 0);

	switch (msgid)
	{
		case TAKE:
		{
			TakeProc();
			break;
		}
		case CHANGE:
		{
			ChangeProc();
			break;
		}
		case GET:
		{
			GetProc();
			break;
		}

	}
}

void Stub::TakeProc()
{
	string picture = itake->TakeAPicture();
	char buf[256];
	strcpy(buf, picture.c_str());
	send(sock, buf, 256, 0);
}

void Stub::ChangeProc()
{
	bool mode;
	recv(sock, (char *)&mode, sizeof(mode), 0);
	itake->ChangeMode(mode);
}

void Stub::GetProc()
{
	bool mode;
	mode = itake->GetMode();
	send(sock, (char *)&mode, sizeof(mode), 0);
}

Stub::~Stub(void)
{
	closesocket(sock);
}