#include "stdafx.h"
#include "Camera.h"

Camera::Camera(void) { mode = false; }

string Camera::TakeAPicture()
{
	cout << "������ ����ϴ�." << endl;

	if (mode)
	{
		return "���� ���� ���� ����";
	}

	return "�ڵ� ���� ���� ����";
}

void Camera::ChangeMode(bool mode)
{
	this->mode = mode;
	if (mode)
	{
		cout << "���� ���� ��ȯ�Ǿ����ϴ�." << endl;

	}
	else
	{
		cout << "�ڵ� ���� ��ȯ�Ǿ����ϴ�." << endl;
	}
}


bool Camera::GetMode()
{
	if (mode)
	{
		cout << "���� ����Դϴ�." << endl;
	}
	else
	{
		cout << "�ڵ� ����Դϴ�." << endl;
	}

	return mode;
}