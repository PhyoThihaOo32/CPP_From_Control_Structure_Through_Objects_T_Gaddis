#ifndef FINALEXAM_H
#define FINALEXAM_H

#include "GradeActivity.h"

class FinalExam : public GradeActivity
{
private:
    int numQuestions;
    double pointsEach;
    int numQuesMissed;

public:
    // default constructor
    FinalExam()
    {
        numQuestions = 0;
        pointsEach = 0.0;
        numQuesMissed = 0;
    }

    // constructor
    FinalExam(int numQuestions, int numQuesMissed)
    {
        set(numQuestions, numQuesMissed);
    }

    // mutator function
    void set(int, int);
    void adjustScore();

    // accessor function
    int getNumQuestion() const
    {
        return numQuestions;
    }

    double getPointsEach() const
    {
        return pointsEach;
    }

    int getNumQuesMissed() const
    {
        return numQuesMissed;
    }
};

#endif