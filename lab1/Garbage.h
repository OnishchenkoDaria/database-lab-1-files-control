#pragma once
#include <iostream>

using namespace std;
struct Garbage
{
private:
	streampos address = -1;
	Garbage* Next = NULL;
public:

	Garbage() {
		setAddress(-1);
		setNext(NULL);
	}

	Garbage(streampos pos) {
		setAddress(pos);
	}

	Garbage(streampos pos, Garbage* next) {
		setAddress(pos);
		setNext(next);
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

void AddNewAddress(Garbage** head, streampos address) {
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