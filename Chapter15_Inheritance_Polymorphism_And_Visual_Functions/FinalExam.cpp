#include "FinalExam.h"

void FinalExam::set(int numQuestion, int numQuesMissed)
{
    double testScore;

    this->numQuestions = numQuestion;
    this->numQuesMissed = numQuesMissed;

    // calculate the pointsEach
    pointsEach = 100.0 / numQuestions;

    // get the testScore
    testScore = 100.0 - (numQuesMissed * pointsEach);

    // setting testScore (in based class)
    setScore(testScore);

    // adjust the test score ( round up )
    adjustScore();
}

void FinalExam::adjustScore()
{
    double fraction = testScore - static_cast<int>(testScore);
    if (fraction >= 0.5)
    {
        testScore += (1.0 - fraction);
    }
}