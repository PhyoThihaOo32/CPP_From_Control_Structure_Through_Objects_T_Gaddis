#include <iostream>
#include "PassFailActivity.h"

using namespace std;

void display(const GradeActivity_Ver2 &activity)
{
    cout << "Score: " << activity.getScore() << endl;
    cout << "Letter Grade: " << activity.getLetterGrade() << endl;
}

int main()
{
    double minPassScore, testScore;

    cout << "Enter the minimum passing score: ";
    cin >> minPassScore;

    PassFailActivity test(minPassScore);

    cout << "Enter test score: ";
    cin >> testScore;

    test.setScore(testScore);

    display(test);

    return 0;
}