/*
This program averages test scores. It asks the user for the number of students and the number of test scores
per student.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

    // variables
    int number_students;
    int number_test_scores_per_student;

    double test_score,
        total_test_scores, // accumulator
        average_test_scores;

    // set the numberic data output
    cout << setprecision(2) << showpoint << fixed;

    // ask how many students need to evaluate the test score
    cout << "How many student want to evaluate their test score? ";
    cin >> number_students;

    // ask for each student how many number of test score they have
    cout << "For each student, how many test score do they have? ";
    cin >> number_test_scores_per_student;

    for (int student_count = 1; student_count <= number_students; student_count++)
    {
        total_test_scores = 0; // initialize the accumulator to 0
        for (int test_score_count = 1; test_score_count <= number_test_scores_per_student; test_score_count++)
        {
            cout << "Enter the test score " << test_score_count << " for student no: " << student_count << " :\t";
            cin >> test_score;

            // sum up the test score
            total_test_scores += test_score;
        }
        // calculate the average test score for each student
        average_test_scores = total_test_scores / number_test_scores_per_student;

        // dispaly the result for each student
        cout << "Student " << student_count << " has average test score: " << average_test_scores << endl;
    }

    return 0;
}