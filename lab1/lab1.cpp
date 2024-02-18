// lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Audience.h"
#include "Student.h"
#include "indexTable.h"
#include "indexNode.h"
#include "indexTableList.h"
using namespace std;

int main()
{
    Audience aud1;
    cout << " >>>ADDRESS : " << &aud1 << endl;
    indexTable obj1(aud1.getNumber(), &aud1);
    cout << " >>>ADDRESS : " << &aud1 << endl;
    cout << " INDEXTABLE ADDRESS: " << obj1.getAudienceLink() << endl;

    Audience aud2;
    cout << " >>>ADDRESS : " << &aud2 << endl;
    indexTable obj2(aud2.getNumber(), &aud2);
    cout << " INDEXTABLE ADDRESS: " << obj2.getAudienceLink() << endl;
    Audience aud3;
    cout << " >>>ADDRESS : " << &aud3 << endl;
    indexTable obj3(aud3.getNumber(), &aud3);
    cout << " INDEXTABLE ADDRESS: " << obj3.getAudienceLink() << endl;
    
    indexTableList Table;
    Table.addNewItem(obj1);
    Table.addNewItem(obj2);
    Table.addNewItem(obj3);
    Table.showAllList();
   
    //print
    aud1.showObject();
    aud2.showObject();
    aud3.showObject();

    //Students
    Student stud1;
    stud1.createObj();
    //the function below returns the address of the audience (master record)
    Audience* found = Table.findStudentAudience(stud1);
    cout << " Address: " << found << endl;

    Audience decoded = *found;
    //make print method for single object
    cout << "OBJECT: ";
    // CHECK WHY THE UNIVERSITY FACULTY AND TYPE IS NOT SHOWN
    decoded.showObject();

    //somewhere after here the constructor is summoned!!!!!

    StudentList List = decoded.getStudentSubList();
    List.AddItemStudentList(stud1);
    decoded.setStudentSubList(List);
    List.showList();

    cout << " OBJECT CHANGED" << endl;
    decoded.showObject();

    cout << "Hello World!\n";

    /*indexTable Table;
    indexTable* head = new indexTable;
    indexTable* tail = new indexTable;
    head = tail = NULL;
    Table.printTable(head);
    Audience aud;
    Audience aud1;
    Table.addNewItem(aud, &head, &tail);
    Table.addNewItem(aud1, &head, &tail);
    Table.printTable(head);*/
   
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
