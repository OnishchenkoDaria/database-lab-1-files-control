#include "Audience.h"

void Audience::setStudentCount(int count) {
	this->StudentCount = count;
}

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

void Audience::setStudentSubList(streampos head) {
	this->Students = head;
}

streampos Audience::getStudentSubList() {
	return this->Students;
}

void Audience::showObject() {
	cout << " ID Number: " << this->getNumber() << " | "
		<< " Floor: " << this->getFloor() << " | "
		<< " Type: " << this->getType() << " | "
		<< " University: " << this->getUniversity() << " | "
		<< " Faculty: " << this->getFaculty() << " | "
		<< " Visibility: " << this->getVisibility() << " | "
		<< " List LINK: " << this->getStudentSubList() << " | "
		<< " StudCount: " << this->getStudentCount() << endl;
}

string Audience::TransformObjDataToLine() {
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