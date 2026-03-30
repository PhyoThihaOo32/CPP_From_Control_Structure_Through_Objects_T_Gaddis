/*
5) Suppose you have the following declaration:

struct student
{
  string name;
  int exams [5];
  double average;
};
a) Declare a pointer to the structure student and use it to create a dynamic structure.
b) Ask the user to enter the name of a student and his 5 exam scores.
c) Calculate the average of the 5 exams and assign it to the average.
d) Delete the dynamic structure.
e) Create a dynamic array of 10 students.
f) Ask the user to enter the names of all students and their 5 exam scores.
g) For each student, calculate the average of the 5 exams and assign it to the average.
h) Delete the dynamic array.
*/

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
    // a) dynamic single student
    Student *stuP = new Student;

    // b) input (use getline for full name)
    cout << "Enter Student Name: ";
    getline(cin, stuP->name);

    for (int i = 0; i < 5; i++)
    {
        cout << "Enter Exam Score " << i + 1 << ": ";
        cin >> stuP->exams[i];
    }

    // c) calculate average
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += stuP->exams[i];
    }

    stuP->average = static_cast<double>(sum) / 5;
    cout << "Average Score: " << stuP->average << endl;

    // d) delete single student
    delete stuP;

    cin.ignore(); // clear buffer before next getline

    // e) dynamic array of 10 students
    Student *stuAp = new Student[10];

    // f) input all students
    for (int i = 0; i < 10; i++)
    {
        cout << "\nEnter Student " << i + 1 << " Name: ";
        getline(cin, stuAp[i].name);

        for (int j = 0; j < 5; j++)
        {
            cout << "Enter Exam Score " << j + 1 << ": ";
            cin >> stuAp[i].exams[j];
        }

        cin.ignore(); // prepare for next name
    }

    // g) calculate averages
    for (int i = 0; i < 10; i++)
    {
        int sum = 0;
        for (int j = 0; j < 5; j++)
        {
            sum += stuAp[i].exams[j];
        }

        stuAp[i].average = static_cast<double>(sum) / 5;

        cout << "Student " << i + 1
             << " Average: " << stuAp[i].average << endl;
    }

    // h) delete array
    delete[] stuAp;

    return 0;
}