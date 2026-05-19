#include <iostream>
#include <string>

using namespace std;

struct Student
{
    string name;
    int exams[5];
    double average;
};

int main()
{

    Student *stu = new Student; // Declare a pointer to the structure student and use it to create a dynamic structure.

    // ask the user to enter the name of a student and his 5 exams scores
    cout << "Enter the Name of Student: " << endl;
    cin >> stu->name; // (*str).name

    for (int i = 0; i < 5; i++)
    {
        cout << "Enter the exam scores " << i + 1 << " :";
        cin >> stu->exams[i];
    }

    // calculate the avg score
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += (*stu).exams[i];
    }
    stu->average = sum / 5;
    cout << "Average Score: " << stu->average << endl;

    delete stu;
    stu = nullptr;

    // create dynamic array of 10 Students
    Student *arrStu = new Student[10];
    // Student *stu[10];

    // ask user to enter the names of all student and their 5 exam scores
    for (int i = 0; i < 10; i++)
    {
        cout << "Enter Name of Student " << i + 1 << " :";
        cin >> arrStu[i].name;
        for (int j = 0; j < 5; j++)
        {
            cout << "Enter Exam Score " << j + 1 << " :";
            cin >> arrStu[i].exams[j];
        }
    }

    // calculate the average
    sum = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            sum += arrStu[i].exams[j];
        }
        arrStu[i].average = sum / 5;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << "Student " << i + 1 << " average score: " << arrStu[i].average << endl;
    }

    delete[] arrStu;
    arrStu = nullptr;

    return 0;
}