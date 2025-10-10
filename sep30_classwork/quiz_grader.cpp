/*
This program will calculate the user's quiz average .
the program asks the user how many quizzes they took for a class.
For each of the quizzes, the program asks for the grade.
*/

#include <iostream>

using namespace std;

int main()
{

    int num_quizzes;
    float quiz_grade; // this variable is reused.In each iteration of the loop, it gets repeated.
    float total_quiz_grade = 0;
    float avg_grade;

    // ask user for the number of quizes
    cout << "Enter the number of quizes: ";
    cin >> num_quizzes;

    for (int i = 1; i <= num_quizzes; i++)
    {
        cout << "Enter the grade for quiz no." << i << " :";
        cin >> quiz_grade;
        total_quiz_grade += quiz_grade;
    }

    // calculate the average grade
    avg_grade = total_quiz_grade / num_quizzes;

    cout << "Total grade: " << total_quiz_grade << endl;
    cout << "Average grade: " << avg_grade << endl;

    return 0;
}