/*
    ============================================================
    Student Dynamic Memory Examples
    ============================================================

    This program explains 3 different pointer/dynamic memory ideas:

    1) Pointer to a dynamic array of 10 Student objects
       ------------------------------------------------
       Student *students = new Student[10];

       Meaning:
       - students is ONE pointer.
       - It points to the first element of a dynamic array.
       - The dynamic array has 10 Student objects.

       Visual:
           students
              |
              v
           [Student][Student][Student] ... [Student]
              0        1        2             9

       Access:
           students[0].name
           students[1].name
           students[9].name

       Delete:
           delete[] students;


    2) Array of 10 pointers, each pointer points to ONE dynamic Student
       ---------------------------------------------------------------
       Student *studentPtrs[10];

       Meaning:
       - studentPtrs is an array of 10 pointers.
       - Each pointer can point to one dynamic Student object.

       Visual:
           studentPtrs[0] ---> Student
           studentPtrs[1] ---> Student
           studentPtrs[2] ---> Student
           ...
           studentPtrs[9] ---> Student

       Access:
           studentPtrs[0]->name
           studentPtrs[1]->name

       Delete:
           delete studentPtrs[i];


    3) Array of 10 pointers, each pointer points to a dynamic array of 10 Students
       -------------------------------------------------------------------------
       Student *studentArrays[10];

       Meaning:
       - studentArrays is an array of 10 pointers.
       - Each pointer points to a dynamic array of 10 Student objects.
       - This creates something like a 10 x 10 table of Student objects.

       Visual:
           studentArrays[0] ---> [Student][Student][Student] ... [Student]
           studentArrays[1] ---> [Student][Student][Student] ... [Student]
           studentArrays[2] ---> [Student][Student][Student] ... [Student]
           ...
           studentArrays[9] ---> [Student][Student][Student] ... [Student]

       Access:
           studentArrays[0][0].name
           studentArrays[0][1].name
           studentArrays[1][0].name
           studentArrays[9][9].name

       Delete:
           delete[] studentArrays[i];


    Important:
    ----------
    For your assignment, you only need this:

        Student *students = new Student[10];

    That creates a dynamic array of 10 students.
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
    /*
        ============================================================
        Example 1:
        Pointer to a dynamic array of 10 Student objects
        ============================================================

        students is a pointer.
        It points to the first element of a dynamic array of 10 Students.
    */

    Student *students = new Student[10];

    // Store data into the first student
    students[0].name = "Alice";
    students[0].exams[0] = 90;
    students[0].exams[1] = 85;
    students[0].exams[2] = 88;
    students[0].exams[3] = 92;
    students[0].exams[4] = 95;

    // Calculate average for first student
    int sum = 0;

    for (int i = 0; i < 5; i++)
    {
        sum += students[0].exams[i];
    }

    students[0].average = static_cast<double>(sum) / 5;

    cout << "Example 1: Pointer to dynamic array of 10 Students" << endl;
    cout << "Name: " << students[0].name << endl;
    cout << "Average: " << students[0].average << endl;
    cout << "--------------------------------------" << endl;

    // Delete dynamic array
    delete[] students;
    students = nullptr;

    /*
        ============================================================
        Example 2:
        Array of 10 pointers, each points to ONE dynamic Student
        ============================================================

        studentPtrs is an array of 10 Student pointers.

        Each element:
            studentPtrs[i]

        can point to one dynamic Student object.
    */

    Student *studentPtrs[10];

    // Create 10 dynamic Student objects
    for (int i = 0; i < 10; i++)
    {
        studentPtrs[i] = new Student;
    }

    // Store data into the first dynamic Student
    studentPtrs[0]->name = "Bob";
    studentPtrs[0]->average = 87.5;

    cout << "Example 2: Array of 10 pointers to Student objects" << endl;
    cout << "Name: " << studentPtrs[0]->name << endl;
    cout << "Average: " << studentPtrs[0]->average << endl;
    cout << "--------------------------------------" << endl;

    // Delete each dynamic Student object
    for (int i = 0; i < 10; i++)
    {
        delete studentPtrs[i];
        studentPtrs[i] = nullptr;
    }

    /*
        ============================================================
        Example 3:
        Array of 10 pointers, each points to a dynamic array of 10 Students
        ============================================================

        studentArrays is an array of 10 pointers.

        Each pointer points to a dynamic array of 10 Student objects.

        This is like a 10 x 10 table:

            row 0 -> 10 students
            row 1 -> 10 students
            row 2 -> 10 students
            ...
            row 9 -> 10 students
    */

    Student *studentArrays[10];

    // Create 10 dynamic arrays
    // Each dynamic array has 10 Student objects
    for (int i = 0; i < 10; i++)
    {
        studentArrays[i] = new Student[10];
    }

    // Store data into row 0, column 0
    studentArrays[0][0].name = "Charlie";
    studentArrays[0][0].average = 91.2;

    // Store data into row 9, column 9
    studentArrays[9][9].name = "David";
    studentArrays[9][9].average = 78.9;

    cout << "Example 3: Array of 10 pointers to dynamic arrays" << endl;
    cout << "Student at [0][0]: " << studentArrays[0][0].name << endl;
    cout << "Average: " << studentArrays[0][0].average << endl;

    cout << "Student at [9][9]: " << studentArrays[9][9].name << endl;
    cout << "Average: " << studentArrays[9][9].average << endl;
    cout << "--------------------------------------" << endl;

    // Delete each dynamic array
    for (int i = 0; i < 10; i++)
    {
        delete[] studentArrays[i];
        studentArrays[i] = nullptr;
    }

    return 0;
}