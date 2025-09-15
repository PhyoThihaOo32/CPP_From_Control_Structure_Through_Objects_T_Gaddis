/*
This program allow a student to enter a test score and then display the grade for that score.
Using only if and else.
*/

#include <iostream>

using namespace std;

int main()
{

    // Constants for grade thresholds
    const int A_SCORE = 90,
              B_SCORE = 80,
              C_SCORE = 70,
              D_SCORE = 60;

    float score;
    char grade;

    // Ask user for the score
    cout << "Enter Test Score: " << endl;
    cin >> score;

    // Determin the letter grade
    if (score > A_SCORE)
    {
        grade = 'A';
        cout << grade << endl;
    }
    else
    {
        if (score > B_SCORE)
        {
            grade = 'B';
            cout << grade << endl;
        }
        else
        {
            if (score > C_SCORE)
            {
                grade = 'C';
                cout << grade << endl;
            }
            else
            {
                if (score > D_SCORE)
                {
                    grade = 'D';
                    cout << grade << endl;
                }
                else
                {
                    cout << "You Failed." << endl;
                }
            }
        }
    }

    return 0;
}