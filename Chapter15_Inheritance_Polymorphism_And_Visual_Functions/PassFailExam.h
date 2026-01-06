// ================================================================
//              PASS / FAIL EXAM CLASS
// ================================================================

#ifndef PASSFAILEXAM_H
#define PASSFAILEXAM_H

#include "PassFailActivity.h"

/*
===========================================
 CLASS: PassFailExam
-------------------------------------------
 • Derived from PassFailActivity.
 • Models an exam graded on number of questions
   and number missed.
 • Automatically calculates score as:
        score = 100 − (missed × pointsEach)
   and assigns 'P' or 'F' accordingly.
===========================================
*/
class PassFailExam : public PassFailActivity
{
private:
    int numQuestions;  // Total number of questions
    int quesMissed;    // Number of questions missed
    double pointsEach; // Points per question

public:
    // Default constructor
    PassFailExam() : PassFailActivity()
    {
        numQuestions = 0;
        quesMissed = 0;
        pointsEach = 0.0;
    }

    // Overloaded constructor
    PassFailExam(int questions, int missed, double minPassScore)
        : PassFailActivity(minPassScore)
    {
        set(questions, missed);
    }

    // Mutator: sets exam details and computes score
    void set(int questions, int missed)
    {
        numQuestions = questions;
        quesMissed = missed;

        // Avoid division by zero
        if (numQuestions <= 0)
        {
            cout << "⚠️ Invalid number of questions!" << endl;
            pointsEach = 0.0;
            score = 0.0;
            return;
        }

        // Calculate points per question and numeric score
        pointsEach = 100.0 / numQuestions;
        double numericScore = 100.0 - (quesMissed * pointsEach);

        // Use base class setScore() to assign and update grade
        setScore(numericScore);
    }

    // Accessors
    int getNumQuestion() const { return numQuestions; }
    int getMissedQuestion() const { return quesMissed; }
    double getPointsEach() const { return pointsEach; }
};

#endif // PASSFAILEXAM_H