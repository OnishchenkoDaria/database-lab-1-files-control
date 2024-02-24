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
	indexNode* temp = head;

	while (temp != NULL) {
		cout << "Key (AUDIENCE NUMBER): " << temp->getAudienceNumber() 
			 << "   Address: " << temp->getAudienceLink() << endl;
		temp = temp->getNext();
	}
}

streampos findById(int id, indexNode* head) {
	indexNode* temp = head;
	while (temp) {
		if (temp->getAudienceNumber() == id) {
			return temp->getAudienceLink();
		}
		else {
			temp = temp->getNext();
		}
	}
	cout << "No such item with id: " << id << endl;
	return -1;
}

streampos findStudentAudience(int AudNumber, indexNode* head) {
	//int AudNumber = stud.getAudience();
	indexNode* temp = head;
	while (temp != NULL) {
		if (temp->getAudienceNumber() == AudNumber) {
			cout << "Found: Audience: " << temp->getAudienceNumber()
				<< "   Link: " << temp->getAudienceLink() << endl;
			return temp->getAudienceLink();
		}
		else {
			temp = temp->getNext();
		}
	}
	cout << "Error. No Audience with such a Number was recorded" << endl;
	return NULL;
}

/*indexTable indexNode::getItemData() {
	return this->item;
}*/