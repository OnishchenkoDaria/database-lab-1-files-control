#include "indexNode.h"

void indexNode::printNode() {
	cout << "OBJECT: Item: ID " << this->getAudienceNumber()
		<< " Link " << this->getAudienceLink()
		<< " || Next: " << this->Next << endl;
}

void indexNode::setAudienceNumber(int num) {
	this->Number = num;
}

int indexNode::getAudienceNumber() {
	return this->Number;
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

void writeSortedIndexTable(indexNode** head, string filename) {
	ofstream outFile(filename);

	if (!outFile) {
		cout << "Error opening index file!" << endl;
		return;
	}

	indexNode* temp = *head;
	while (temp) {
		//cout << temp->getAudienceNumber() << " " << temp->getAudienceLink() << endl;
		outFile << temp->getAudienceNumber() << " " << temp->getAudienceLink() << endl;
		temp = temp->getNext();
	}

	outFile.close();
}

void addNewIndex(int num, streampos pos, indexNode** head) {
	indexNode* temp = new indexNode(num, pos);

	if (((*head)->getAudienceNumber() == 0) or ((*head)->getAudienceLink() == -1)) {
		*head = temp;
		return;
	}

	temp->setNext(*head);
	*head = temp;

}

void showAllList(indexNode* head) {
	while (head != NULL) {
		cout << "Key: " << head->getAudienceNumber() 
			 << "   Address: " << head->getAudienceLink() << endl;
		head = head->getNext();
	}
	cout << endl;
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
	//cout << "No such item with id: " << id << endl;
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
		return true;
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

void sortIndexTable(indexNode** head) {
	//check for empty or single-item list
	if (!(*head) or (*head)->getNext() == NULL) {
		return;
	}

	bool swapped;
	indexNode* ptr, * last = NULL;
	do {
		swapped = false;
		ptr = *head;

		while (ptr->getNext() != last) {
			if (ptr->getAudienceNumber() > ptr->getNext()->getAudienceNumber()) {
				int num = ptr->getAudienceNumber();
				streampos pos = ptr->getAudienceLink();

				ptr->setAudienceNumber(ptr->getNext()->getAudienceNumber());
				ptr->setAudienceLink(ptr->getNext()->getAudienceLink());

				ptr->getNext()->setAudienceNumber(num);
				ptr->getNext()->setAudienceLink(pos);

				swapped = true;
			}
			ptr = ptr->getNext();
		}
		last = ptr; //reached the end -> mark last sorted nnode
	} while (swapped);

}

/*indexTable indexNode::getItemData() {
	return this->item;
}*/