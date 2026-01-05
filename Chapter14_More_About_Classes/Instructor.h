#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include <iostream>
#include <string>

using namespace std;

class Instructor
{
private:
    string lastName,
        firstName,
        officeNumber;

public:
    Instructor()
    {
        set(" ", " ", " ");
    }

    Instructor(string lname, string fname, string officeNum)
    {
        set(lname, fname, officeNum);
    }

    // set function
    void set(string lname, string fname, string officeNum)
    {
        lastName = lname;
        firstName = fname;
        officeNumber = officeNum;
    }

    // print function
    void print() const
    {
        cout << "Last Name: " << lastName << endl;
        cout << "First Name: " << firstName << endl;
        cout << "Office Number: " << officeNumber << endl;
    }
};

#endif