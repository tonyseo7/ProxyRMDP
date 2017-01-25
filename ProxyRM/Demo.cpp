#include "stdafx.h"
#include "ListenServer.h"
#include "Camera.h"

void main()
{
	WSADATA wsadata;
	WSAStartup(MAKEWORD(2, 2), &wsadata);

	Camera *camera = new Camera();
	ListenServer *listenserver = new ListenServer(camera);
	WSACleanup();
}