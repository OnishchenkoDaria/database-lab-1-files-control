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

	void createAudienceObj();
};