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

	void createStudentObj();
};