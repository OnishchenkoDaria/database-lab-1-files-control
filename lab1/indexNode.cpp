#include "indexNode.h"

void indexNode::setNext(indexNode* temp) {
	this->Next = temp;
}

indexNode* indexNode::getNext() {
	return this->Next;
}

indexTable indexNode::getItemData() {
	return this->item;
}