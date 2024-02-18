#pragma once
#include "Student.h"

using namespace std;
class StudentNode
{
private:
	//int id, string name, string birthdate, char gender, string group, int 
	Student item;
	StudentNode* Next;
public:
	//methods

	StudentNode(const Student& obj) {
		this->item = obj;
		this->Next = NULL;
	}

	void setStudentData(Student stud);

	Student getStudentData();

	void setNextStudent(StudentNode* stud);

	StudentNode* getNextStudent();
};