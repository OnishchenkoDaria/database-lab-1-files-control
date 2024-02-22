// lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Audience.h"
#include "Student.h"
#include "indexTable.h"
#include "indexNode.h"
#include "indexTableList.h"
#include "Functions.h"
using namespace std;

int main()
{
    
    //at start get functions LOAD for AUDIENCES , STUDENTS , INDEXTABLE
    //preloading
    readAllIndexTable();
    
    //ut-m
    showMasterFile();

    //ut-s
    showSlave();

    //insert-m
    /*AddNewAudience();
    AddNewAudience();*/
    //get-m

    //get-s
    findTheStudent();

    Audience aud = getAudience();
    EditAudience(aud);
    
    //findTheAudience();
    
    //insert-s
    AddNewStudent();
    cout << "Hello World!\n";
}