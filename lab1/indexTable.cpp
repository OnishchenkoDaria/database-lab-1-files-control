#include "indexTable.h"

void indexTable::setKey(indexTable* tail) {
	if (!tail) {
		this->Key = 1;
	}
	else {
		this->Key = (tail->Key + 1);
	}
}

void indexTable::setAudienceNumber(int num) {
	this->AudienceNumber = num;
}

//chaeck for the keys, some KEYS CAN BE DELETED AFTER DELETE FUNCTION
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
	temp->AudienceNumber = aud.getNumber();

	if (!(*head)){
		*head = *tail = temp;
		temp->Key = 1;
		temp->Next = NULL;
	}
	else {
		indexTable *find, *prev;
		find = prev = *head;
		if (find) {
			if (find->Key == -1) {
				//found the empty
				//need to fill and link with prev and next
				prev->Next = temp;
				temp->Next = find->Next;
				//look carefully whether you have freed all memory needed
				free(find);
				free(prev);
			}
			else {
				if (find->Next != NULL) {
					prev = find;
					find = find->Next;
				}
				else {
					(*tail)->Next = temp;
					temp->Next = NULL;
					*tail = temp;
				}
			}
		}
	}
}

//юан б╡дянпрсбюрх о╡якъ дндюбюммъ б й╡мж╡ мнбцн екелемрю 