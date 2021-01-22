#include <iostream>
#include <vector>
#include "Student.h"
#include "cli.h"

using namespace std;

int main()
{
    system("chcp 65001");

    Welcome();

    Student student;
    student.firstName = "Andrey";
    student.lastName = "Starinin";
    student.sex = Sex::Male;
    student.birthDay.year = 1986;
    student.birthDay.month = 2;
    student.birthDay.day = 18;
    student.faculty = Faculty::SoftDev;
    student.group = "RPO";
    student.isStudy = false;

    vector<Student> students;

    int choice;
    bool flagExit = false;
    do {
        ShowMenu();
        cout << endl << "Введите пункт меню: ";
        cin >> choice;

        switch (choice) {
            case 1:
                InsertStudent(students);
                break;
            case 2:
                break;
            case 3:
                ShowStudents(students);
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                ExportInFile(students);
                cout << "Check the file named 'InformationOfStudents.csv' , please." << endl;
                break;
            case 7:
                cout << endl << "There is the next information in file 'InformationOfStudents.csv':" << endl << endl;
                ImportFromFile(students);
                break;
            case 0:
                flagExit = true;
                break;
            default:
                break;
        }
    } while (!flagExit);
    //TODO подумать о создании функции выхода из программы
    cout << "До свидания!" << endl;
}
