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
//int MasterArr[MAXrecordsSIZE], SlaveArr[MAXrecordsSIZE];

/// THE ADD NEW MASTER --- START

void readAudFromFile(ifstream& file) {
	string line;
	if (getline(file, line)) {
		istringstream iss(line);
		int num, floor, position, count;
		string type, uni, faculty;
		bool visib;

		if (iss >> num >> floor >> type >> uni >> faculty >> visib >> position >> count) {
			streampos pos = position;
			cout << " Audience Number: " << num << " | "
				 << " Floor: " << floor << " | "
				 << " Type: " << type << " | "
				 << " University: " << uni << " | "
				 << " Faculty: " << faculty << " | "
				 << " Visibility: " << visib << " | "
				 << " Students List head: " << pos << " | "
				 << " Overall Students: " << count << endl;
			return;
		}
		else {
			cout << "Invalid text found in audiences file" << endl;
			return;
		}
	}
}

string readLineFromPosition(streampos startPos, string fileName) {
	ifstream inFile(fileName);

	if (!inFile) {
		cerr << "Error opening audience file!" << endl;
		return "";
	}

	string line;
	inFile.seekg(startPos);
	// get to the position in file
	getline(inFile, line); // read the line from the position
	//cout << line << endl;
	return line;
}

StudentNode createStudfromLine(string line) {
	//cout << "LINE: " << line << endl;
	istringstream iss(line);
	int id, audience, position;
	string name, date, group;
	char gender;
	bool visib;
	streampos pos;

	if (iss >> id >> name >> date >> gender >> group >> audience >> visib >> position) {
		/*cout << " Student Id: " << id << " | "
			<< " Name: " << name << " | "
			<< " BirthDate: " << date << " | "
			<< " Gender: " << gender << " | "
			<< " Group: " << group << " | "
			<< " Audience: " << audience << " | " << endl;*/
		pos = position;
		Student stud(id, name, date, gender, group, audience, visib);
		return StudentNode(stud, pos);
	}
	else {
		return StudentNode();
	}
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
			cout << "Invalid text found in index file" << endl;
			return indexTable();
		}
	}
	else {
		cout << "Failed to read the line in index file" << endl;
		return indexTable();
	}
}

void readAllIndexTable() {
	ifstream inFile("index.txt");
	
	if (!inFile) {
		cout << "Error opening index file!" << endl;
		return;
	}
	
	//string line;
	while (!inFile.eof()) {
		indexTable indx = readIndexFromFile(inFile);
		//indx.showObj();
		if ((indx.getAudienceLink() != -1) or (indx.getAudienceNumber() != 0)) {
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
		<< obj.getStudentSubList()<< " "
		<< obj.getStudentCount() << endl;
	
	//outFile.close();
	return startPos;
}

streampos writeStudentToFile(StudentNode obj) {
	ofstream outFile("students.txt", ios::app);

	if (!outFile) {
		cout << "Error opening students file!" << endl;
		return -1;
	}
	outFile << " ";
	streampos startPos = outFile.tellp();
	cout << "POSITION IN STUDENT FILE: " << startPos << endl;
	outFile << obj.getStudentData().getId() << " "
		<< obj.getStudentData().getName() << " "
		<< obj.getStudentData().getDate() << " "
		<< obj.getStudentData().getGender() << " "
		<< obj.getStudentData().getGroup() << " "
		<< obj.getStudentData().getAudience() << " "
		<< obj.getStudentData().getVisibility() << " "
		<< obj.getNextStudent() << endl;

	return startPos;
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
	// Перевірка на наявність ідентифікатора
	streampos startPos = writeAudienceToFile(aud); // Отримуємо позицію початку рядку у файлі
	if (startPos != -1) { // Якщо запис відбувся успішно
		indexTable obj(aud.getNumber(), startPos); // Передаємо позицію початку рядку
		AddToIndexTable(obj);
		AddNewIndexRecord(obj);
	}
}
/// THE ADD NEW MASTER --- FINISH

Audience createAudfromLine(string line) {
	istringstream iss(line);
	int num, floor, position, count;
	string type, uni, facult;
	bool visib;
	streampos studLink;
	if (iss >> num >> floor >> type >> uni >> facult >> visib >> position >> count) {
		/*cout << "AUDIENCE READ:  num " << num << " floor " << floor
			<< " type: " << type << " uni " << uni
			<< " facult " << facult << " vis " << visib
			<< " stud link: " << position << " stud count: " << count << endl;*/
		cout << endl << " Audience Number: " << num << " | "
			<< " Floor: " << floor << " | "
			<< " Type: " << type << " | "
			<< " University: " << uni << " | "
			<< " Faculty: " << facult << " | "
			<< " Overall Students: " << count << endl << endl;
		studLink = position;
		return Audience(num, floor, type, uni, facult, visib, studLink, count);
	}
	else {
		cout << "Invalid text found" << endl;
		return Audience();
	}
}

int AskForId() {
	int id;
	cout << "Insert id: ";
	cin >> id;
	return id;
}

Audience findTheAudience() {
	int id = AskForId();
	streampos pos = Table.findById(id);
	string line = readLineFromPosition(pos, "audience.txt");
	
	return createAudfromLine(line);
}

StudentNode readStudentFromFile(int inputId, streampos position) {
	ifstream inFile("students.txt");

	string line = readLineFromPosition(position, "students.txt");
	//cout << line << endl;
	StudentNode stud = createStudfromLine(line);
	//stud.getStudentData().showObject();
	if (inputId == stud.getStudentData().getId()) {
		stud.getStudentData().showObject();
		return stud;
	}
	else {
		//cout << "next position: " << stud.getNextStudent() << endl;
		if (stud.getNextStudent() != -1) {
			readStudentFromFile(inputId, stud.getNextStudent());
		}
		else {
			cout << "No Student with such Id found!" << endl;
		}
	}
}

StudentNode findTheStudent() {
	//use get-m
	Audience foundMaster = findTheAudience();
	int id = AskForId();
	//cout << "pos: " << foundMaster.getStudentSubList() << endl;
	return readStudentFromFile(id, foundMaster.getStudentSubList());
}

int streamposToInt(std::streampos pos) {
	return static_cast<int>(pos);
}

void replaceTheLineiInFile(streampos position, const string& newString) {
	//ifstream inFile("audience.txt");
	//ofstream outFile("temp.txt", ios::app);
	fstream file("audience.txt", ios::in | ios::out);
	if (!file.is_open()) {
		cerr << "Error: Failed to open audience file." << std::endl;
		return;
	}
	file.seekg(position);
	string line;
	getline(file, line);
	const char* charrArr = line.c_str();

	int pos = streamposToInt(position);
	for (int i = 0; i < line.size(); i++) {
		file.seekg(pos + i);
		file.put(' ');
	}

	file.seekg(position);
	file << newString;

	//check
	cout << "check after replacement: ";
	file.seekg(position);
	string line1;
	getline(file, line1);
	cout << line1 << endl;

	file.close();
}

StudentNode createNode(Student stud, Audience foundAud) {
	if (foundAud.getStudentSubList() == -1) {
		return StudentNode(stud);
		//update the student attribute in audience master file
	}
	else {
		return StudentNode(stud, foundAud.getStudentSubList());
	}
}

// insert-s
void AddNewStudent() {
	Student stud;
	stud.createObj();
	// id check
	
	streampos found = Table.findStudentAudience(stud);
	string line = readLineFromPosition(found, "audience.txt");
	Audience foundAud = createAudfromLine(line);
	foundAud.showObject();
	StudentNode head = createNode(stud, foundAud);
	head.showObj();
	streampos NewStudentsHeadPos = writeStudentToFile(head);
	int prevCount = foundAud.getStudentCount();
	cout << "prevCount: " << prevCount << endl;
	foundAud.setStudentCount(prevCount + 1);
	cout << "newCount: " << foundAud.getStudentCount() << endl;
	foundAud.setStudentSubList(NewStudentsHeadPos);
	cout << "newStudentSubList: " << foundAud.getStudentSubList() << endl;
	string replacement = foundAud.TransformObjDataToLine();
	cout << "REPLACEMENT: " << replacement << endl;
	replaceTheLineiInFile(found, replacement);
}