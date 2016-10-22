#pragma comment(lib, "ws2_32.lib")
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "Student.h"
#include "View.h"
#include "StudentCtr.h"
#include "DAO.h"
#include <list>
#include <string>
#include<iostream>
#include<sstream>
#include<winsock.h>
using namespace std;

std::string Convert(float number) {
	std::ostringstream buff;
	buff << number;
	return buff.str();
}

std::string Convert2(int number) {
	std::ostringstream buff;
	buff << number;
	return buff.str();
}

int main() {
	StudentCtr sc;

	//winsock startup
	WSADATA wsaData;
	WORD DllVersion = MAKEWORD(2, 1);
	if (WSAStartup(DllVersion, &wsaData) != 0) {
		MessageBoxA(NULL, "winshock startup is fail", "ERROR", MB_OK | MB_ICONERROR);
		exit(1);
	}
	SOCKADDR_IN addr;
	int addrLen = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(12345);
	addr.sin_family = AF_INET;

	//listen
	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
	listen(sListen, SOMAXCONN);
	cout << "wating for connect" << endl;
	//creat connect
	SOCKET newConn;
	newConn = accept(sListen, (SOCKADDR*)&addr, &addrLen);

	if (newConn == 0) {
		cout << "fail to accept" << endl;
	}
	else {
		cout << "connected" << endl;
	} 

	char success[1000] = "success";
	char fail[1000] = "fail";
	char notfound[1000] = "not found. enter 'OK': ";
	char exist[1000] = "ID is exist. enter 'OK': ";
	char welcome[1000] = "==== Welcome To Student Manager ====\n1.show all student\n2.add 1 student\n3.edit 1 student\n4.delete 1 student\n5.search \n6.statistical\nYour choice is ....";
	char mesSend[1000];
	char mesRecv[1000];
	send(newConn, welcome, sizeof(welcome), NULL);
	while (true)
	{			
		recv(newConn, mesRecv, sizeof(mesRecv), NULL);
		string x(mesRecv);
		cout << "Receviced: " << x <<  endl;
		if (x == "1") {//show all
			string x = sc.showAll() + "Enter 'OK': ";
			const char* y = x.c_str();
			send(newConn, y, sizeof(welcome), NULL);
			recv(newConn, mesRecv, sizeof(welcome), NULL);
			string x2(mesRecv);
			if (x2 == "OK" || x2 == "ok") {
				send(newConn, welcome, sizeof(welcome), NULL);
			}
		}
		if (x == "2") {//add
			char id[1000], name[1000], sex[1000], addr[1000], math[1000], phys[1000], chem[1000];
			char a[1000] = "ADD a Student.\nEnter Student Infor.\nID: ";
			char b[1000] = "Name: ";
			char c[1000] = "Addr: ";
			char d[1000] = "Gender: ";
			char e[1000] = "Math: ";
			char f[1000] = "Phys: ";
			char g[1000] = "Chem: ";
			
			send(newConn, a, sizeof(welcome), NULL);
			recv(newConn, id, sizeof(mesRecv), NULL);

			send(newConn, b, sizeof(welcome), NULL);
			recv(newConn, name, sizeof(mesRecv), NULL);

			send(newConn, c, sizeof(welcome), NULL);
			recv(newConn, addr, sizeof(mesRecv), NULL);

			send(newConn, d, sizeof(welcome), NULL);
			recv(newConn, sex, sizeof(mesRecv), NULL);

			send(newConn, e, sizeof(welcome), NULL);
			recv(newConn, math, sizeof(mesRecv), NULL);

			send(newConn, f, sizeof(welcome), NULL);
			recv(newConn, phys, sizeof(mesRecv), NULL);

			send(newConn, g, sizeof(welcome), NULL);
			recv(newConn, chem, sizeof(mesRecv), NULL);
			string name1(name);
			string addr1(addr);
			string sex1(sex);
			float math1 = stof(math);
			float phys1 = stof(phys);
			float chem1 = stof(chem);
			int id1 = stoi(id);
			Student st = Student(id1, name1, addr1, sex1, math1, phys1, chem1);
			if (sc.checkID(id1)) {
				send(newConn, exist, sizeof(welcome), NULL);
				recv(newConn, mesRecv, sizeof(welcome), NULL);
				string mesRecv2(mesRecv);
				if (mesRecv2 == "ok") {
					send(newConn, welcome, sizeof(welcome), NULL);
				}
				else {
					send(newConn, welcome, sizeof(welcome), NULL);
				}
			}
			else {
				if (sc.add(st) == true) {
					send(newConn, welcome, sizeof(success), NULL);
				}
				else {
					send(newConn, welcome, sizeof(fail), NULL);
				}
			}
		}
		if (x == "3") {//edit
			char id[1000], name[1000], sex[1000], addr[1000], math[1000], phys[1000], chem[1000];
			char a1[1000] = "EDIT a Student.\nEnter ID: ";

			send(newConn, a1, sizeof(welcome), NULL);
			recv(newConn, id, sizeof(mesRecv), NULL);

			int id2 = stoi(id);
			if (!sc.checkID(id2)) {
				send(newConn, notfound, sizeof(welcome), NULL);
				recv(newConn, mesRecv, sizeof(welcome), NULL);
				string mesRecv1(mesRecv);
				if (mesRecv1 == "ok") {
					send(newConn, welcome, sizeof(welcome), NULL);
				}
				else {
					send(newConn, welcome, sizeof(welcome), NULL);
				}
			}
			else {
				Student st = sc.searchID(id2);

				string send1 = "ID: " + Convert2(st.getID()) + "\nName: " + st.getName() + "\nAddr: " + st.getAddress() + "\nSex: " + st.getSex() + "\nMath: " + Convert(st.getMath()) + "\nPhys: " + Convert(st.getPhys()) + "\nChem: " + Convert(st.getChem()) + "\nDo you want to EDIT: ";
				cout << send;
				const char* send2 = send1.c_str();

				char x[1000];
				send(newConn, send2, sizeof(welcome), NULL);
				recv(newConn, x, sizeof(mesRecv), NULL);
				string x1(x);
				if (x1 == "y" || x1 == "Y") {
					char id[1000], name[1000], sex[1000], addr[1000], math[1000], phys[1000], chem[1000];
					char a[1000] = "Enter new Student Infor.\nID: ";
					char b[1000] = "Name: ";
					char c[1000] = "Addr: ";
					char d[1000] = "Gender: ";
					char e[1000] = "Math: ";
					char f[1000] = "Phys: ";
					char g[1000] = "Chem: ";

					send(newConn, a, sizeof(welcome), NULL);
					recv(newConn, id, sizeof(mesRecv), NULL);

					send(newConn, b, sizeof(welcome), NULL);
					recv(newConn, name, sizeof(mesRecv), NULL);

					send(newConn, c, sizeof(welcome), NULL);
					recv(newConn, addr, sizeof(mesRecv), NULL);

					send(newConn, d, sizeof(welcome), NULL);
					recv(newConn, sex, sizeof(mesRecv), NULL);

					send(newConn, e, sizeof(welcome), NULL);
					recv(newConn, math, sizeof(mesRecv), NULL);

					send(newConn, f, sizeof(welcome), NULL);
					recv(newConn, phys, sizeof(mesRecv), NULL);

					send(newConn, g, sizeof(welcome), NULL);
					recv(newConn, chem, sizeof(mesRecv), NULL);
					string name1(name);
					string addr1(addr);
					string sex1(sex);
					float math1 = stof(math);
					float phys1 = stof(phys);
					float chem1 = stof(chem);
					int id3 = stoi(id);
					Student st = Student(id3, name1, addr1, sex1, math1, phys1, chem1);
					if (sc.edit(id2, st) == true) {
						send(newConn, welcome, sizeof(success), NULL);
					}
					else {
						send(newConn, welcome, sizeof(fail), NULL);
					}
				}
			}
		}
		if (x == "4") {
			char a1[1000] = "DELETE a Student.\nEnter ID: ";
			char id[1000];
			send(newConn, a1, sizeof(welcome), NULL);
			recv(newConn, id, sizeof(mesRecv), NULL);
			int id4 = stoi(id);
			if (!sc.checkID(id4)) {
				send(newConn, notfound, sizeof(welcome), NULL);
				recv(newConn, mesRecv, sizeof(welcome), NULL);
				string mesRecv2(mesRecv);
				if (mesRecv2 == "ok") {
					send(newConn, welcome, sizeof(welcome), NULL);
				}
				else {
					send(newConn, welcome, sizeof(welcome), NULL);
				}
			}
			else {
				Student st = sc.searchID(id4);
				string send1 = "ID: " + Convert2(st.getID()) + "\nName: " + st.getName() + "\nAddr: " + st.getAddress() + "\nSex: " + st.getSex() + "\nMath: " + Convert(st.getMath()) + "\nPhys: " + Convert(st.getPhys()) + "\nChem: " + Convert(st.getChem()) + "\nDo you want to DELETE: ";
				cout << send;
				const char* send2 = send1.c_str();
				char x[1000];
				send(newConn, send2, sizeof(welcome), NULL);
				recv(newConn, x, sizeof(mesRecv), NULL);
				string x1(x);
				if (x1 == "y" || x1 == "Y") {
					if (sc.del(id4)) {
						send(newConn, welcome, sizeof(success), NULL);
					}
					else {
						send(newConn, welcome, sizeof(fail), NULL);
					}
				}
			}
		}
		if (x == "5") {
			char menuChoice[1000] = "1.Search via ID\n2.Search via Name\n3.Search via Sum\nYour choice:  ";
			send(newConn, menuChoice, sizeof(welcome), NULL);
			char choice[1000];
			recv(newConn, choice, 1000, NULL);
			string choice1(choice);
			if (choice1 == "1") {//search by ID
				char sID[1000] = "Enter ID: ";
				send(newConn, sID, 1000, NULL);
				char id[1000];
				recv(newConn, id, 1000, NULL);
				int id1 = stoi(id);
				Student st = sc.searchID(id1);
				string send1 = "ID: " + Convert2(st.getID()) + "\nName: " + st.getName() + "\nAddr: " + st.getAddress() + "\nSex: " + st.getSex() + "\nMath: " + Convert(st.getMath()) + "\nPhys: " + Convert(st.getPhys()) + "\nChem: " + Convert(st.getChem()) + "\nEnter 'OK': ";
				const char* send2 = send1.c_str();
				send(newConn, send2, sizeof(welcome), NULL);
				char x3[1000];
				recv(newConn, x3, sizeof(welcome), NULL);
				string x2(x3);
				if (x2 == "OK" || x2 == "ok") {
					send(newConn, welcome, sizeof(welcome), NULL);
				}
				else {
					send(newConn, welcome, sizeof(welcome), NULL);
				}
			}
			if (choice == "2") {//search by Name

			}
			if (choice == "3") {//search by Sum

			}
		}
		if (x == "6") {
			string s = sc.thongke();
			const char* s2 = s.c_str();
			send(newConn, s2, sizeof(welcome), NULL);
			recv(newConn, mesRecv, sizeof(welcome), NULL);
			string x2(mesRecv);
			if (x2 == "OK" || x2 == "ok") {
				send(newConn, welcome, sizeof(welcome), NULL);
			}
		}
	}
	return 0;
}