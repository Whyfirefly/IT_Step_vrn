#pragma once

#include <iostream>
#include <vector>
#include "Student.h"

using namespace std;

void Welcome()
{
    cout << "====================" << endl;
    cout << "=== БД студентов ===" << endl;
    cout << "=== ------------ ===" << endl;
    cout << "= (c) IT Step ======" << endl;
    cout << "====================" << endl;
}

void ShowMenu()
{
    cout << "Пункты меню:" << endl;
    cout << "1. Добавить нового студента" << endl;
    cout << "2. Поиск студента" << endl;
    cout << "3. Показ данных всех студентов" << endl;
    cout << "4. Редактирование данных студента" << endl;
    cout << "5. Удаление данных студента" << endl;
    cout << "6. Экспорт в файл" << endl;
    cout << "7. Импорт из файла" << endl;
    cout << endl;
    cout << "0. Выход" << endl;
}

void ShowStudent(Student student)
{
    cout << "--- Студент ---" << endl;
    cout << "Имя: " << student.firstName << endl;
    cout << "Фамилия: " << student.lastName << endl;
    cout << "Дата рождения: ";
    cout << student.birthDay.ToString() << endl;
    cout << "Пол: " << SexToString(student.sex) << endl;
    cout << "Факультет: " << FacultyToString(student.faculty) << endl;
    cout << "Группа: " << student.group << endl;
    cout << "Учится? - " << student.IsStudyToString() << endl;
    //TODO переработать вывод на экран
}

void ShowStudents(vector<Student> students)
{
    for (auto student : students) {
        ShowStudent(student);
    }
}

void InsertStudent(vector<Student>& students)
{
    Student temp;
    char sexTemp;
    char facultyTemp;

    cout << "+++ Ввод данных студента +++" << endl;
    cout << "Введите имя - "; cin >> temp.firstName;
    cout << "Введите фамилию - "; cin >> temp.lastName;
    cout << "Введите дату рождения:" << endl;
    cout << "год - "; cin >> temp.birthDay.year;
    cout << "месяц - "; cin >> temp.birthDay.month;
    cout << "день - "; cin >> temp.birthDay.day;
    cout << "Введите пол (1 - мужской, 2 - женский) - ";
    cin >> sexTemp;
    if (sexTemp == '1') {
        temp.sex = Sex::Male;
    } else if (sexTemp == '2') {
        temp.sex = Sex::Female;
    } else {
        temp.sex = Sex::Other;
    }
    cout << "Введите факультет (1 - РПО, 2 - Дизайн) - ";
    cin >> facultyTemp;
    if (facultyTemp == '1') {
        temp.faculty = Faculty::SoftDev;
    } else if (facultyTemp == '2') {
        temp.faculty = Faculty::Design;
    }
    cout << "Введите номер группы - "; cin >> temp.group;
    temp.isStudy = true;

    students.push_back(temp);
}

//6.Экспорт в файл
string ExportInFile(vector<Student> students)
{
    Student student;
    ofstream file;
    file.open("InformationOfStudents.csv", ios_base::out);
    if(file.is_open()) {
       for (Student student : students) {
           file << "Name: " << student.firstName << ";" << endl
                << "Surname: " << student.lastName << ";" << endl
                << "Sex: " << SexToString(student.sex) << ";" << endl
                << "Date of birthday: " << student.birthday.ToString() << ";" << endl
                << "Faculty: " << FacultyToString(student.faculty) << ";" << endl
                << "Group: " << student.group << ";" << endl
                << "Does student study? - " << student.IsStudyToString() << ";" << endl << endl;
       }
    } else {
        cout << "File wasn't open" << endl;
    }
    file.close();
}

//7.Импорт из файла
string ImportFromFile(vector<Student> students)
{
    Student student;
    string birthday = student.birthday.ToString();
    string sex = SexToString(student.sex);
    string faculty = FacultyToString(student.faculty);
    string isStudy = student.IsStudyToString();

    ifstream file ("InformationOfStudents.csv");
    if(file.is_open()) {
        for (Student student : students) {
            getline (file, student.firstName,';');
            getline (file, student.lastName, ';');
            getline (file, sex, ';');
            getline (file, birthday, ';');
            getline (file, faculty, ';');
            getline (file, student.group, ';');
            getline (file, isStudy, ';');
        }
    } else {
        cout << "File wasn't open" << endl;
    }
    file.close();

    for (Student student : students) {
    cout << "Name: " << student.firstName << endl
         << "Surname: " << student.lastName
         << sex
         << birthday
         << faculty << endl
         << "Group: " << student.group
         << isStudy << endl << endl;
    }

}
