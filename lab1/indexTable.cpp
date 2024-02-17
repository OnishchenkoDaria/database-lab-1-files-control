#include "indexTable.h"

void indexTable::setAudienceNumber(int num) {
	this->AudienceNumber = num;
}

int indexTable::getAudienceNumber() {
	return this->AudienceNumber;
}

//check for the keys, some KEYS CAN BE DELETED AFTER DELETE FUNCTION
//INSERT NEW OBJECT AT Missing key place

/*void indexTable::addNewItem(Audience aud, indexTable** head, indexTable** tail) {
	if (*head) {
		int prevKey=0;
		// here according to the requirements of the lab when the obj is deleted
		//the properties on the missing spot should be filled with -1 for each attribute
		//so it serves as a signal that this spot is free and new item can be written in there
		if ((*head)->Key != -1) {
			prevKey = (*head)->Key;
			*head = (*head)->Next;
			
		}
		else {
			this->Key = prevKey;
			this->AudienceNumber = aud.getNumber();
		}
	}
	else {

	}
}*/

void indexTable::addNewItem(Audience aud, indexTable** head, indexTable** tail) {
	indexTable* temp = new indexTable;
	cout << aud.getNumber() << endl;
	temp->AudienceNumber = aud.getNumber();
	temp->AudienceLink = &aud;
	cout << temp->AudienceNumber << endl;

	if (!(*head)){
		cout << "if" << endl;
		*head = *tail = temp;
		//temp->AudienceNumber = aud.getNumber();
		temp->Next = NULL;
		cout << "head: " << (*head)->AudienceNumber << endl;
	}
	else {
		cout<<"else"<<endl;
		indexTable *find, *prev;
		find = prev = *head;
		if (find) {
			if (find->AudienceNumber == -1) {
				//found the empty
				//need to fill and link with prev and next
				prev->Next = temp;
				temp->Next = find->Next;
				free(find);
				free(prev);
				//temp->Key = prev->Key + 1;
				//look carefully whether you have freed all memory needed
			}
			else {
				if (find->Next != NULL) {
					prev = find;
					find = find->Next;
					free(find);
					free(prev);
				}
				else {
					cout << "yipeeeeeeeee" << endl;
					cout << (*tail)->AudienceNumber << endl;
					(*tail)->Next = temp;
					//temp->Key = (*tail)->Key + 1;
					temp->Next = NULL;
					*tail = temp;
					cout <<"head: < " << (*head)->AudienceNumber << endl;
					cout <<"tail: < " << (*tail)->AudienceNumber << endl;
				}
			}
		}
	}
}

void indexTable::printTable(indexTable* head) {
	if (!head) {
		cout << "Empty indexTable!" << endl;
	}
	else {
		cout << "print start";
		while (head) {
			cout << "loop" << endl;
			cout << "Audience Number (Key): " << head->AudienceNumber << " Audience Link: " << head->AudienceLink << endl;
			head = head->Next;
		}
	}
}

//ÀÁÎ Â²ÄÑÎÐÒÓÂÀÒÈ Ï²ÑËß ÄÎÄÀÂÀÍÍß Â Ê²ÍÖ² ÍÎÂÃÎ ÅËÅÌÅÍÒÀ 

void indexTable::findAudience(Student stud, indexTable* head) {
	while (head) {
		if (head->AudienceNumber == stud.getAudience()) {

		}
	}
}