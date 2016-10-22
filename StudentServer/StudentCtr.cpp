#include "StudentCtr.h"
#include"DAO.h"
#include"View.h"
#include<list>
#include"rapidjson\stringbuffer.h"
#include<sstream>
using namespace std;

string StudentCtr::Convert2(int number) {
	std::ostringstream buff;
	buff << number;
	return buff.str();
}

bool StudentCtr::checkID(int id)
{
	DAO dao;
	list<Student> list2 = dao.readList("output.txt");
	list<Student>::iterator it;
	for (it = list2.begin(); it != list2.end(); it++) {
		if ((*it).getID() == id) {
			return true;
		}
	}
	return false;
}

bool StudentCtr::checkName(string name)
{
	DAO dao;
	list<Student> list2 = dao.readList("output.txt");
	list<Student>::iterator it;
	for (it = list2.begin(); it != list2.end(); it++) {
		if ((*it).getName() == name) {
			return true;
		}
	}
	return false;
}

bool StudentCtr::checkSum(float sum)
{
	DAO dao;
	list<Student> list2 = dao.readList("output.txt");
	list<Student>::iterator it;
	for (it = list2.begin(); it != list2.end(); it++) {
		float sum1 = (*it).getMath() + (*it).getPhys() + (*it).getChem();
		if (sum1 == sum) {
			return true;
		}
	}
	return false;
}

bool StudentCtr::add(Student st)
{
	DAO dao;
	if (checkID(st.getID())) {
		cout << "student is esixt hihi" << endl;
	}
	else {
		if (dao.writeFile(st, "output.txt")) {
			return true;
		}
		return false;
	}
}

string StudentCtr::showAll()
{
	DAO dao;
	string result = dao.readFile("output.txt");
	return result;
}

StudentCtr::StudentCtr()
{
}

struct CompareBy
{//tham khao cua hoang
	const string SORT_FIELD;
	CompareBy(const string& sort_field = "name") :SORT_FIELD(sort_field)
	{
		/* validate sort_field */
	}

	bool operator()(Student& st1, Student& st2)
	{
		if (SORT_FIELD == "name")
			return st1.getName() < st2.getName();
		else if (SORT_FIELD == "sum")
			return st1.getMath() + st1.getPhys() + st1.getChem() < st2.getMath() + st2.getPhys() + st2.getChem();
		else if (SORT_FIELD == "id")
			return st1.getID() < st2.getID();
	}
};

void StudentCtr::sort(list<Student> list1)
{
	View v;
	switch (v.showSortMenu())
	{
	case 1: {//sort by id
		list1.sort(CompareBy("id"));
		v.showList(list1);
		break;
	}
	case 2: {//sort by name
		list1.sort(CompareBy("name"));
		v.showList(list1);
		break;
	}
	case 3: {//sort by sum
		list1.sort(CompareBy("sum"));
		v.showList(list1);
		break;
	}
	default:
		break;
	}
}

Student StudentCtr::searchID(int id)
{
	list<Student> list2;
	list<Student>::iterator it;
	Student st;
	DAO dao;
	list2 = dao.readList("output.txt");
	if (list2.empty()) cout << "empty" << endl;
	else {
		int k = 0;
		for (it = list2.begin(); it != list2.end(); it++) {
			if ((*it).getID() == id) {
				k = 1;
				st.setID((*it).getID());
				st.setName((*it).getName());
				st.setAddress((*it).getAddress());
				st.setSex((*it).getSex());
				st.setMath((*it).getMath());
				st.setPhys((*it).getPhys());
				st.setChem((*it).getChem());
			}
		}
		if (k == 0) cout << "not found" << endl;
		else
			return st;
	}
}

string StudentCtr::searchName(string name)
{
	list<Student> list2;
	list<Student>::iterator it;
	Student st = Student();
	DAO dao;
	list2 = dao.readList("output.txt");
	if (list2.empty()) cout << "empty" << endl;
	else {
		int k = 0;
		for (it = list2.begin(); it != list2.end(); it++) {
			if ((*it).getName() == name) {
				k = 1;
				st.setID((*it).getID());
				st.setName((*it).getName());
				st.setAddress((*it).getAddress());
				st.setSex((*it).getSex());
				st.setMath((*it).getMath());
				st.setPhys((*it).getPhys());
				st.setChem((*it).getChem());
				Student st = Student((*it).getID(), (*it).getName(), (*it).getAddress(), (*it).getSex(), (*it).getMath(), (*it).getPhys(), (*it).getChem());
				dao.writeFile(st, "search.txt");
				
			}
		}
		if (k == 0) cout << "not found" << endl;
	}
	string result = dao.readFile("search.txt");
	remove("search.txt");
	return result;
}

string StudentCtr::searchSum(float sum)
{
	list<Student> list2;
	list<Student>::iterator it;
	Student st;
	DAO dao;
	list2 = dao.readList("output.txt");
	if (list2.empty()) cout << "empty" << endl;
	else {
		int k = 0;
		for (it = list2.begin(); it != list2.end(); it++) {
			float Sum = (*it).getMath() + (*it).getPhys() + (*it).getChem();
			if (Sum == sum) {
				k = 1;
				st.setID((*it).getID());
				st.setName((*it).getName());
				st.setAddress((*it).getAddress());
				st.setSex((*it).getSex());
				st.setMath((*it).getMath());
				st.setPhys((*it).getPhys());
				st.setChem((*it).getChem());
				dao.writeFile(st, "search.txt");
			}
		}
		if (k == 0) cout << "not found" << endl;
	}
	string result = dao.readFile("search.txt");
	remove("search.txt");
	return result;
}

void StudentCtr::searchMath()
{
	list<Student> list2, result;
	list<Student>::iterator it;
	Student st;
	DAO dao;
	list2 = dao.readList("output.txt");
	system("cls");
	if (list2.empty()) cout << "empty" << endl;
	else {
		int m;
		cout << "enter Math: ";
		cin >> m;
		int k = 0;
		for (it = list2.begin(); it != list2.end(); it++) {
			if ((*it).getMath() == m) {
				k = 1;
				st.setID((*it).getID());
				st.setName((*it).getName());
				st.setAddress((*it).getAddress());
				st.setSex((*it).getSex());
				st.setMath((*it).getMath());
				st.setPhys((*it).getPhys());
				st.setChem((*it).getChem());
				result.push_back(st);
			}
		}
		if (k == 0) cout << "not found" << endl;
		else
			sort(result);
	}
}

void StudentCtr::searchPhys()
{
	list<Student> list2, result;
	list<Student>::iterator it;
	Student st;
	DAO dao;
	list2 = dao.readList("output.txt");
	system("cls");
	if (list2.empty()) cout << "empty" << endl;
	else {
		float p;
		cout << "enter Phys: ";
		cin >> p;
		int k = 0;
		for (it = list2.begin(); it != list2.end(); it++) {
			if ((*it).getPhys() == p) {
				k = 1;
				st.setID((*it).getID());
				st.setName((*it).getName());
				st.setAddress((*it).getAddress());
				st.setSex((*it).getSex());
				st.setMath((*it).getMath());
				st.setPhys((*it).getPhys());
				st.setChem((*it).getChem());
				result.push_back(st);
			}
		}
		if (k == 0) cout << "not found" << endl;
		else
			sort(result);
	}
}

void StudentCtr::searchChem()
{
	list<Student> list2, result;
	list<Student>::iterator it;
	Student st;
	DAO dao;
	list2 = dao.readList("output.txt");
	system("cls");
	if (list2.empty()) cout << "empty" << endl;
	else {
		cout << "enter Chem: ";
		float c;
		cin >> c;
		int k = 0;
		for (it = list2.begin(); it != list2.end(); it++) {
			if ((*it).getChem() == c) {
				k = 1;
				st.setID((*it).getID());
				st.setName((*it).getName());
				st.setAddress((*it).getAddress());
				st.setSex((*it).getSex());
				st.setMath((*it).getMath());
				st.setPhys((*it).getPhys());
				st.setChem((*it).getChem());
				result.push_back(st);
			}
		}
		if (k == 0) cout << "not found" << endl;
		else
			sort(result);
	}
}

bool StudentCtr::edit(int id, Student st)
{
	DAO dao;
	list<Student> list2;
	list<Student>::iterator it;
	list2 = dao.readList("output.txt");
	for (it = list2.begin(); it != list2.end(); it++) {
		if ((*it).getID() == id) {
			(*it).setID(st.getID());
			(*it).setName(st.getName());
			(*it).setAddress(st.getSex());
			(*it).setSex(st.getSex());
			(*it).setMath(st.getMath());
			(*it).setPhys(st.getPhys());
			(*it).setChem(st.getChem());
		}
	}
	remove("output.txt");
	for (it = list2.begin(); it != list2.end(); it++) {
		Student st2;
		st2.setID((*it).getID());
		st2.setName((*it).getName());
		st2.setAddress((*it).getAddress());
		st2.setSex((*it).getSex());
		st2.setMath((*it).getMath());
		st2.setPhys((*it).getPhys());
		st2.setChem((*it).getChem());
		dao.writeFile(st2, "output.txt");
	}
	return true;
}

bool StudentCtr::del(int id)
{
	DAO dao;
	list<Student> list2;
	list<Student>::iterator it;
	list2 = dao.readList("output.txt");
	for (it = list2.begin(); it != list2.end(); it++) {
		if ((*it).getID() == id) {
			it = list2.erase(it);
			if (it == list2.end()) break;
		}
		else cout << "not found" << endl;
	}
	remove("output.txt");
	for (it = list2.begin(); it != list2.end(); it++) {
		Student st;
		st.setID((*it).getID());
		st.setName((*it).getName());
		st.setAddress((*it).getAddress());
		st.setSex((*it).getSex());
		st.setMath((*it).getMath());
		st.setPhys((*it).getPhys());
		st.setChem((*it).getChem());
		dao.writeFile(st, "output.txt");
	}
	return true;
}

string StudentCtr::thongke()
{
	int n = 0, a = 0, b = 0, c = 0, d = 0;
	DAO dao;
	list<Student> list2;
	list<Student>::iterator it;
	list2 = dao.readList("output.txt");
	for (it = list2.begin(); it != list2.end(); it++) {
		n++;
		float s = (*it).getMath() + (*it).getPhys() + (*it).getChem();
		if (s < 15) { a++; }
		if (s >= 15 && s < 20) { b++; }
		if (s >= 20 && s < 25) { c++; }
		if (s >= 25) { d++; }
	}
	string s = "Co tong so " + Convert2(n) + " sinh vien trong do co: \n" + Convert2(a) + " sinh vien co diem < 15\n" + Convert2(b) + " sinh vien co diem tu 15 den 20\n" + Convert2(c) + " sinh vien co diem tu 20 den 25\n" + Convert2(d) + " sinh vien co diem > 25\nEnter 'OK': ";
	return s;
}

void StudentCtr::swap(Student st1, Student st2)
{
	Student tem;
	memcpy(&tem, &st1, sizeof(Student));
	memcpy(&st1, &st2, sizeof(Student));
	memcpy(&st2, &tem, sizeof(Student));
}

StudentCtr::~StudentCtr()
{
}