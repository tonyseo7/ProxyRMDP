#pragma once

#include "ITake.h"

class Camera :public ITake
{
	bool mode;

public:
	Camera(void);
	virtual string TakeAPicture();
	virtual void ChangeMode(bool mode);
	virtual bool GetMode();
};


