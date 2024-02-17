#pragma once
#include "Audience.h"
#include "Student.h"
#include <iostream>
#include <string>

using namespace std;
class indexTable
{
private:
	int AudienceNumber;
	Audience* AudienceLink;
	//indexTable* Next;
public:
	//methods

	indexTable() {
		this->AudienceNumber = 0;
		this->AudienceLink = NULL;
		//this->Next = NULL;
	}

	indexTable(Audience aud){
		this->AudienceNumber = aud.getNumber();
		this->AudienceLink = &aud;
	}
	//indexTable* head = new indexTable;
	//indexTable* tail = new indexTable;

	void setAudienceNumber(int num);

	int getAudienceNumber();

	void setAudienceLink(Audience &aud) {
		this->AudienceLink = &aud;
	}

	Audience* getAudienceLink() {
		return this->AudienceLink;
	}

	//ÏĞÀÖŞŞ×² ÌÅÒÎÄÈ ÍÈÆ×Å 
	
	//void addNewItem(Audience aud, indexTable** head, indexTable** tail);

	//void findAudience(Student stud, indexTable* head);

	//void printTable(indexTable* head);
};

