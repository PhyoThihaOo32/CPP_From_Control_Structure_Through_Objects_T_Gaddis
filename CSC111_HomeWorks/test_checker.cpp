/*
This program checks a student's test performance based on their test scores.
1. It calculates the average score of all tests entered by the user.
2. It counts how many tests were passed and how many were failed.
3. It also identifies tests with scores over 100 (which may include extra credit).
4. The program performs input validation to ensure all scores are valid numbers within the allowed range.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

    int num_tests,
        extra_credit,

        // counters for tests numbers, passing tests, failing tests, test score more than 100
        test_count = 0,
        passing_test = 0,
        failing_test = 0,
        test_above100 = 0;

    double total_scores = 0.0, // accumulator for total test grade
        test_score,
           avg_scores;

    do
    {
        // get the number of tests from the user
        cout << "Enter the number of test (test can't be 0 or negative numbers): ";
        cin >> num_tests;
    } while (num_tests < 1); // validating the user input

    // Display grading info
    cout << "\n***********************************************************************\n"
         << "BMCC Grading Policy:\n"
         << "Passing: Any score >= 60 (D- or higher)\n"
         << "Failing: Any score < 60 (F)\n"
         << "Maximum Extra Credit Allowed: 10 points per test\n"
         << "***********************************************************************\n\n";

    // Ask the user for their numeric course grade for each test
    for (test_count = 1; test_count <= num_tests; test_count++)
    {
        do
        {
            do
            {
                // getting extra credit from the user
                cout << "Enter the possible extra credit for the course " << test_count << " : ";
                cin >> extra_credit;

                // validating user input for extra credit
                if (extra_credit < 0 || extra_credit > 10)
                {
                    cout << "Note: Maximum extra credit allowed is 10 points and (can't be negative.)"
                         << endl;
                }
            } while (extra_credit < 0 || extra_credit > 10);

            // getting numeri course grade from the user
            cout << "Enter your numeric course grade[0 - 100]for test " << test_count << " : ";
            cin >> test_score;

            // validate numeric course grade
            if (test_score < 0 || test_score > (100 + extra_credit))
                cout << "Invalid score! Must be between 0 and " << (100 + extra_credit) << ". Try again.\n";

        } while (test_score < 0 || test_score > (100 + extra_credit));

        // check the passing, failing and test above 100 and then adding the counters
        if (test_score >= 100)
        {
            test_above100++;
        }
        if (test_score >= 60)
        {
            passing_test++;
        }
        else
        {
            failing_test++;
        }

        // calculate the total test scores
        total_scores += test_score;
    }

    // calculating the average test scores
    avg_scores = total_scores / num_tests;

    // setting the numeric data output
    cout << setprecision(2) << showpoint << fixed;

    /*
    Printing the test average, the number of tests they passed,
    number of tests failed, number of tests in which the grade was 100 or more.
    */

    cout << "\nTotal test scores: " << total_scores << endl;
    cout << "Test average :\t" << avg_scores << endl;
    cout << "Number of passing tests :" << passing_test << endl;
    cout << "Number of failing tests(if any) : " << failing_test << endl;
    cout << "Number of tests in which grade was 100 or more : " << test_above100 << endl;

    return 0;
}