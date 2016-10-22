#pragma once
#include"Student.h"
#include<List>
class View
{
public:
	int showMenu();
	Student showAdd();
	int showSearch();
	void showList(list<Student>);
	int showSearchFrm();
	Student showEdit(Student);
	int showDel(Student);
	void statistical(int, int, int, int, int);
	int showSortMenu();
	View();
	~View();
};
