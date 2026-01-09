#ifndef PASSFAILACTIVITY_H
#define PASSFAILACTIVITY_H

#include "GradeActivity_Ver2.h"

/*
    PassFailActivity class
    -------------------------
    • Derived from GradeActivity_Ver2.
    • Changes grading logic: if score ≥ minPassScore → 'P', otherwise → 'F'.
*/

class PassFailActivity : public GradeActivity_Ver2
{
protected:
    double minPassScore; // Minimum score required to pass

    // Override base version — uses pass/fail logic
    virtual void determineLetterGrade()
    {
        if (score >= minPassScore)
            letterGrade = 'P';
        else
            letterGrade = 'F';
    }

public:
    // Constructors
    PassFailActivity() : GradeActivity_Ver2(), minPassScore(0.0) {}

    PassFailActivity(double passScore) : GradeActivity_Ver2(), minPassScore(passScore) {}

    // Mutators
    void setMinPassScore(double s)
    {
        minPassScore = s;
    }

    // Accessors
    double getMinPassScore() const { return minPassScore; }

    // Optional: convenience function
    char getPassLetterGrade() const
    {
        return (score >= minPassScore) ? 'P' : 'F';
    }
};

#endif