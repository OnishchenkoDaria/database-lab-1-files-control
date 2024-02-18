#pragma once
#include "Student.h"
#include "StudentNode.h"
#include <iostream>
#include <string>

using namespace std;
class StudentList
{
private:
	StudentNode* head;
public:
	//methods
	StudentList() {
		head = NULL;
	}

	StudentNode* getHeadLink();

	void AddItemStudentList(const Student &stud);

	void showList();
};
