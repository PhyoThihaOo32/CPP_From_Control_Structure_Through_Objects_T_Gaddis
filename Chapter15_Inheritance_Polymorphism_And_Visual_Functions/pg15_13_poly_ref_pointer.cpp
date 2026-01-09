/*
Note: Polymorphic behavior is not possible when an object is passed by value.
*/

#include <iostream>
#include "PassFailExam.h"

using namespace std;

void displayGrade(const GradeActivity_Ver2 *);

int main()
{
    GradeActivity_Ver2 gradeActivity(88.0);

    PassFailExam exam(100, 25, 70.0);

    PassFailActivity activity(80.0); // minium passing score

    displayGrade(&gradeActivity);

    displayGrade(&exam);

    activity.setScore(45);
    displayGrade(&activity);

    return 0;
}

void displayGrade(const GradeActivity_Ver2 *activity)
{
    cout << "Score: " << activity->getScore() << endl;
    cout << "Letter Grade: " << activity->getLetterGrade() << endl;
}
