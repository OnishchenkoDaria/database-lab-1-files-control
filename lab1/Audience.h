#pragma once
#include <iostream>
#include <string>

using namespace std;
class Audience
{
private:
	int Number{};
	int Floor{};
	string Type;
	string University;
	string Faculty;
	bool Visibility{};

public:
	//methods

	Audience() {
		cout << "Insert AUDIENCE number:   ";
		cin >> this->Number;
		cout << "Insert AUDIENCE floor:   ";
		cin >> this->Floor;
		cout << "Insert AUDIENCE type:   ";
		cin >> this->Type;
		cout << "Insert AUDIENCE location University:   ";
		cin >> this->University;
		cout << "Insert AUDIENCE location Faculty:   ";
		cin >> this->Faculty;
		this->Visibility = true;
	}

	void setNumber(int number);

	int getNumber();

	void setFloor(int floor);

	int getFloor();

	void setType(string type);

	string getType();

	void setUniversity(string univ);

	string getUniversity();

	void setFaculty(string faculty);

	string getFaculty();

	void changeVisibility();

	//void createAudienceObj();
};