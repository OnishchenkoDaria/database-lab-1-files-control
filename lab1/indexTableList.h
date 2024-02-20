#pragma once
#include <iostream>
#include <string>
#include "indexNode.h"

using namespace std;
struct indexTableList
{
private:
	indexNode* head;
public:

	indexTableList() {
		head = NULL;
	}

	//переписати функцію з indextable під цей клас
	//тобто функції, що приймали на вхід голову тепер мають бути переписан як методи цього класу
	//зокремо методи void indexTable::addNewItem , void indexTable::printTable , 

	void addNewItem(const indexTable& aud);

	void showAllList();

	Audience* findStudentAudience(Student stud);
};