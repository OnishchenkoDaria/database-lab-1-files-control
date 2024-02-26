// lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Audience.h"
#include "indexNode.h"
#include "Functions.h"
using namespace std;

int main()
{
    
    //at start get functions LOAD for AUDIENCES , STUDENTS , INDEXTABLE
    //preloading
    readAllIndexTable();
    readAllStudentTable();
    
    //ut-m
    showMasterFile();

    //insert-m
//  AddNewAudience();

    //ut-s
    showSlave();

    //insert-s
//  AddNewStudent();
    
    //get-m
    getAudience().showObject();
    
    //get-s
    getStudent().userData();

    //edit-m
    Audience aud = getAudience();
    if (aud.getNumber() != -1) {
        EditAudience(aud);
    }

    showMasterFile();

    cout << "Hello World!\n";
}