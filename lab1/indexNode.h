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
		this->Next = NULL;
	}

	void setNext(indexNode* temp);

	indexNode* getNext();

	indexTable getItemData();
};

