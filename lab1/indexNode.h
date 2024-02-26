#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;
struct indexNode
{
private:
	int Number;
	streampos position;
	indexNode* Next;
public:

	indexNode() {
		this->Number = 0;
		this->position = -1;
		this->Next = NULL;;
	}
	
	indexNode(int num, streampos pos) {
		this->Number = num;
		this->position = pos;
		this->Next = NULL;
	}

	void printNode();

	void setAudienceNumber(int num);

	int getAudienceNumber();

	void setAudienceLink(streampos pos);

	streampos getAudienceLink();

	void setNext(indexNode* temp);

	indexNode* getNext();
};

void writeSortedIndexTable(indexNode** head, string filename);
	
void addNewIndex(int num, streampos pos, indexNode** head);
	
void showAllList(indexNode* head);

streampos findById(int id, indexNode* head);

streampos findKey(int AudNumber, indexNode* head);

bool checkId(int inputId, indexNode* head);

void sortIndexTable(indexNode** head);
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

	Audience* findKey(Student stud, indexNode* head) {
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
