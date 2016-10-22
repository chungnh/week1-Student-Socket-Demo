#pragma once
#include"Student.h"
#include "DAO.h"
#include<iostream>
class StudentCtr
{
public:
	bool checkID(int);
	bool checkName(string);
	bool checkSum(float);
	bool add(Student);
	string showAll();
	StudentCtr();
	Student searchID(int);
	string searchName(string);
	string searchSum(float);
	void searchMath();
	void searchPhys();
	void searchChem();
	bool edit(int, Student);
	bool del(int);
	string thongke();
	void swap(Student, Student);
	void sort(list<Student>);
	string Convert2(int);
	~StudentCtr();
};
