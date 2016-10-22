#include "View.h"
#include<iostream>
using namespace std;

int View::showMenu()
{
	int choice;
	cout << "==== Welcome To Student Manager ====" << endl;
	cout << "1.show all student" << endl;
	cout << "2.add 1 student" << endl;
	cout << "3.edit 1 student" << endl;
	cout << "4.delete 1 student" << endl;
	cout << "5.search" << endl;
	cout << "6.statistical" << endl;
	cout << "Your choice is ....";
	cin >> choice;
	return choice;
}

Student View::showAdd()
{
	Student st;
	int a;
	string b, c, d;
	float e, f, g;
	cout << "ID: ";
	cin >> a; st.setID(a);
	cout << "Name: ";
	cin.ignore();
	getline(cin, b); st.setName(b);

	cout << "Address: ";
	fflush(stdin);
	getline(cin, c); st.setAddress(c);

	cout << "Sex: ";
	fflush(stdin);
	getline(cin, d); st.setSex(d);

	cout << "Math: ";
	cin >> e;
	while (e < 0 || e > 10) {
		cout << "Diem toan ko hop le, nhap lai: ";
		cin >> e;
	}
	st.setMath(e);

	cout << "Phys: ";
	cin >> f;
	while (f < 0 || f > 10) {
		cout << "Diem ly ko hop le, nhap lai: ";
		cin >> f;
	}
	st.setPhys(f);

	cout << "Chem: ";
	cin >> g;
	while (g < 0 || g > 10) {
		cout << "Diem hoa ko hop le, nhap lai: ";
		cin >> g;
	}
	st.setChem(g);
	return st;
}

int View::showSearch()
{
	cout << "1.search via ID" << endl;
	cout << "2.search via name" << endl;
	cout << "3.search via sum" << endl;
	cout << "4.search via math" << endl;
	cout << "5.search via phys" << endl;
	cout << "6.search via chem" << endl;
	cout << "your choice is...";
	int choice;
	cin >> choice;
	return choice;
}

void View::showList(list<Student> list2)
{
	list<Student>::iterator it;
	for (it = list2.begin(); it != list2.end(); it++) {
		cout << (*it).getID() << " " << (*it).getName() << " " << (*it).getAddress() << " " << (*it).getSex() << " ";
		cout << (*it).getMath() << " " << (*it).getPhys() << " " << (*it).getChem() << endl;
	}
}

int View::showSearchFrm()
{
	cout << "Enter ID: ";
	int id;
	cin >> id;
	return id;
}

Student View::showEdit(Student st)
{
	cout << "Student: " << endl;
	cout << "ID: " << st.getID();
	cout << "\nName: " << st.getName();
	cout << "\nAddress: " << st.getAddress();
	cout << "\nSex: " << st.getSex();
	cout << "\nMath: " << st.getMath();
	cout << "\nPhys: " << st.getPhys();
	cout << "\nChem: " << st.getChem();
	cout << "\ndo you want edit...";
	char c;
	cin >> c;
	if (c == 'y' || c == 'Y') {
		cout << "New infor: " << endl;
		return showAdd();
	}
}

int View::showDel(Student st)
{
	cout << "Student: " << endl;
	cout << "ID: " << st.getID();
	cout << "\nName: " << st.getName();
	cout << "\nAddress: " << st.getAddress();
	cout << "\nSex: " << st.getSex();
	cout << "\nMath: " << st.getMath();
	cout << "\nPhys: " << st.getPhys();
	cout << "\nChem: " << st.getChem();
	cout << "\ndo you want delete...";
	char c;
	cin >> c;
	if (c == 'y' || c == 'Y') {
		return 1;
	}
	return 0;
}

void View::statistical(int n, int a, int b, int c, int d)
{
	cout << "Co tong so " << n << " sinh vien trong do co: " << endl;
	cout << a << " sinh vien co diem < 15" << endl;
	cout << b << " sinh vien co diem tu 15 den 20" << endl;
	cout << c << " sinh vien co diem tu 20 den 25" << endl;
	cout << d << " sinh vien co diem > 25" << endl;
}

int View::showSortMenu()
{
	int choice;
	cout << "Sort by:" << endl;
	cout << "1.ID\n2.Name\n3.Sum\n";
	cin >> choice;
	return choice;
}

View::View()
{
}


View::~View()
{
}