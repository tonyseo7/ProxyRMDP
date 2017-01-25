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
		cout << "���� ���� ��ȯ�Ǿ����ϴ�." << endl;
	}
	else
	{
		cout << "�ڵ� ���� ��ȯ�Ǿ����ϴ�." << endl;
	}

	delete remocon;

	WSACleanup();
}