#include "indexNode.h"

void indexNode::printNode() {
	cout << "OBJECT: Item: ID " << this->getAudienceNumber()
		<< " Link " << this->getAudienceLink()
		<< " || Next: " << this->Next << endl;
}

void indexNode::setAudienceNumber(int num) {
	this->AudienceNumber = num;
}

int indexNode::getAudienceNumber() {
	return this->AudienceNumber;
}

void indexNode::setAudienceLink(streampos pos) {
	this->position = pos;
}

streampos indexNode::getAudienceLink() {
	return this->position;
}

void indexNode::setNext(indexNode* temp) {
	this->Next = temp;
}

indexNode* indexNode::getNext() {
	return this->Next;
}

void addNewIndex(int num, streampos pos, indexNode** head) {
	indexNode* temp = new indexNode(num, pos);
	temp->setNext(*head);
	*head = temp;
}

void showAllList(indexNode* head) {
	//indexNode* temp = head;

	while (head != NULL) {
		cout << "Key (AUDIENCE NUMBER): " << head->getAudienceNumber() 
			 << "   Address: " << head->getAudienceLink() << endl;
		head = head->getNext();
	}
}

streampos findById(int id, indexNode* head) {
	//indexNode* temp = head;
	while (head) {
		if (head->getAudienceNumber() == id) {
			return head->getAudienceLink();
		}
		else {
			head = head->getNext();
		}
	}
	cout << "No such item with id: " << id << endl;
	return -1;
}

streampos findStudentAudience(int AudNumber, indexNode* head) {
	//int AudNumber = stud.getAudience();
	//indexNode* temp = head;
	while (head != NULL) {
		if (head->getAudienceNumber() == AudNumber) {
			cout << "Found: Audience: " << head->getAudienceNumber()
				<< "   Link: " << head->getAudienceLink() << endl;
			return head->getAudienceLink();
		}
		else {
			head = head->getNext();
		}
	}
	cout << "Error. No Audience with such a Number was recorded" << endl;
	return NULL;
}

bool checkId(int inputId, indexNode* head) {
	if (!head) {
		cerr << "The list does not exist!" << endl;
	}
	else {
		while (head) {
			if (inputId == head->getAudienceNumber()) {
				return false;
			}
			head = head->getNext();
			if (head == NULL) {
				return true;
			}
		}
	}
}

/*indexTable indexNode::getItemData() {
	return this->item;
}*/