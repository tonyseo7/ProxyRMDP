#include "stdafx.h"
#include "RemoteController.h"

void main()
{
	WSADATA wsadata;
	WSAStartup(MAKEWORD(2, 2), &wsadata);
	RemoteController *remocon = new RemoteController();
	string s = remocon->TakeAPicture();
	cout << s << endl;
	remocon->ChangeMode(false);
	s = remocon->TakeAPicture();
	cout << s << endl;

	bool mode = remocon->GetMode();

	if (mode)
	{
		cout << "수동 모드로 변환되었습니다." << endl;
	}
	else
	{
		cout << "자동 모드로 변환되었습니다." << endl;
	}

	delete remocon;

	WSACleanup();
}