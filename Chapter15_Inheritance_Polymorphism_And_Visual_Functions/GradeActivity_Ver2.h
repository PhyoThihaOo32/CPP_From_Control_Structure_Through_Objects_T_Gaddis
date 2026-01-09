#ifndef GRADEACTIVITY_VER2_H
#define GRADEACTIVITY_VER2_H

#include <iostream>
using namespace std;

/*
    GradeActivity_Ver2 class
    -------------------------
    • Represents a graded activity (like an assignment or exam).
    • Stores a numeric score and determines a letter grade automatically.
    • Demonstrates inheritance and virtual methods for extensibility.
*/

class GradeActivity_Ver2
{
protected:
    double score;     // Numeric score
    char letterGrade; // Letter grade (A, B, C, D, F)

    // Helper: determines the letter grade based on score
    // Declared virtual so derived classes can override it
    virtual void determineLetterGrade()
    {
        if (score > 89)
            letterGrade = 'A';
        else if (score > 79)
            letterGrade = 'B';
        else if (score > 69)
            letterGrade = 'C';
        else if (score > 59)
            letterGrade = 'D';
        else
            letterGrade = 'F';
    }

public:
    // Constructors
    GradeActivity_Ver2() : score(0.0), letterGrade(' ') {}

    GradeActivity_Ver2(double s)
    {
        score = s;
        determineLetterGrade();
    }

    // Mutator: sets score and updates letter grade
    void setScore(double s)
    {
        score = s;
        determineLetterGrade(); // may call derived version if overridden
    }

    // Accessors
    double getScore() const { return score; }

    char getLetterGrade() const { return letterGrade; }
};

#endif