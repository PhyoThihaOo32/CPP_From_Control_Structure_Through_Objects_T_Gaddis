// ================================================================
//              PASS / FAIL ACTIVITY CLASS
// ================================================================

#ifndef PASSFAILACTIVITY_H
#define PASSFAILACTIVITY_H

#include "GradeActivity_Ver2.h"

/*
===========================================
 CLASS: PassFailActivity
-------------------------------------------
 • Derived from GradeActivity_Ver2.
 • Changes the grading logic to use a minimum passing score.
 • If score ≥ minPassScore → 'P', otherwise → 'F'.
===========================================
*/
class PassFailActivity : public GradeActivity_Ver2
{
protected:
    double minPassScore; // Minimum score required to pass

public:
    // Default constructor
    PassFailActivity() : GradeActivity_Ver2()
    {
        minPassScore = 0.0;
    }

    // Overloaded constructor
    PassFailActivity(double passScore) : GradeActivity_Ver2()
    {
        minPassScore = passScore;
    }

    // Mutator
    void setMinPassScore(double s)
    {
        minPassScore = s;
    }

    // Accessors
    double getMinPassScore() const { return minPassScore; }

    // Optional: convenience accessor for 'P'/'F'
    char getPassLetterGrade()
    {
        char passLetterGrade;
        if (score >= minPassScore)
        {
            passLetterGrade = 'P';
        }
        else
            passLetterGrade = 'F';

        return passLetterGrade;
    }
};

#endif // PASSFAILACTIVITY_H
