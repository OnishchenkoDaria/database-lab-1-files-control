#pragma once
#include <iostream>

using namespace std;
struct Garbage
{
private:
	streampos address;
	Garbage* Next;
public:

	Garbage() {
		this->Next = NULL;
	}

	Garbage(streampos pos) {
		this->address = pos;
		this->Next = NULL;
	}

	Garbage(streampos pos, Garbage* next) {
		this->address = pos;
		this->Next = next;
	}

	void setAddress(streampos pos) {
		this->address = pos;
	}

	streampos getAddress() {
		return this->address;
	}

	void setNext(Garbage* temp) {
		this->Next = temp;
	}

	Garbage* getNext() {
		return this->Next;
	}
};

bool checkEmpty(Garbage* head) {
	if (head == NULL)
		return true;
	else
		return false;
}

void AddNewGarbageAddress(Garbage** head, streampos address) {
	if (address < 0) {
		cerr << "Invalid address. Error adding to garbage" << endl;
		return;
	}

	Garbage* temp = new Garbage(address);
	//temp->setAddress(address);
	//if(!(*head)){
	//	*head = temp;
	//}

	temp->setNext(*head);
	*head = temp;
}

streampos takeAddress(Garbage** head) {
	if (!(*head)) {
		return -1;
	}

	Garbage* temp = *head;
	streampos address = (temp)->getAddress();
	*head = temp->getNext();

	delete temp;
	return address;	
}

void writeGarbage(Garbage** head, string filename) {
	ofstream outFile(filename, ios::app);

	if (!outFile) {
		cout << "Error opening index file!" << endl;
		return;
	}

	Garbage* temp = *head;
	while (temp) {
		//cout << temp->getAudienceNumber() << " " << temp->getAudienceLink() << endl;
		outFile << temp->getAddress() << " " << endl;
		temp = temp->getNext();
	}

	outFile.close();
}