#include "Student.h"

void Student::setId(int id) {
	this->StudentId = id;
}

int Student::getId() {
	return this->StudentId;
}

void Student::setName(string name) {
	this->Name = name;
}

string Student::getName() {
	return this->Name;
}

void Student::setDate(string date){
	this->BirthDate = date;
}

string Student::getDate() {
	return this->BirthDate;
}

void Student::setGender(char gender) {
	this->Gender = gender;
}

char Student::getGender() {
	return this->Gender;
}

void Student::setGroup(string group) {
	this->GroupName = group;
}

string Student::getGroup() {
	return this->GroupName;
}

void Student::setAudience(int aud) {
	this->Audience = aud;
}

int Student::getAudience() {
	return this->Audience;
}

void Student::changeVisibility() {
	if (this->Visibility == false) {
		this->Visibility = true;
	}
	else {
		this->Visibility = false;
	}
}

bool Student::getVisibility() {
	return this->Visibility;
}

void Student::createObj() {
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

void Student::showObject() {
	cout << " ID: " << this->getId()
		<< " Name: " << this->getName()
		<< " Birth Date: " << this->getDate()
		<< " Gender: " << this->getGender()
		<< " Group: " << this->getGroup()
		<< " Audience: " << this->getAudience()
		<< " Visibility: " << this->Visibility << endl;
}