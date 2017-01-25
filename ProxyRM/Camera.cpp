#include "stdafx.h"
#include "Camera.h"

Camera::Camera(void) { mode = false; }

string Camera::TakeAPicture()
{
	cout << "사진을 찍습니다." << endl;

	if (mode)
	{
		return "수동 모드로 찍힌 사진";
	}

	return "자동 모드로 찍힌 사진";
}

void Camera::ChangeMode(bool mode)
{
	this->mode = mode;
	if (mode)
	{
		cout << "수동 모드로 변환되었습니다." << endl;

	}
	else
	{
		cout << "자동 모드로 변환되었습니다." << endl;
	}
}


bool Camera::GetMode()
{
	if (mode)
	{
		cout << "수동 모드입니다." << endl;
	}
	else
	{
		cout << "자동 모드입니다." << endl;
	}

	return mode;
}