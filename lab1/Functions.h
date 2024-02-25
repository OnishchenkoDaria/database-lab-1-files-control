#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Audience.h"
#include "StudentNode.h"
#include "Utilities.h"
#include "indexNode.h"

indexNode* indexHead = new indexNode;
indexNode* studentsHead = new indexNode;
//StudentNode* head = new StudentNode;

void readAllIndexTable() {
	ifstream inFile("index.txt");

	if (!inFile) {
		cout << "Error opening index file!" << endl;
		return;
	}

	while (!inFile.eof()) {
		indexNode indx = readIndexFromFile(inFile);
		
		if ((indx.getAudienceLink() != -1) or (indx.getAudienceNumber() != 0)) {
			//indexHead->printNode();
			//indx.printNode();
			addNewIndex(indx.getAudienceNumber(), indx.getAudienceLink(), &indexHead);
		}
	}

	sortIndexTable(&indexHead);
	cout << "AUDIENCE INDEX TABLE" << endl;
	showAllList(indexHead);
}

void readAllStudentTable() {
	ifstream inFile("studentTable.txt");

	if (!inFile) {
		cout << "Error opening index file!" << endl;
		return;
	}

	while (!inFile.eof()) {
		indexNode indx = readIndexFromFile(inFile);

		if ((indx.getAudienceLink() != -1) or (indx.getAudienceNumber() != 0)) {
			//indexHead->printNode();
			//indx.printNode();
			addNewIndex(indx.getAudienceNumber(), indx.getAudienceLink(), &studentsHead);
		}
	}

	sortIndexTable(&studentsHead);
	cout << "STUDENT INDEX TABLE" << endl;
	showAllList(studentsHead);
}

void showMasterFile(){
	ifstream inFile("audience.txt");

	if (!inFile) {
		cout << "Error opening audience file!" << endl;
		return;
	}
	cout << endl;
	while (!inFile.eof()) {
		readAudFromFile(inFile);
	}
	cout << endl;
}

void showSlave() {
	ifstream inFile("students.txt");

	if (!inFile) {
		cout << "Error opening audience file!" << endl;
		return;
	}

	cout << endl;
	while (!inFile.eof()) {
		readStudentFromFile(inFile);
	}
	cout << endl;
}

void AddNewAudience() {
	Audience aud;
	aud.createObj(indexHead);
	if (aud.getNumber() == -1) {
		cerr << "The item with such Id already exist!" << endl;
		return;
	}
	
	streampos startPos = writeAudienceToFile(aud);
	if (startPos != -1) {
		indexNode obj(aud.getNumber(), startPos);
		addNewIndex(obj.getAudienceNumber(), obj.getAudienceLink(), &indexHead);
		writeNewIndexRecord(obj, "index.txt");
	}
	else {
		return;
	}
	sortIndexTable(&indexHead);
	writeSortedIndexTable(&indexHead, "index.txt");
}
/// THE ADD NEW MASTER --- FINISH
int AskForId() {
	int id;
	cout << "Insert id: ";
	cin >> id;
	return id;
}

Audience findAudience(int id) {
	//int id = AskForId();
	streampos pos = findById(id, indexHead);
	if (pos != -1) {
		string line = readLineFromPosition(pos, "audience.txt");
		return createAudfromLine(line);
	}
	else {
		cerr << "No Audience with such Number recorded earlier" << endl;
		Audience Empty;
		Empty.setNumber(-1);
		return Empty;
	}
}

void AddNewStudent() {
	StudentNode stud;
	stud.createObj(studentsHead);
	if (stud.getId() == -1) {
		cerr << "The item with such Id already exist!" << endl;
		return;
	}
	// id check (modernise the function for the master)

	streampos found = findStudentAudience(stud.getAudience(), indexHead);
	Audience foundAud = findAudience(stud.getAudience());
	if (foundAud.getNumber() == -1) {
		return;
	}

	//StudentNode head = createNode(stud, foundAud);
	if (foundAud.getStudentSubList() != -1) {
		stud.setNext(foundAud.getStudentSubList());
		//update the student attribute in audience master file
	}
	//stud.userData();

	streampos NewStudentsHeadPos = writeStudentToFile(stud);
	
	if (NewStudentsHeadPos != -1) {
		indexNode obj(stud.getId(), NewStudentsHeadPos);
		cout << "new student index object: "; obj.printNode();
		addNewIndex(obj.getAudienceNumber(), obj.getAudienceLink(), &studentsHead);
		writeNewIndexRecord(obj, "studentTable.txt");
	}
	else {
		return;
	}

	sortIndexTable(&studentsHead);
	writeSortedIndexTable(&studentsHead, "studentTable.txt");
	//int prevCount = foundAud.getStudentCount();
	//cout << "prevCount: " << prevCount << endl;

	foundAud.setStudentCount(foundAud.getStudentCount() + 1);
	//cout << "newCount: " << foundAud.getStudentCount() << endl;

	foundAud.setStudentSubList(NewStudentsHeadPos);
	//cout << "newStudentSubList: " << foundAud.getStudentSubList() << endl;

	string replacement = foundAud.TransformObjDataToLine();
	//cout << "REPLACEMENT: " << replacement << endl;
	replaceTheLineiInFile(found, replacement);
}

Audience getAudience() {
	return findAudience(AskForId());
}

StudentNode findStudentFromFile(int inputId, streampos position) {
	ifstream inFile("students.txt");

	string line = readLineFromPosition(position, "students.txt");
	//cout << line << endl;
	StudentNode stud = createStudfromLine(line);
	//stud.getStudentData().showObject();
	if (inputId == stud.getId()) {
		stud.userData();
		return stud;
	}
	else {
		//cout << "next position: " << stud.getNextStudent() << endl;
		if (stud.getNextStudent() != -1) {
			findStudentFromFile(inputId, stud.getNextStudent());
		}
		else {
			cout << "No Student with such Id found!" << endl;
		}
	}
}

StudentNode findTheStudent() {
	//use get-m
	Audience foundMaster = findAudience(AskForId());
	int id = AskForId();
	//cout << "pos: " << foundMaster.getStudentSubList() << endl;
	return findStudentFromFile(id, foundMaster.getStudentSubList());
}

void EditAudience(Audience& aud) {
	char answer;
	cout << "Press 'F' to change the floor data" << endl
		<< "Press 'T' to change the type data" << endl
		<< "Press 'U' to change the university data" << endl
		<< "Press 'A' to change the faculty data" << endl;

	int newFloor;
	string newString;
	streampos found;


	cin >> answer;
	switch (answer)
	{
	case 'F':
		cout << "Input new value: "; cin >> newFloor;
		aud.setFloor(newFloor);
		newString = aud.TransformObjDataToLine();
		found = findStudentAudience(aud.getNumber(), indexHead);
		replaceTheLineiInFile(found, newString);
		break;
	case 'T':
		cout << "Input new value: "; cin >> newString;
		aud.setType(newString);
		newString = aud.TransformObjDataToLine();
		found = findStudentAudience(aud.getNumber(), indexHead);
		replaceTheLineiInFile(found, newString);
		break;
	case 'U':
		cout << "Input new value: "; cin >> newString;
		aud.setType(newString);
		newString = aud.TransformObjDataToLine();
		found = findStudentAudience(aud.getNumber(), indexHead);
		replaceTheLineiInFile(found, newString);
		break;
	case 'A':
		cout << "Input new value: "; cin >> newString;
		aud.setType(newString);
		newString = aud.TransformObjDataToLine();
		found = findStudentAudience(aud.getNumber(), indexHead);
		replaceTheLineiInFile(found, newString);
		break;
	}
}

void EditStudent(StudentNode& stud) {
	char answer;
	cout << "Press 'N' to change the name data" << endl
		<< "Press 'B' to change the birthday data" << endl
		<< "Press 'G' to change the gender data" << endl
		<< "Press 'J' to change the group data" << endl
		<< "Press 'A' to change the audience data" << endl;

	int newAudince;
	string newString;
	char newGender;
	streampos found;


	cin >> answer;
	switch (answer)
	{
	case 'N':
		cout << "Input new value: "; cin >> newString;
		stud.setName(newString);
		newString = stud.TransformObjDataToLine();
		//
		replaceTheLineiInFile(found, newString);
		break;
	case 'B':
		/*cout << "Input new value: "; cin >> newString;
		aud.setType(newString);
		newString = aud.TransformObjDataToLine();
		found = indexHead.findStudentAudience(aud.getNumber());
		replaceTheLineiInFile(found, newString);*/
		break;
	case 'G':
		/*cout << "Input new value: "; cin >> newString;
		aud.setType(newString);
		newString = aud.TransformObjDataToLine();
		found = indexHead.findStudentAudience(aud.getNumber());
		replaceTheLineiInFile(found, newString);*/
		break;
	case 'J':
		/*cout << "Input new value: "; cin >> newString;
		aud.setType(newString);
		newString = aud.TransformObjDataToLine();
		found = indexHead.findStudentAudience(aud.getNumber());
		replaceTheLineiInFile(found, newString);*/
		break;
	case 'A':
		/*cout << "Input new value: "; cin >> newString;
		aud.setType(newString);
		newString = aud.TransformObjDataToLine();
		found = indexHead.findStudentAudience(aud.getNumber());
		replaceTheLineiInFile(found, newString);*/
		break;
	}
}