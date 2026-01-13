// specification file for cs_student class

#ifndef CSSTUDENT_H
#define CSSTUDENT_H

#include "Student.h"

// constant for required hours
const int MATH_HOURS = 20;
const int CS_HOURS = 40;
const int GEN_ED_HOURS = 60;

class CsStudent : public Student
{
private:
    int mathHours;
    int csHours;
    int genEdHours;

public:
    // default constructor
    CsStudent() : Student()
    {
        mathHours = 0;
        csHours = 0;
        genEdHours = 0;
    }

    CsStudent(string name, int id, int year) : Student(name, id, year)
    {
        mathHours = 0;
        csHours = 0;
        genEdHours = 0;
    }

    void setMathHours(int mathHours)
    {
        this->mathHours = mathHours;
    }

    void setCsHours(int csHours)
    {
        this->csHours = csHours;
    }

    void setGenEdHours(int genEdHours)
    {
        this->genEdHours = genEdHours;
    }

    // overriding pure virtual function getRamainingHours in derived class
    virtual int getRemainingHours() const
    {
        int reqHours;
        int remainingHours;

        reqHours = MATH_HOURS + CS_HOURS + GEN_ED_HOURS;

        remainingHours = reqHours - (mathHours + csHours + genEdHours);

        return remainingHours;
    }
};

#endif