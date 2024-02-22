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

	indexNode* getHead();

	void addNewItem(const indexTable& aud);

	void showAllList();

	streampos findStudentAudience(int AudNumber);

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