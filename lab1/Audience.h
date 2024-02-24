#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

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
	int StudentCount;

public:
	//methods

	Audience() {
		this->Visibility = true;
		this->StudentCount = 0;
	}

	Audience(int num, int floor, string type, string uni, string faculty, bool visib, streampos pos, int count) {
		this->setNumber(num);
		this->setFloor(floor);
		this->setType(type);
		this->setUniversity(uni);
		this->setFaculty(faculty);
		this->setStudentSubList(pos);
		this->setVisibility(visib);
		this->setStudentCount(count);
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

	void setVisibility(bool visib) {
		this->Visibility = visib;
	}

	int getStudentCount() {
		return this->StudentCount;
	}

	void setStudentCount(int count) {
		this->StudentCount = count;
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

	void setStudentSubList(streampos head);

	streampos getStudentSubList();

	void changeVisibility();

	void showObject();

	string TransformObjDataToLine() {
		ostringstream oss;

		oss << this->getNumber() 
			<< " " << this->getFloor()
			<< " " << this->getType()
			<< " " << this->getUniversity()
			<< " " << this->getFaculty()
			<< " " << this->getVisibility()
			<< " " << this->getStudentSubList()
			<< " " << this->getStudentCount();

		return oss.str();
	}
};