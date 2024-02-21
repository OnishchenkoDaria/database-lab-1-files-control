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
    int num, floor, position, count;
    string type, uni, faculty;
    bool visib;
    //StudentList* list;
    file >> num >> floor >> type >> uni >> faculty >> visib >> position >> count;
	streampos pos = position;
	cout << " num: " << num << " floor: " << floor << " type: " << type << " uni: " << uni << " fac: " << faculty << " vis: " << visib << " pos: " << pos<< endl;
	return Audience(num, floor, type, uni, faculty, visib, pos, count);
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

string readLineFromPosition(streampos startPos) {
	ifstream inFile("audience.txt");

	if (!inFile) {
		cerr << "Error opening audience file!" << endl;
		return ""; // Повертаємо пустий рядок у разі помилки
	}

	string line;
	inFile.seekg(startPos); // Встановлюємо позицію у файлі
	getline(inFile, line); // Зчитуємо рядок з встановленої позиції до символу нового рядка

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
	int num, floor, position, count;
	string type, uni, facult;
	bool visib;
	streampos studLink;
	if (iss >> num >> floor >> type >> uni >> facult >> visib >> position >> count) {
		cout << "AUDIENCE READ:  num " << num << " floor " << floor
			<< " type: " << type << " uni " << uni
			<< " facult " << facult << " vis " << visib
			<< " stud link: " << position << " stud count: " << count << endl;
		studLink = position;
		return Audience(num, floor, type, uni, facult, visib, studLink, count);
	}
	else {
		cout << "Invalid text found" << endl;
		return Audience();
	}
}

/*void replaceTheLineiInFile(streampos position, const string& newString, const string& oldline) {
	//ifstream inFile("audience.txt");
	//ofstream outFile("temp.txt", ios::app);
	fstream file("audience.txt", ios::in | ios::out);
	if (!file.is_open()) {
		cerr << "Error: Failed to open audience file." << std::endl;
		return;
	}
	file.seekg(position);
	string line;
	while (getline(file, line))
	{
		line.replace(line.find(oldline), oldline.length(), "");
		file << line << endl;

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
}*/

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

	int pos = position;
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
	string line = readLineFromPosition(found);
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