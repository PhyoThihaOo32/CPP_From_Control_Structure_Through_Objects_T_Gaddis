// Implementation file for Employee class
#include "Employee.h"
#include <iostream>
using namespace std;

// Default constructor
Employee::Employee()
{
    name = "";
    idNumber = 0;
    department = "";
    position = "";
}

// 4-argument constructor
Employee::Employee(string empName, int idNum, string depart, string empPosition)
{
    name = empName;
    idNumber = idNum;
    department = depart;
    position = empPosition;
}

// 2-argument constructor (only name and ID)
Employee::Employee(string empName, int idNum)
{
    name = empName;
    idNumber = idNum;
    department = "";
    position = "";
}

// Display employee info
void Employee::displayInfo() const
{
    cout << "Name: " << name << endl;
    cout << "ID Number: " << idNumber << endl;
    cout << "Department: " << department << endl;
    cout << "Position: " << position << endl;
    cout << "----------------------------------------\n";
}