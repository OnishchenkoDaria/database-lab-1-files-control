#include "Functions.h"
#include "Audience.h"
#include "Student.h"

void Functions::addNewAudienceObject() {
	Audience audience;
	//audience.createAudienceObj();
	//go to the index table (precisely list) and add a new item to the list
	// ALERT: before exactly adding check for existence of the exact same audience number
	// if the check is giving result of the already existing one then show error, else just add
}

void Functions::addNewStudentObject() {
	Student student;
	//student.createStudentObj();
	//using the student->Audience go to the index table and find that one audience (check for existence before is needed)
	//when found go to the student list, the tail must be existing and accessible
	//with tail add new (slave) student object to the StudentList make it a new tail
	// QUASTION (is sorting needed)
}