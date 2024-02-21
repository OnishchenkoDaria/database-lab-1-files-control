#include "StudentNode.h"

void StudentNode::setStudentData(Student stud) {
	this->item = stud;
}

Student StudentNode::getStudentData() {
	return this->item;
}

void StudentNode::setNextStudent(streampos stud) {
	this->Next = stud;
}

streampos StudentNode::getNextStudent() {
	return this->Next;
}