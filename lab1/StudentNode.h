#pragma once
#include "Student.h"

using namespace std;
struct StudentNode
{
private:
	//int id, string name, string birthdate, char gender, string group, int 
	Student item;
	streampos Next;
public:
	//methods

	StudentNode() {
		this->Next = -1;
		this->getStudentData().setId(-1);
	}

	StudentNode(const Student& obj) {
		this->item = obj;
		this->Next = -1;
	}

	StudentNode(const Student& obj, streampos next) {
		this->item = obj;
		this->Next = next;
	}

	void showObj() {
		this->item.showObject();
		cout << " NEXT NODE: " << this->getNextStudent() << endl;
	}

	void userData() {
		cout << " Student Id: " << this->getStudentData().getId() << " | "
			<< " Name: " << this->getStudentData().getName() << " | "
			<< " BirthDate: " << this->getStudentData().getDate() << " | "
			<< " Gender: " << this->getStudentData().getGender() << " | "
			<< " Group: " << this->getStudentData().getGroup() << " | "
			<< " Audience: " << this->getStudentData().getAudience() << endl;
	}
	
	void setStudentData(Student stud);

	Student getStudentData();

	void setNextStudent(streampos stud);

	streampos getNextStudent();
};