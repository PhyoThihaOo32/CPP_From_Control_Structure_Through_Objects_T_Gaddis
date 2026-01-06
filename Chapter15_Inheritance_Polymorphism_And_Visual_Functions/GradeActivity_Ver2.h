#ifndef GRADEACTIVITY_VER2_H
#define GRADEACTIVITY_VER2_H

#include <iostream>
using namespace std;

/*
    GradeActivity_Ver2 class
    -------------------------
    • Represents a graded activity (like an assignment or exam).
    • Stores a numeric score and determines a letter grade automatically.
    • Demonstrates encapsulation and use of non-const mutator functions.
*/

class GradeActivity_Ver2
{
protected:
    double score;     // Numeric score
    char letterGrade; // Letter grade (A, B, C, D, F)

    // Helper function to determine the letter grade from score
    // This function modifies the object's state, so it should NOT be const
    void determineLetterGrade()
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
    // Default constructor
    GradeActivity_Ver2()
    {
        score = 0.0;
        letterGrade = ' ';
    }

    // Constructor with score parameter
    GradeActivity_Ver2(double s)
    {
        score = s;
        determineLetterGrade();
    }

    // Mutator: sets the score and updates the grade
    void setScore(double s)
    {
        score = s;
        determineLetterGrade();
    }

    // Accessor: returns numeric score
    double getScore() const
    {
        return score;
    }

    // Accessor: returns letter grade
    char getLetterGrade() const
    {
        return letterGrade;
    }

    // Display function (optional)
    void display() const
    {
        cout << "Score: " << score << ", Grade: " << letterGrade << endl;
    }
};

#endif