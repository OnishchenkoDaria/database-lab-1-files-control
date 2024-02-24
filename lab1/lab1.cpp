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
    
    //ut-m
    showMasterFile();

    //indert-m
    //AddNewAudience();
    //AddNewAudience();

    //ut-s
    showSlave();

    AddNewStudent();
    
    
    cout << "Hello World!\n";
    
    //insert-m
    /*AddNewAudience();
    AddNewAudience();*/
    //get-m

    //get-s
    //not working
    //findTheStudent();

    /*Audience aud = getAudience();
    if (aud.getNumber() != -1) {
        EditAudience(aud);
    }*/
    
    
    //findTheAudience();
    
    //insert-s
    
}