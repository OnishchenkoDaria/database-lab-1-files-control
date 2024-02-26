#pragma once
#include <sstream>
#include <iostream>
#include "indexNode.h"
using namespace std;

using namespace std;
struct StudentNode
{
private:
	//int id, string name, string birthdate, char gender, string group, int 
	int StudentId{};
	string Name;
	string BirthDate{};
	char Gender{};
	string GroupName;
	int Audience{};
	bool Visibility{};
	streampos Next;
public:
	//methods

	StudentNode() {
		this->Next = -1;
		this->StudentId = -1;
	}

	StudentNode(int id, string name, string date, char gender, string group, int audience, bool visib) {
		this->setId(id);
		this->setName(name);
		this->setDate(date);
		this->setGender(gender);
		this->setGroup(group);
		this->setAudience(audience);
		this->setVisibility(visib);
		this->Next = -1;
	}

	StudentNode(int id, string name, string date, char gender, string group, int audience, bool visib, streampos next) {
		this->setId(id);
		this->setName(name);
		this->setDate(date);
		this->setGender(gender);
		this->setGroup(group);
		this->setAudience(audience);
		this->setVisibility(visib);
		this->Next = next;
	}

	void userData();

	string TransformObjDataToLine();

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

	void setNextStudent(streampos stud);

	streampos getNextStudent();

	void setNext(streampos next);
	
	void createObj(indexNode* head);
};