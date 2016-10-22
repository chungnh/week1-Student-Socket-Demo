#include "Student.h"

void Student::setID(int x)
{
	id = x;
}

int Student::getID()
{
	return id;
}

void Student::setName(string x)
{
	name = x;
}

string Student::getName()
{
	return name;
}

void Student::setAddress(string x)
{
	address = x;
}

string Student::getAddress()
{
	return address;
}

void Student::setSex(string x)
{
	sex = x;
}

string Student::getSex()
{
	return sex;
}

void Student::setMath(float x)
{
	math = x;
}

float Student::getMath()
{
	return math;
}

void Student::setPhys(float x)
{
	phys = x;
}

float Student::getPhys()
{
	return phys;
}

void Student::setChem(float x)
{
	chem = x;
}

float Student::getChem()
{
	return chem;
}

Student::Student()
{
}

Student::Student(int id1, string name1, string address1, string sex1, float m1, float p1, float c1)
{
	id = id1;
	name = name1;
	address = address1;
	sex = sex1;
	math = m1;
	phys = p1;
	chem = c1;
}


Student::~Student()
{
}