#include "indexTableList.h"

/*void indexTableList::addNewItem(const indexTable& aud) {
	indexNode* temp = new indexNode(aud);
	temp->setNext(head);
	head = temp;
}

indexNode* indexTableList::getHead() {
	return this->head;
}

void indexTableList::showAllList() {
	indexNode* temp = head;
	
	while (temp != NULL) {
		cout << "Key (AUDIENCE NUMBER): " << temp->getAudienceNumber() << "   Address: " << temp->getAudienceLink() << endl;
		temp = temp->getNext();
	}
}



streampos indexTableList::findStudentAudience(int AudNumber) {
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
}*/