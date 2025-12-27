/*
This program asks the users to enter their numeric grade (0–100).
The program converts the numeric grade into a letter grade based on BMCC a standard
grading scale, check the average GPA and also determines if it is a passing or failing grade.
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{

    // variables
    double numeric_grade,
        average_GPA;
    string letter_grade;
    bool isPassingGrade;

    // get the numeric grade from the user
    cout << "Please enter your numeric grade[0-100]: ";
    cin >> numeric_grade;

    // validate the input
    while (numeric_grade < 0 || numeric_grade > 100)
    {
        cout << "Scores can't be less than 0 and greater than 100." << endl;
        cout << "Please enter your numeric grade[0-100]: ";
        cin >> numeric_grade;
    }

    // check the numeric grade and convert it into letter grade
    if (numeric_grade >= 93)
    {
        letter_grade = "A";
        average_GPA = 4.00;
    }
    else if (numeric_grade >= 90)
    {
        letter_grade = "A-";
        average_GPA = 3.70;
    }
    else if (numeric_grade >= 87)
    {
        letter_grade = "B+";
        average_GPA = 3.30;
    }
    else if (numeric_grade >= 83)
    {
        letter_grade = "B";
        average_GPA = 3.00;
    }
    else if (numeric_grade >= 80)
    {
        letter_grade = "B-";
        average_GPA = 2.70;
    }
    else if (numeric_grade >= 77)
    {
        letter_grade = "C+";
        average_GPA = 2.30;
    }

    else if (numeric_grade >= 73)
    {
        letter_grade = "C";
        average_GPA = 2.00;
    }
    else if (numeric_grade >= 70)
    {
        letter_grade = "C-";
        average_GPA = 1.70;
    }
    else if (numeric_grade >= 67)
    {
        letter_grade = "D+";
        average_GPA = 1.30;
    }
    else if (numeric_grade >= 63)
    {
        letter_grade = "D";
        average_GPA = 1.00;
    }
    else if (numeric_grade >= 60)
    {
        letter_grade = "D-";
        average_GPA = 0.70;
    }
    else
    {
        letter_grade = "F";
        average_GPA = 0.00;
    }

    // determine if is a passing or failing grade
    isPassingGrade = (numeric_grade >= 60) ? true : false;

    // set the numeric data output
    cout << setprecision(2) << showpoint << fixed;

    // print out the letter grade with passing/ failing statement

    cout << "Your letter grade is " << letter_grade << " which is a "
         << (isPassingGrade ? "passing" : "failing") << " grade." << endl;
    cout << "Numeric grade:\t" << setw(5) << numeric_grade << endl;
    cout << "Average GPA:\t" << setw(5) << average_GPA << endl;

    return 0;
}
