#pragma once
#include "Student.h"
#include <iostream>
#include <string>

using namespace std;
class StudentList
{
private:
	Student StudentData;
	Student* Next;
public:
	//methods

	void AddItemToList();
};
