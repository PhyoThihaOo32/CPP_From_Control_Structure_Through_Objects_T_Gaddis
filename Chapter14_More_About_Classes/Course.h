#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>
#include "Instructor.h"
#include "TextBook.h"

using namespace std;

class Course
{
private:
    string courseName;
    Instructor instructor;
    TextBook textBook;

public:
    Course(string course,
           string instLName, string instFName, string instOfficeNum,
           string textTitle, string textAuthor, string textPublisher)
    {
        courseName = course;

        // assign instructor
        instructor.set(instLName, instFName, instOfficeNum);

        // assign textBook
        textBook.set(textTitle, textAuthor, textPublisher);
    }

    // print function
    void print() const
    {
        cout << "Course Name: " << courseName << endl;
        cout << "Instructor Information: \n";
        instructor.print();
        cout << "\nTextBook Information: \n";
        textBook.print();
        cout << endl;
    }
};

#endif