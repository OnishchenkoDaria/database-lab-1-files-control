#include "StudentList.h"
#include <fstream>

StudentNode* StudentList::getHeadLink() {
	return this->head;
}

/*void StudentList::AddItemStudentList(const Student& stud) {
	StudentNode* temp = new StudentNode(stud);
	temp->setNextStudent(head);
	head = temp;

	//add if head == NULL ---> audiense set students (head)
}*/

/*void StudentList::showList() {
	StudentNode* temp = head;
	cout << "LINKED LIST: " << endl;
	while (temp != NULL) {
		temp->getStudentData().showObject();
		temp = temp->getNextStudent();
	}
}*/