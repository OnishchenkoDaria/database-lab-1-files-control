#include "Student.h"

void Student::setId(int id) {
	this->StudentId = id;
}

int Student::getId() {
	return this->StudentId;
}

void Student::setName(string name) {
	this->FullName = name;
}

string Student::getName() {
	return this->FullName;
}

void Student::setDate(int date){
	this->BirthDate = date;
}

int Student::getDate() {
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

void Student::createStudentObj() {
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
	// go to the index table and find the right (adress) number of audience
	// choose the sudience and add the student to the list (slave) by adding to tail and make this object a new tail
}