#include <iostream>
#include "CurveActivity.h"
using namespace std;

int main()
{
    double testScore, percentage;
    CurveActivity test;

    cout << "Enter the raw numeric test score: ";
    cin >> testScore;

    cout << "Enter the curve percentage: ";
    cin >> percentage;

    test.setPercentage(percentage);
    test.setScore(testScore);

    cout << "\n=== Grade Report ===\n";
    cout << "Raw Score: " << test.getRawScore() << endl;
    cout << "Curve Percentage: " << test.getPercentage() << "%" << endl;
    cout << "Final Curved Score: " << test.getScore() << endl;
    cout << "Final Letter Grade: " << test.getLetterGrade() << endl;

    return 0;
}