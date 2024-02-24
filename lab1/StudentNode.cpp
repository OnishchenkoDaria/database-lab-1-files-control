#include "StudentNode.h"

/*void StudentNode::setStudentData(Student stud) {
	this->item = stud;
}

/*Student StudentNode::getStudentData() {
	return this->item;
}*/

void StudentNode::setNextStudent(streampos stud) {
	this->Next = stud;
}

streampos StudentNode::getNextStudent() {
	return this->Next;
}
void StudentNode::setId(int id) {
	this->StudentId = id;
}

int StudentNode::getId() {
	return this->StudentId;
}

void StudentNode::setName(string name) {
	this->Name = name;
}

string StudentNode::getName() {
	return this->Name;
}

void StudentNode::setDate(string date) {
	this->BirthDate = date;
}

string StudentNode::getDate() {
	return this->BirthDate;
}

void StudentNode::setGender(char gender) {
	this->Gender = gender;
}

char StudentNode::getGender() {
	return this->Gender;
}

void StudentNode::setGroup(string group) {
	this->GroupName = group;
}

string StudentNode::getGroup() {
	return this->GroupName;
}

void StudentNode::setAudience(int aud) {
	this->Audience = aud;
}

int StudentNode::getAudience() {
	return this->Audience;
}

void StudentNode::changeVisibility() {
	if (this->Visibility == false) {
		this->Visibility = true;
	}
	else {
		this->Visibility = false;
	}
}

bool StudentNode::getVisibility() {
	return this->Visibility;
}

void StudentNode::setVisibility(bool visib) {
	this->Visibility = visib;
}

void StudentNode::setNext(streampos next) {
	this->Next = next;
}

void StudentNode::createObj() {
	cout << "Insert STUDENT'S id card number:  ";
	cin >> this->StudentId;
	cout << "Insert STUDENT'S Name:  ";
	cin >> this->Name;
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