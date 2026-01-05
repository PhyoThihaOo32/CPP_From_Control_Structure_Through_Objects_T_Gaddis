#ifndef GRADEACTIVITY_H
#define GRADEACTIVITY_H

class GradeActivity
{
protected:
    double testScore;

public:
    GradeActivity()
    {
        testScore = 0.0;
    }

    GradeActivity(double s)
    {
        testScore = s;
    }

    void setScore(double s)
    {
        testScore = s;
    }

    double getTestScore() const
    {
        return testScore;
    }

    char getLetterGrade() const;
};

#endif