// lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Audience.h"
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
    //not working
    findTheStudent();

    Audience aud = getAudience();
    if (aud.getNumber() != -1) {
        EditAudience(aud);
    }
    
    
    //findTheAudience();
    
    //insert-s
    AddNewStudent();
    cout << "Hello World!\n";
}