/*
This program check test score and print out the test score.
Using if/ else if statements.
(Updated - This program also perform input validation. )
*/

#include <iostream>

using namespace std;

int main()
{

    // Constant for grade thresholds
    const int A_SCORE = 90,
              B_SOCRE = 80,
              C_SCORE = 70,
              D_SCORE = 60,
              MIN_SCORE = 0,
              MAX_SOCRE = 100;

    int user_score;

    // Getting user input
    cout << "Enter your test score: ";
    cin >> user_score;

    // Check the grade
    // user must enter valid data type (int) and score must be with range (0,100)
    if (cin.fail() || (user_score < 0 || user_score > 100))
    {
        cout << "Invalid Input." << endl;
    }
    else if (user_score >= A_SCORE)
    {
        cout << "You got A." << endl;
    }
    else if (user_score >= B_SOCRE)
    {
        cout << "You got B." << endl;
    }
    else if (user_score >= C_SCORE)
    {
        cout << "You got C." << endl;
    }
    else if (user_score >= D_SCORE)
    {
        cout << "You got D." << endl;
    }
    else
    {
        cout << "You Failed." << endl;
    }

    return 0;
}

/*
Note: The program doesn’t trigger the else block,
because cin >> user_score fails silently and sets an input error state,
so the rest of the if/else logic is never executed correctly.

Use:
    // Check if the input was valid
    if (cin.fail())
    {
        cout << "Invalid input. Please enter a number." << endl;
    }

    •	It detects invalid input, like entering letters when expecting a number.
    •	It prevents your logic from running on garbage or undefined values.
*/