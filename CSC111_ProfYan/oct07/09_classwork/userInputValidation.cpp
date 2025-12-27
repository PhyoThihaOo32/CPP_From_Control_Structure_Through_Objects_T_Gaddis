/*
This program validate the user input using while loops.
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{

    int num_classes;

    int course_credit,
        total_attempted_credit = 0;

    double numeric_grade,
        semester_GPA,
        quality_point,
        total_quality_point = 0;

    string letter_grade;

    // ask user the number of class
    cout << "How many classes are you taking? (You can take 1 to 6 classes only.)";
    cin >> num_classes;

    while (num_classes < 0 || num_classes > 6)
    {
        cout << "Invalid input." << endl;
        cout << "How many classes are you taking? (You can take 1 to 6 classes only.) ";
        cin >> num_classes;
    }

    for (int i = 1; i <= num_classes; i++)
    {
        // ask the user the number of credit for the class
        cout << "For class No " << i << endl;
        cout << "Enter the number of credit for class " << i << " : ";
        cin >> course_credit;

        // get the numeric grade from the user
        cout << "Please enter your numeric grade[0-100]: ";
        cin >> numeric_grade;

        // validate the numeric grade input
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
            quality_point = 4.00;
        }
        else if (numeric_grade >= 90)
        {
            letter_grade = "A-";
            quality_point = 3.70;
        }
        else if (numeric_grade >= 87)
        {
            letter_grade = "B+";
            quality_point = 3.30;
        }
        else if (numeric_grade >= 83)
        {
            letter_grade = "B";
            quality_point = 3.00;
        }
        else if (numeric_grade >= 80)
        {
            letter_grade = "B-";
            quality_point = 2.70;
        }
        else if (numeric_grade >= 77)
        {
            letter_grade = "C+";
            quality_point = 2.30;
        }

        else if (numeric_grade >= 73)
        {
            letter_grade = "C";
            quality_point = 2.00;
        }
        else if (numeric_grade >= 70)
        {
            letter_grade = "C-";
            quality_point = 1.70;
        }
        else if (numeric_grade >= 67)
        {
            letter_grade = "D+";
            quality_point = 1.30;
        }
        else if (numeric_grade >= 63)
        {
            letter_grade = "D";
            quality_point = 1.00;
        }
        else if (numeric_grade >= 60)
        {
            letter_grade = "D-";
            quality_point = 0.70;
        }
        else
        {
            letter_grade = "F";
            quality_point = 0.00;
        }

        // total of all credit for each class
        total_attempted_credit += course_credit;

        // calculate total quality point ( add the product of credit * quality point for each course)
        total_quality_point += (course_credit * quality_point);

        // calculating semester GPA (the sum of product of credits * quality points) divided by total attempted credit
        semester_GPA = total_quality_point / total_attempted_credit;

        cout << "Your letter grade for class " << i << " is " << letter_grade << endl;
        cout << "Quality point for class " << i << " is " << quality_point << endl;
    }

    cout << "Total attempted credit: " << total_attempted_credit << endl;
    cout << "Total quality point( course credit * quality point for each class): " << total_quality_point << endl;
    cout << "Semester GPA: " << semester_GPA << endl;
    semester_GPA >= 3.3 ? cout << "You are on the Dean's List" << endl : cout << "You are not on the Dean's List" << endl;

    return 0;
}
