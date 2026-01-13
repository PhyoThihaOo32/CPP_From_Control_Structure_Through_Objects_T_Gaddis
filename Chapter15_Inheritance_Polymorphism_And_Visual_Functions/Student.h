// specification file for the student class

#ifndef STUDENT_H
#define STUDENT_H

#include <string>

using namespace std;

class Student
{
private:
    string studentName;
    int idNumber;
    int yearAdmitted;

public:
    // constructors
    Student()
    {
        studentName = "";
        idNumber = 0;
        yearAdmitted = 0;
    }

    Student(string name, int id, int year)
    {
        set(name, id, year);
    }

    // destructor
    virtual ~Student() {}

    // mutator function
    void set(string name, int id, int year)
    {
        studentName = name;
        idNumber = id;
        yearAdmitted = year;
    }

    // accessor function
    string getStudentName() const { return studentName; }

    int getIdNumber() const { return idNumber; }

    int getYearAdmitted() const { return yearAdmitted; }

    // pure virtual function
    virtual int getRemainingHours() const = 0;
};

#endif