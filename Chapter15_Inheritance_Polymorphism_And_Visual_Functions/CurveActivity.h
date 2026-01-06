#ifndef CURVEACTIVITY_H
#define CURVEACTIVITY_H

#include "GradeActivity_Ver2.h"

class CurveActivity : public GradeActivity_Ver2
{
private:
    double rawScore;
    double percentage; // curve percentage (e.g., 5 means +5%)

public:
    CurveActivity() : GradeActivity_Ver2()
    {
        rawScore = 0.0;
        percentage = 0.0;
    }

    // Set curve percentage (e.g., 5 means 5%)
    void setPercentage(double p)
    {
        percentage = p;
    }

    void setScore(double s)
    {
        rawScore = s;
        // Apply curve: adds given percentage
        double curvedScore = rawScore * (1 + percentage / 100);
        GradeActivity_Ver2::setScore(curvedScore);
    }

    double getPercentage() const { return percentage; }
    double getRawScore() const { return rawScore; }
};

#endif