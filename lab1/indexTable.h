#pragma once
#include "Audience.h"
#include <iostream>
#include <string>

using namespace std;
class indexTable
{
private:
	int Key;
	int AudienceNumber;
	indexTable* Next;
public:
	//methods

	indexTable() {
		this->Key = this->AudienceNumber = 0;
		this->Next = NULL;
	}

	void setKey(indexTable* tail);

	void setAudienceNumber(int num);

	void addNewItem(Audience aud , indexTable** head, indexTable** tail);
};

