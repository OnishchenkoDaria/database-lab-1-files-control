#include "Utilities.h"

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

void readStudentFromFile(ifstream& file) {
	string line;
	if (getline(file, line)) {
		istringstream iss(line);
		int id, audience, position;
		string name, date, group;
		char gender;
		bool visib;

		if (iss >> id >> name >> date >> gender >> group >> audience >> visib >> position) {
			cout << " Student Id: " << id << " | "
				<< " Name: " << name << " | "
				<< " Birth date: " << date << " | "
				<< " Gender: " << gender << " | "
				<< " Group: " << group << " | "
				<< " Audience: " << audience << " | "
				<< " Visibility: " << visib << " | "
				<< " Next Student: " << position << endl;
			return;
		}
		else {
			cout << "Invalid text found in audiences file" << endl;
			return;
		}
	}
}

indexNode readIndexFromFile(ifstream& file) {
	string line;
	if (getline(file, line)) {
		istringstream iss(line);

		int num;
		int address;
		if (iss >> num >> address) {
			//cout << "num: " << num << " address: " << address << endl;
			streampos Adrs = address;
			return indexNode(num, Adrs);
		}
		else {
			cout << "Invalid text found in index file" << endl;
			return indexNode();
		}
	}
	else {
		//cout << "Failed to read the line in index file" << endl;
		return indexNode();
	}
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
		<< obj.getStudentSubList() << " "
		<< obj.getStudentCount() << endl;

	//outFile.close();
	return startPos;
}

void writeNewIndexRecord(indexNode obj, string filename) {
	ofstream outFile(filename, ios::app);

	if (!outFile) {
		cout << "Error opening index file!" << endl;
		return;
	}

	outFile << obj.getAudienceNumber() << " " << obj.getAudienceLink() << endl;
	outFile.close();
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
	outFile << obj.getId() << " "
		<< obj.getName() << " "
		<< obj.getDate() << " "
		<< obj.getGender() << " "
		<< obj.getGroup() << " "
		<< obj.getAudience() << " "
		<< obj.getVisibility() << " "
		<< obj.getNextStudent() << endl;

	return startPos;
	//outFile.close();
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
		pos = position;
		return StudentNode(id, name, date, gender, group, audience, visib);
	}
	else {
		return StudentNode();
	}
}

Audience createAudfromLine(string line) {
	istringstream iss(line);
	int num, floor, position, count;
	string type, uni, facult;
	bool visib;
	streampos studLink;
	if (iss >> num >> floor >> type >> uni >> facult >> visib >> position >> count) {
		studLink = position;
		return Audience(num, floor, type, uni, facult, visib, studLink, count);
	}
	else {
		cout << "Invalid text found" << endl;
		return Audience();
	}
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
	//ѕ≈–≈–ќЅ»“» Ќј “»ѕ” outFile << ... << ... <<endl (бо воно вносить без переносу)
	//в≥рн≥ше треба ото написати функц≥ю, €ка ф≥ксую, на ск≥льки (по к≥лькост≥ символ≥в) 
	//зб≥льшилась/зменшилаьс нова в≥дредагована ≥нфа (у вже готов≥й сроц≥, €ку тре заносити)
	//≥ в≥дпов≥дно в≥д цього зб≥льшити/зменшити на в≥дпов≥дно одиниць ус≥ position в зв'€зному списку
	//indexHead (зм≥нити треба вс≥ position на в≥дпов≥дну к≥льк≥сть одиниць починаючи в≥д наступного нода ≥ до к≥нц€)
	//п≥сл€ такого перепис≥в ус≥х position треба записати оновлений список
	file << newString;

	//check
	cout << "check after replacement: ";
	file.seekg(position);
	string line1;
	getline(file, line1);
	cout << line1 << endl;

	file.close();
}