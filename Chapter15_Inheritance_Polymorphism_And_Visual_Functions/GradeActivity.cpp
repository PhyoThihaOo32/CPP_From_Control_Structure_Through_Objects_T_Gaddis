#include "GradeActivity.h"

char GradeActivity::getLetterGrade() const
{
    char letterGrade;
    if (testScore > 89)
        letterGrade = 'A';
    else if (testScore > 79)
        letterGrade = 'B';
    else if (testScore > 69)
        letterGrade = 'C';
    else if (testScore > 59)
        letterGrade = 'D';
    else
        letterGrade = 'F';
    return letterGrade;
}