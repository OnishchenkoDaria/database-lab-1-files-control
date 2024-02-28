// lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//#include <iostream>
//#include "Audience.h"
//#include "indexNode.h"
#include "Functions.h"
using namespace std;

int main()
{
    readAllIndexTable();
    readAllStudentTable();
    int option = 0;
    while (true) {
        
        cout << "--------------------------------------------------------" << endl
            << "Press '1' to Add Audience (master)" << endl
            << "Press '2' to Add Student (slave)" << endl
            << "Press '3' to show all Audiences (master) - ut-m" << endl
            << "Press '4' to show all Students (slave) - ut-s" << endl
            << "Press '5' to get Audience (master) by Number" << endl
            << "Press '6' to get Student (slave) by Id" << endl
            << "Press '7' to calculate all Audiences (master) records" << endl
            << "Press '8' to calculate all Student (slave) records" << endl
            << "Press '9' to calculate all Audience's sub records" << endl
            << "Press '10' to edit Audience (master) record by Number" << endl
            << "Press '11' to edit Student (slave) record by Id" << endl
            << "Press '12' to remove Audience (master) record by Id" << endl
            << "Press '13' to remove Student (slave) record by Id" << endl
            << "--------------------------------------------------------" << endl;
        Audience aud;
        StudentNode stud;
        cin >> option;
        switch (option) {
            case 1:
                AddNewAudience();
                break;
            case 2:
                AddNewStudent();
                break;
            case 3:
                showMasterFile();
                break;
            case 4:
                showSlave();
                break;
            case 5:
                getAudience().showObject();
                break;
            case 6:
                getStudent().userData();
                break;
            case 7:
                cout << "Overall audiences: " << MasterCount() << endl;
                break;
            case 8:
                cout << "Overall Students: " << SlaveCount() << endl;
                break;
            case 9:
                cout << CountStudentsInAudience() << endl;
                break;
            case 10:
                aud = getAudience();
                if (aud.getNumber() != -1) {
                    EditAudience(aud);
                }
                break;
            case 11:
                stud = getStudent();
                if (stud.getId() != -1) {
                    EditStudent(stud);
                }
                break;
            case 12:
                printIndexList();
                removeAudience();
                break;
            case 13:
                int id = AskForId();
                removeStudent(id);
                break;
        }
        cout << endl;
    }
    
    

    //cout << "Hello World!\n";
}