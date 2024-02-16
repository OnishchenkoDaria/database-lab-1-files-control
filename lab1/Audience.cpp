#include "Audience.h"

void Audience::setNumber(int number) {
	this->Number = number;
}

int Audience::getNumber() {
	return this->Number;
}

void Audience::setFloor(int floor) {
	this->Floor = floor;
}

int Audience::getFloor() {
	return this->Floor;
}

void Audience::setType(string type) {
	this->Type = type;
}

string Audience::getType() {
	return this->Type;
}

void Audience::setUniversity(string univ) {
	this->University = univ;
}

string Audience::getUniversity() {
	return this->University;
}

void Audience::setFaculty(string faculty) {
	this->Faculty = faculty;
}

string Audience::getFaculty() {
	return this->Faculty;
}

void Audience::changeVisibility() {
	if (this->Visibility == false) {
		this->Visibility = true;
	}
	else {
		this->Visibility = false;
	}
}

void Audience::createAudienceObj() {
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
}