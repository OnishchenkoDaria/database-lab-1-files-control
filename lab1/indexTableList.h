#pragma once
#include <iostream>
#include <string>
#include "indexNode.h"

using namespace std;
class indexTableList
{
private:
	indexNode* head;
public:

	indexTableList() {
		head = NULL;
	}

	//���������� ������� � indextable �� ��� ����
	//����� �������, �� �������� �� ���� ������ ����� ����� ���� ��������� �� ������ ����� �����
	//������� ������ void indexTable::addNewItem , void indexTable::printTable , 

	void addNewItem(const indexTable& aud);

	void showAllList();
};