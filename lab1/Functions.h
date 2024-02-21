#pragma once
#include <iostream>
#include <string>
#include <fstream>
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
    int num, floor, position;
    string type, uni, faculty;
    bool visib;
    //StudentList* list;
    file >> num >> floor >> type >> uni >> faculty >> visib >> position;
	streampos pos = position;
	cout << " num: " << num << " floor: " << floor << " type: " << type << " uni: " << uni << " fac: " << faculty << " vis: " << visib << " pos: " << pos<< endl;
	return Audience(num, floor, type, uni, faculty, visib, pos);
}

indexTable readIndexFromFile(ifstream& file) {
	string line;
	if (getline(file, line)) {
		istringstream iss(line);

		int num;
		int address;
		if (iss >> num >> address) {
			cout << "num: " << num << " address: " << address << endl;
			streampos Adrs = address;
			return indexTable(num, Adrs);
		}
		else {
			cout << "Invalid text found" << endl;
			return indexTable();
		}
	}
	else {
		cout << "Failed to read the line" << endl;
		return indexTable();
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

streampos writeAudienceToFile(Audience obj) {
	ofstream outFile("audience.txt", ios::app);

	if (!outFile) {
		cout << "Error opening audience file!" << endl;
		return -1;
	}
	outFile << " ";
	streampos startPos = outFile.tellp();
	//cout << startPos << endl;
	outFile << obj.getNumber() << " "
		<< obj.getFloor() << " "
		<< obj.getType() << " "
		<< obj.getUniversity() << " "
		<< obj.getFaculty() << " "
		<< obj.getVisibility() << " "
		<< obj.getStudentSubList() << endl;
	
	//outFile.close();
	return startPos;
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
	//Table.showAllList();
}

void AddNewAudience() {
	Audience aud;
	aud.creteObj();
	// �������� �� �������� ��������������
	streampos startPos = writeAudienceToFile(aud); // �������� ������� ������� ����� � ����
	if (startPos != -1) { // ���� ����� ������� ������
		indexTable obj(aud.getNumber(), startPos); // �������� ������� ������� �����
		AddToIndexTable(obj);
		AddNewIndexRecord(obj);
	}
}

string readLineFromPosition(streampos startPos) {
	ifstream inFile("audience.txt");

	if (!inFile) {
		cerr << "Error opening audience file!" << endl;
		return ""; // ��������� ������ ����� � ��� �������
	}

	string line;
	inFile.seekg(startPos); // ������������ ������� � ����
	getline(inFile, line); // ������� ����� � ����������� ������� �� ������� ������ �����

	return line;
}

void findTheAudience() {
	int id;
	cout << "Insert id: " << endl;
	cin >> id;
	streampos pos = Table.findById(id);
	string line = readLineFromPosition(pos);
	cout << "Line from position " << pos << ": " << line << endl;
}

/// THE ADD NEW MASTER --- FINISH

Audience createAudfromLine(string line) {
	istringstream iss(line);
	int num, floor, position;
	string type, uni, facult;
	bool visib;
	streampos studLink;
	if (iss >> num >> floor >> type >> uni >> facult >> visib >> position) {
		cout << "AUDIENCE READ:  num " << num << " floor " << floor 
			 << " type: " << type << " uni " << uni 
			 << " facult " << facult << " vis " << visib 
			 << " stud link: " << position << endl;
		studLink = position;
		return Audience(num, floor, type, uni, facult, visib, studLink);
	}
	else {
		cout << "Invalid text found" << endl;
		return Audience();
	}
}

void AddNewStudent() {
	Student stud;
	stud.createObj();
	// id check
	
	streampos found = Table.findStudentAudience(stud);
	string line = readLineFromPosition(found);
	Audience foundAud = createAudfromLine(line);
	if (foundAud.getStudentSubList() == -1) {
		StudentList List;
		List.AddItemStudentList(stud);
		//update the student attribute in audience master file
	}
	else {

	}
	writeStudentToFile(stud);

	/*
	StudentList List = decoded.getStudentSubList();
	List.AddItemStudentList(stud);
	decoded.setStudentSubList(List);*/
}