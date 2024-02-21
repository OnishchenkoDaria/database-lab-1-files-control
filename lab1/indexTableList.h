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

	streampos findStudentAudience(Student stud);

	streampos findById(int id){
		indexNode* temp = head;
		while (temp) {
			if (temp->getItemData().getAudienceNumber() == id) {
				return temp->getItemData().getAudienceLink();
			}
			else {
				temp = temp->getNext();
			}
		}
		cout << "No such item with id: " << id << endl;
		return 0;
	}
};