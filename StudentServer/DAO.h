#pragma once
#pragma once
#include<fstream>
#include "Student.h"
#include <list>
#include <iostream>
class DAO
{
public:
	bool writeFile(Student, string);
	string readFile(string);
	list<Student> readList(string);
	DAO();
	~DAO();
};
