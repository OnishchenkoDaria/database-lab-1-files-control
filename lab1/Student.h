#pragma once
#include <iostream>
#include <string>

using namespace std;
struct Student
{
private:
	int StudentId{};
	string Name;
	string BirthDate{};
	char Gender{};
	string GroupName;
	int Audience{};
	bool Visibility{};

public:
	//methods

	Student() {
		this->Visibility = true;
		this->Audience = NULL;
	}

	Student(int id, string name, string birthdate, char gender, string group, int aud) {
		this->setId(id);
		this->setDate(birthdate);
		this->setGender(gender);
		this->setGroup(group);
		this->setAudience(aud);
		this->Visibility = true;
	}

	Student(int id, string name, string birthdate, char gender, string group, int aud, bool visib) {
		this->setId(id);
		this->setName(name);
		this->setDate(birthdate);
		this->setGender(gender);
		this->setGroup(group);
		this->setAudience(aud);
		this->setVisibility(visib);
	}

	void setId(int id);

	int getId();

	void setName(string name);

	string getName();

	void setDate(string date);

	string getDate();

	void setGender(char gender);

	char getGender();

	void setGroup(string group);

	string getGroup();

	void setAudience(int aud);

	int getAudience();

	void changeVisibility();

	void setVisibility(bool visib);

	bool getVisibility();

	void showObject();

	void createObj();
};