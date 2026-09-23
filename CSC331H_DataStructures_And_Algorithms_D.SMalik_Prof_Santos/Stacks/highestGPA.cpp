/*
This program will read the student name and GPA from the text file,
put the student names with highest GPA to the stack
and print out the student names with highest GPA.
*/

#include <iostream>
#include "stackType.h"
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    ifstream inputFile("studentGPA.txt");
    double highestGPA;               // to store highest GPA
    double GPA;                      // to store GPA from the file
    string name;                     // to store student name
    stackType<string> students(100); // stack of string type to store student names

    if (inputFile >> name >> GPA)
    {
        highestGPA = GPA;
        students.push(name);
    }
    else
    {
        cout << "File doesn't exist." << endl;
        return 1;
    }

    while (inputFile >> name >> GPA)
    { // that mean - file is not at the end there is more than one student
        // if the next student GPA is higher
        if (GPA > highestGPA)
        {
            // we want to clean up the stack again
            students.initializeStack();
            students.push(name);
            highestGPA = GPA;
        }
        else if (GPA == highestGPA)
        {
            // if another student has the highest GPA - we want to push that student to the stack
            if (!students.isFullStack())
            {
                students.push(name);
            }
            else
            {
                cout << "Stack overflow." << endl;
                return 1;
            }
        }
        }
    cout << "Highest GPA: " << highestGPA << endl
         << "and the student names are as follows: " << endl;

    while (!students.isEmptyStack())
    {
        cout << students.top() << endl;
        students.pop();
    }

    return 0;
}