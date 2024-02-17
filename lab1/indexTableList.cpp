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