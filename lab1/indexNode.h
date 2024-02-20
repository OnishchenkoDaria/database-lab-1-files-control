#pragma once
#include <iostream>
#include <string>
#include "indexTable.h"

using namespace std;
struct indexNode
{
private:
	indexTable item;
	indexNode* Next;
public:

	indexNode() {
		this->Next = NULL;
	}
	
	indexNode(const indexTable& obj) {
		this->item = obj;
		//cout << "Making Node: " << this->item.getAudienceNumber() << " " << this->item.getAudienceLink() << endl;
		this->Next = NULL;
	}

	void printNode() {
		cout << "Item: ID " << this->item.getAudienceNumber() << " LINK " << this->item.getAudienceLink() << " || Next: " << this->Next << endl;
	}



	/*void AddNewNodeToList(indexNode** head, const indexTable& obj) {
		indexNode* temp = new indexNode(obj);
		temp->Next = NULL;
		if (!(*head)) {
			cout << "new node" << temp->getItemData().getAudienceNumber() << endl;
			*head = temp;
		}
		else {
			indexNode *find, *prev;
			find = prev = *head;
			while (find) {
				if (find->getItemData().getAudienceNumber() > temp->getItemData().getAudienceNumber()) {
					prev->setNext(temp);
					temp->setNext(find);
					free(find);
					free(prev);
					return;
				}
				else {
					prev->setNext(find);
					find->setNext(find->getNext());
				}
			}
			prev->setNext(temp);
			free(temp);
			free(prev);
		}
	}

	Audience* findStudentAudience(Student stud, indexNode* head) {
		int AudNumber = stud.getAudience();
		indexNode* temp = head;
		while (temp != NULL) {
			if (temp->getItemData().getAudienceNumber() == AudNumber) {
				cout << "Found: Audience: " << temp->getItemData().getAudienceNumber()
					<< "   Link: " << temp->getItemData().getAudienceLink() << endl;
				return temp->getItemData().getAudienceLink();
			}
			else {
				temp = temp->getNext();
			}
		}
		cout << "Error. No Audience with such a Number was recorded" << endl;
		return NULL;
	}*/

	void setNext(indexNode* temp);

	indexNode* getNext();

	indexTable getItemData();
};