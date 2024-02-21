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

/*Audience readFromFile(ifstream& file) {
    int num, floor;
    string type, uni, faculty;
    bool visib;
    //StudentList* list;
    file >> num >> floor >> type >> uni >> faculty >> visib;
    cout << num << floor << type << uni << faculty << visib;
    return Audience(num, floor, type, uni, faculty, visib);
}*/

int main()
{
    //at start get functions LOAD for AUDIENCES , STUDENTS , INDEXTABLE
    readAllIndexTable();
    
    AddNewStudent();
    
    AddNewAudience();
    
    /*ofstream outFile("audience.txt");
    Audience aud1;
    aud1.creteObj();
    aud1.writeToFile(outFile);
    indexTable obj1(aud1.getNumber(), &aud1);

    Audience aud2;
    aud2.creteObj();
    aud2.writeToFile(outFile);
    indexTable obj2(aud2.getNumber(), &aud2);

    Audience aud3;
    aud3.creteObj();
    aud3.writeToFile(outFile);
    indexTable obj3(aud3.getNumber(), &aud3);
    outFile.close();*/

    /*ifstream inFile("audience.txt");
    Audience aud1;
    aud1 = readFromFile(inFile);
   // aud1.showObject();
    Audience aud2;
    aud2 = readFromFile(inFile);
    Audience aud3;
    aud3 = readFromFile(inFile);
    inFile.close();

    indexTable obj1(aud1.getNumber(), &aud1);
    indexTable obj2(aud2.getNumber(), &aud2);
    indexTable obj3(aud3.getNumber(), &aud3);
  
    indexTableList Table;
    Table.addNewItem(obj1);
    Table.addNewItem(obj2);
    Table.addNewItem(obj3);
    Table.showAllList();*/
    
    
    
    
    /*
    //print
    aud1.showObject();
    aud2.showObject();
    aud3.showObject();
    raud1.showObject();

    //Students
    Student stud1;
    stud1.createObj();

    //the function below returns the address of the audience (master record)
    Audience* found = Table.findStudentAudience(stud1);
    cout << " Address: " << found << endl;

    Audience decoded = *found;
    cout << "OBJECT: ";
    decoded.showObject();

    StudentList List = decoded.getStudentSubList();
    List.AddItemStudentList(stud1);
    decoded.setStudentSubList(List);
    List.showList();

    cout << " OBJECT CHANGED" << endl;
    decoded.showObject();*/

    cout << "Hello World!\n";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
