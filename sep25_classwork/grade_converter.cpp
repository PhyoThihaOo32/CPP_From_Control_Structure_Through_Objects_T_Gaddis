/*
This program ask the user for the numeric course grade. The program will take the numeric grade and
assign the correct letter grade.
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{

    // variable
    double numeric_grade;
    string letter_grade;

    // get the numeric grade from the user
    cout << "Enter your numberic grade: ";
    cin >> numeric_grade;

    // validate the input
    while (numeric_grade < 0 || numeric_grade > 100)
    {
        cout << "GPA can't be less than 0 and greater than 4.0." << endl;
        cout << "Enter your numberic grade: ";
        cin >> numeric_grade;
    }

    // check the numeric grade and convert it into letter grade
    if (numeric_grade >= 93)
    {
        letter_grade = "A";
    }
    else if (numeric_grade >= 90)
    {
        letter_grade = "A-";
    }
    else if (numeric_grade >= 87)
    {
        letter_grade = "B+";
    }
    else if (numeric_grade >= 83)
    {
        letter_grade = "B";
    }
    else if (numeric_grade >= 80)
    {
        letter_grade = "B-";
    }
    else if (numeric_grade >= 77)
    {
        letter_grade = "C+";
    }

    else if (numeric_grade >= 73)
    {
        letter_grade = "C-";
    }
    else if (numeric_grade >= 70)
    {
        letter_grade = "D+";
    }
    else if (numeric_grade >= 67)
    {
        letter_grade = "D";
    }
    else if (numeric_grade >= 63)
    {
        letter_grade = "D-";
    }
    else
    {
        letter_grade = "F";
    }

    // print out the letter grade
    cout << "You numeric_grade: " << numeric_grade
         << " converted to letter_grade: " << letter_grade << endl;

    return 0;
}