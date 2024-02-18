#pragma once
#include <iostream>
#include <string>
#include "indexTable.h"

using namespace std;
class indexNode
{
private:
	indexTable item;
	indexNode* Next;
public:
	
	indexNode(const indexTable& obj) {
		this->item = obj;
		cout << "Making Node: " << this->item.getAudienceNumber() << " " << this->item.getAudienceLink() << endl;
		this->Next = NULL;
	}

	void setNext(indexNode* temp);

	indexNode* getNext();

	indexTable getItemData();
};

