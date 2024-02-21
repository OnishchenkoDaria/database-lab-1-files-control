#pragma once
#include <iostream>
#include <string>
#include "Audience.h"
#include "Student.h"
#include "indexTable.h"
#include "indexNode.h"
#include "indexTableList.h"
#include <sstream>

indexTableList Table;
//const int MAXrecordsSIZE = 20;
//int AllAudiencesCount = 0;

/// THE ADD NEW MASTER --- START

Audience readAudFromFile(ifstream& file) {
    int num, floor;
    string type, uni, faculty;
    bool visib;
    //StudentList* list;
    file >> num >> floor >> type >> uni >> faculty >> visib;
    cout << " num: " << num << " floor: " << floor << " type: " << type << " uni: " << uni << " fac: " << faculty << " vis: " << visib;
    return Audience(num, floor, type, uni, faculty, visib);
}

indexTable readIndexFromFile(ifstream& file) {
	string line;
	getline(file, line); // Read the whole line
	istringstream iss(line);

	int num;
	string address;
	if (iss >> num >> address) {
		cout << "num: " << num << " address: " << address << endl;
		stringstream ss;
		ss << hex << address;
		uintptr_t adrs;
		ss >> adrs;
		Audience* ptr = reinterpret_cast<Audience*>(adrs);
		return indexTable(num, ptr);
	}
	else {
		cout << "Invalid text found" << endl;
		// Handle invalid input or end of file
		return indexTable(); // Or some other indication of failure
	}
}

void readAllIndexTable() {
	ifstream inFile("index.txt");
	
	if (!inFile) {
		cout << "Error opening audience file!" << endl;
		return;
	}

	//string line;
	while (!inFile.eof()) {
		indexTable indx = readIndexFromFile(inFile);
		//indx.showObj();
		if ((indx.getAudienceLink() != NULL) or indx.getAudienceNumber() != 0) {
			Table.addNewItem(indx);
		}
	}

	Table.showAllList();
}

void writeAudienceToFile(Audience obj) {
	ofstream outFile("audience.txt", ios::app);

	if (!outFile) {
		cout << "Error opening audience file!" << endl;
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

void writeStudentToFile(Student obj) {
	ofstream outFile("students.txt", ios::app);

	if (!outFile) {
		cout << "Error opening students file!" << endl;
		return;
	}
	outFile << obj.getId() << " "
		<< obj.getName() << " "
		<< obj.getDate() << " "
		<< obj.getGender() << " "
		<< obj.getGroup() << " "
		<< obj.getAudience() << " "
		<< obj.getVisibility() << endl;
	//outFile.close();
}

void AddNewIndexRecord(indexTable obj) {
	ofstream outFile("index.txt", ios::app);

	if (!outFile) {
		cout << "Error opening index file!" << endl;
		return;
	}

	outFile << obj.getAudienceNumber() << " " << obj.getAudienceLink() << endl;
}

void AddToIndexTable(indexTable obj) {
	Table.addNewItem(obj);
	Table.showAllList();
}

void AddNewAudience() {
	Audience aud;
	aud.creteObj();
	//check for already existing id
	writeAudienceToFile(aud);
	indexTable obj(aud.getNumber(), &aud);
	AddToIndexTable(obj);
	AddNewIndexRecord(obj);
}

/// THE ADD NEW MASTER --- FINISH

void AddNewStudent() {
	Student stud;
	stud.createObj();
	// id check
	writeStudentToFile(stud);
	Audience* found = Table.findStudentAudience(stud);
	Audience decoded = *found;
	decoded.showObject();/*
	StudentList List = decoded.getStudentSubList();
	List.AddItemStudentList(stud);
	decoded.setStudentSubList(List);*/
}