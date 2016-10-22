#pragma comment(lib, "ws2_32.lib")
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<iostream>
#include<winsock2.h>
#include"rapidjson\stringbuffer.h"
using namespace std;

int main() {
	//winsock startup
	WSADATA wsaData;
	WORD DllVersion = MAKEWORD(2, 1);
	if (WSAStartup(DllVersion, &wsaData) != 0) {
		MessageBoxA(NULL, "winshock startup is fail", "ERROR", MB_OK | MB_ICONERROR);
		exit(1);
	}
	SOCKADDR_IN addr;
	int sizeOfAddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(12345);
	addr.sin_family = AF_INET;

	SOCKET conn = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(conn, (SOCKADDR*)&addr, sizeOfAddr) != 0) {
		MessageBoxA(NULL, "fail to connect", "ERROR", MB_OK | MB_ICONERROR);
		return 0;
	}
	cout << "connected" << endl;
	char mesSend[1000];
	char mesRecv[1000];
	while (true)
	{
		recv(conn, mesRecv, sizeof(mesRecv), NULL);
		cout << mesRecv;
		cin >> mesSend;
		send(conn, mesSend, sizeof(mesSend), NULL);
	}

	system("pause");
	return 0;
}