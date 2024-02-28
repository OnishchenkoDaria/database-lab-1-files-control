#pragma once
#include <string>
#include <fstream>
#include "Audience.h"
#include "StudentNode.h"
#include "indexNode.h"
#include <sstream>

void readAudFromFile(ifstream& file);

string readLineFromPosition(streampos startPos, string fileName);

StudentNode createStudfromLine(string line);

void readStudentFromFile(ifstream& file);

indexNode readIndexFromFile(ifstream& file);

streampos writeAudienceToFile(Audience obj);

void writeNewIndexRecord(indexNode obj, string filename);

streampos writeStudentToFile(StudentNode obj);

Audience createAudfromLine(string line);

int streamposToInt(std::streampos pos);

void replaceTheLineiInFile(streampos position, const string& newString, string filename);