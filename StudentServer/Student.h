#pragma once
#include<string>
using namespace std;
class Student
{
private:
	int id;
	string name;
	string address;
	string sex;
	float math;
	float phys;
	float chem;
public:
	void setID(int);
	int getID();
	void setName(string);
	string getName();
	void setAddress(string);
	string getAddress();
	void setSex(string);
	string getSex();
	void setMath(float);
	float getMath();
	void setPhys(float);
	float getPhys();
	void setChem(float);
	float getChem();
	//float getTong();
	Student();
	Student(int, string, string, string, float, float, float);
	~Student();
};
