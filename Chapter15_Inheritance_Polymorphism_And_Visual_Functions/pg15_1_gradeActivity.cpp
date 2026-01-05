#include <iostream>
#include "GradeActivity.h"

using namespace std;

int main()
{

    double testScore;

    GradeActivity test; // default constructor will call, testScore = 0.0

    // get test score from the user
    cout << "Enter the numeric test score: ";
    cin >> testScore;

    // set testScore
    test.setScore(testScore);

    // display the letter grade for the test
    cout << "The grade for that test is " << test.getLetterGrade() << endl;

    return 0;
}