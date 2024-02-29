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
		this->address = -1;
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
	if (head->getAddress() == -1 or !(&head) or !head)
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
	if ((*head)->getAddress() == -1) {
		*head = temp;
		return;
	}

	temp->setNext(*head);
	*head = temp;
}

streampos takeAddress(Garbage** head) {
	
	Garbage* temp = *head;
	if (!temp or (temp->getAddress() == -1)) {
		return -1;
	}
	else {
		streampos address = (temp)->getAddress();
		if (temp->getNext()) {
			*head = temp->getNext();
			delete temp;
			return address;
		}
		else {
			(*head)->setAddress(-1);
			(*head)->setNext(NULL);
			return address;
		}
	}	
}

void writeGarbage(Garbage** head, string filename) {
	ofstream outFile(filename);

	if (!outFile) {
		cout << "Error opening index file!" << endl;
		return;
	}
	if (!(*head)) {
		outFile << -1 << endl;
	}
	else {
		Garbage* temp = *head;
		while (temp) {
			//cout << temp->getAudienceNumber() << " " << temp->getAudienceLink() << endl;
			outFile << temp->getAddress() << " " << endl;
			temp = temp->getNext();
		}
	}
	outFile.close();
}

void printGarbage(Garbage* head) {
	cout << "head: ";
	while (head) {
		cout << head->getAddress() << endl;
		head = head->getNext();
	}
}