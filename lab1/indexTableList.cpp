#include "indexTableList.h"

void indexTableList::addNewItem(const indexTable & aud){
	indexNode* temp = new indexNode(aud);
	temp->setNext(head);
	head = temp;
}

void indexTableList::showAllList() {
	indexNode* temp = head;
	while (temp != NULL) {
		cout << "Key (AUDIENCE NUMBER): " << temp->getItemData().getAudienceLink() << "   Address: " << temp->getItemData().getAudienceNumber() << endl;
		temp = temp->getNext();
	}
}

Audience* indexTableList::findStudentAudience(Student stud) {
	int AudNumber = stud.getAudience();
	indexNode* temp = head;
	while (temp != NULL) {
		if (temp->getItemData().getAudienceNumber() == AudNumber) {
			cout << "Found: Audience: " << temp->getItemData().getAudienceNumber()
				 << "   Link: " << temp->getItemData().getAudienceLink() << endl;
			return temp->getItemData().getAudienceLink();
		}
		else {
			temp = temp->getNext();
		}
	}
	cout << "Error. No Audience with such a Number was recorded" << endl;
	return NULL;
}