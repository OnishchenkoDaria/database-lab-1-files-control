#pragma once
#include <iostream>
#include <string>

using namespace std;
class Student
{
private:
	int StudentId{};
	string FullName;
	int BirthDate{};
	char Gender{};
	string GroupName;
	int Audience{};
	bool Visibility{};

public:
	//methods

	Student() {
		cout << "Insert STUDENT'S id card number:  ";
		cin >> this->StudentId;
		cout << "Insert STUDENT'S Fullname:  ";
		cin >> this->FullName;
		cout << "Insert STUDENT'S birth date:  ";
		cin >> this->BirthDate;
		cout << "Insert STUDENT'S gender:  ";
		cin >> this->Gender;
		cout << "Insert STUDENT'S group:  ";
		cin >> this->GroupName;
		cout << "Insert STUDENT'S audience number:  ";
		cin >> this->Audience;
		this->Visibility = true;
	}

	void setId(int id);

	int getId();

	void setName(string name);

	string getName();

	void setDate(int date);

	int getDate();

	void setGender(char gender);

	char getGender();

	void setGroup(string group);

	string getGroup();

	void setAudience(int aud);

	int getAudience();

	void changeVisibility();

	//void createStudentObj();
};