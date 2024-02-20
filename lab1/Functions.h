#pragma once
#include <iostream>
#include <string>
#include "Audience.h"
#include "Student.h"
#include "indexTable.h"
#include "indexNode.h"
#include "indexTableList.h"

indexTableList Table;

void loadTheIndex() {
	
}

/// THE ADD NEW MASTER --- START

Audience readFromFile(ifstream& file) {
    int num, floor;
    string type, uni, faculty;
    bool visib;
    //StudentList* list;
    file >> num >> floor >> type >> uni >> faculty >> visib;
    cout << num << floor << type << uni << faculty << visib;
    return Audience(num, floor, type, uni, faculty, visib);
}

void writeAudienceToFile(Audience obj) {
	ofstream outFile("audience.txt", ios::app);

	if (!outFile) {
		cout << "Error opening file!" << endl;
		return;
	}
	outFile << obj.getNumber() << " "
		<< obj.getFloor() << " "
		<< obj.getType() << " "
		<< obj.getUniversity() << " "
		<< obj.getFaculty() << " "
		<< obj.getVisibility() << endl;
	//outFile.close();
}

void AddToIndexTable(indexTable obj) {
	Table.addNewItem(obj);
	Table.showAllList();
}

void AddNewAudience() {
	Audience aud;
	aud.creteObj();
	writeAudienceToFile(aud);
	indexTable obj(aud.getNumber(), &aud);
	AddToIndexTable(obj);
}

/// THE ADD NEW MASTER --- FINISH