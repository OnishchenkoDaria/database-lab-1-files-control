#include "StudentNode.h"

void StudentNode::setStudentData(Student stud) {
	this->item = stud;
}

Student StudentNode::getStudentData() {
	return this->item;
}

void StudentNode::setNextStudent(StudentNode* stud) {
	this->Next = stud;
}

StudentNode* StudentNode::getNextStudent() {
	return this->Next;
}