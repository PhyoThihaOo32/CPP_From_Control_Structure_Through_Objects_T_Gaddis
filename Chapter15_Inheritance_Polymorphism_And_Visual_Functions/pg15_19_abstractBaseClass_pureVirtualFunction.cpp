#include <iostream>
#include <string>
#include "CsStudent.h"
using namespace std;

/*
    Program Summary:
    ----------------
    • Demonstrates inheritance with the CsStudent class.
    • A CsStudent is a specialized Student that tracks completed hours in:
         - Math
         - Computer Science
         - General Education
    • The program calculates how many total hours remain until graduation.
*/

int main()
{
    // Create a CS student with name, ID, and year of enrollment
    CsStudent student("Melania", 100, 1998);

    // Set completed course hours
    student.setMathHours(20);
    student.setCsHours(20);
    student.setGenEdHours(40);

    // Display summary
    cout << "------------------------------------------" << endl;
    cout << "Student Name: " << student.getStudentName() << endl;
    cout << "Student ID:   " << student.getIdNumber() << endl;
    cout << "Year Enrolled:" << student.getYearAdmitted() << endl;
    cout << "------------------------------------------" << endl;
    cout << "Remaining Hours to Graduate: "
         << student.getRemainingHours() << endl;
    cout << "------------------------------------------" << endl;

    return 0;
}