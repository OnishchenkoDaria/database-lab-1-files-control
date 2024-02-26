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

void changeOfPositions(indexNode** head, int oldStringLength, int newStringLength, int key);

int Count(indexNode* head);;