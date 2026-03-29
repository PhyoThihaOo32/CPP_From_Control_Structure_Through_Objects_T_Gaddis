#include <iostream>
#include <string>
using namespace std;

struct student
{
    string name;
    int exams[5];
    double average;
};

int main()
{
    // -----------------------------------
    // a) dynamic single student
    // -----------------------------------
    student *s = new student;

    // b) input
    cout << "Enter student name: ";
    getline(cin, s->name);

    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter exam " << i + 1 << ": ";
        cin >> s->exams[i];
        sum += s->exams[i];
    }

    // c) calculate average
    s->average = sum / 5.0;

    cout << "\nSingle Student:\n";
    cout << s->name << " Average: " << s->average << endl;

    // d) delete single student
    delete s;

    cin.ignore(); // clear buffer before next getline

    // -----------------------------------
    // d) dynamic array of 10 students
    // -----------------------------------
    student *stuP = new student[10];

    // e) input all students
    for (int i = 0; i < 10; i++)
    {
        cout << "\nEnter Student " << i + 1 << " Name: ";
        getline(cin, stuP[i].name);

        int sum = 0;
        for (int j = 0; j < 5; j++)
        {
            cout << "Enter Exam " << j + 1 << ": ";
            cin >> stuP[i].exams[j];
            sum += stuP[i].exams[j];
        }

        // f) calculate average
        stuP[i].average = sum / 5.0;

        cin.ignore(); // clear buffer for next name
    }

    // display all
    cout << "\nAll Students:\n";
    for (int i = 0; i < 10; i++)
    {
        cout << "\nName: " << stuP[i].name << endl;

        cout << "Scores: ";
        for (int j = 0; j < 5; j++)
        {
            cout << stuP[i].exams[j] << " ";
        }

        cout << "\nAverage: " << stuP[i].average << endl;
    }

    // g) delete array
    delete[] stuP;

    return 0;
}