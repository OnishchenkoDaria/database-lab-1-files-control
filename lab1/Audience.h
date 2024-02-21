#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "StudentList.h"

using namespace std;

struct Audience
{
private:
	int Number{};
	int Floor{};
	string Type;
	string University;
	string Faculty;
	bool Visibility{};
	streampos Students;

public:
	//methods

	Audience() {
		this->Visibility = true;
	}

	Audience(int num, int floor, string type, string uni, string faculty, bool visib, streampos pos) {
		this->setNumber(num);
		this->setFloor(floor);
		this->setType(type);
		this->setUniversity(uni);
		this->setFaculty(faculty);
		this->setStudentSubList(pos);
		this->Visibility = visib;
	}

	void creteObj() {
		cout << "Insert AUDIENCE number:   ";
		cin >> this->Number;
		cout << "Insert AUDIENCE floor:   ";
		cin >> this->Floor;
		cout << "Insert AUDIENCE type:   ";
		cin >> this->Type;
		cout << "Insert AUDIENCE location University:   ";
		cin >> this->University;
		cout << "Insert AUDIENCE location Faculty:   ";
		cin >> this->Faculty;
		this->Visibility = true;
		this->Students = -1;
	}
	
	bool getVisibility() {
		return this->Visibility;
	}

	void setNumber(int number);

	int getNumber();

	void setFloor(int floor);

	int getFloor();

	void setType(string type);

	string getType();

	void setUniversity(string univ);

	string getUniversity();

	void setFaculty(string faculty);

	string getFaculty();

	void changeVisibility();

	void setStudentSubList(streampos head);

	streampos getStudentSubList();

	void showObject();
};