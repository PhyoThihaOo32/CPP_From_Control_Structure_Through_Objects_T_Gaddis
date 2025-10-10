/*
This program validate the user input using while loops.
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{

    int num_classes, course_credit = 0;
    double numeric_grade,
        quality_point,
        product_credits = 0,
        semester_GPA = 0,
        total_credit = 0;
    string letter_grade;
    bool isPassingGrade;

    // ask user the number of class
    cout << "How many classes are you taking? (You can take 1 to 6 classes only.)";
    cin >> num_classes;

    while (num_classes < 0 || num_classes > 6)
    {
        cout << "Invalid input." << endl;
        cout << "How many classes are you taking? (You can take 1 to 6 classes only.)";
        cin >> num_classes;
    }

    for (int i = 1; i < num_classes; i++)
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
            product_credits = course_credit * quality_point;
        }
        else if (numeric_grade >= 90)
        {
            letter_grade = "A-";
            quality_point = 3.70;
            product_credits = course_credit * quality_point;
        }
        else if (numeric_grade >= 87)
        {
            letter_grade = "B+";
            quality_point = 3.30;
            product_credits = course_credit * quality_point;
        }
        else if (numeric_grade >= 83)
        {
            letter_grade = "B";
            quality_point = 3.00;
            product_credits = course_credit * quality_point;
        }
        else if (numeric_grade >= 80)
        {
            letter_grade = "B-";
            quality_point = 2.70;
            product_credits = course_credit * quality_point;
        }
        else if (numeric_grade >= 77)
        {
            letter_grade = "C+";
            quality_point = 2.30;
            product_credits = course_credit * quality_point;
        }

        else if (numeric_grade >= 73)
        {
            letter_grade = "C";
            quality_point = 2.00;
            product_credits = course_credit * quality_point;
        }
        else if (numeric_grade >= 70)
        {
            letter_grade = "C-";
            quality_point = 1.70;
            product_credits = course_credit * quality_point;
        }
        else if (numeric_grade >= 67)
        {
            letter_grade = "D+";
            quality_point = 1.30;
            product_credits = course_credit * quality_point;
        }
        else if (numeric_grade >= 63)
        {
            letter_grade = "D";
            quality_point = 1.00;
            product_credits = course_credit * quality_point;
        }
        else if (numeric_grade >= 60)
        {
            letter_grade = "D-";
            quality_point = 0.70;
            product_credits = course_credit * quality_point;
        }
        else
        {
            letter_grade = "F";
            quality_point = 0.00;
            product_credits = course_credit * quality_point;
        }

        // determine if is a passing or failing grade
        isPassingGrade = (numeric_grade >= 60) ? true : false;

        // set the numeric data output
        cout << setprecision(2) << showpoint << fixed;

        // print out the result

        cout << "Total attempted credit: " << course_credit << endl;
        cout << "Your letter grade is " << letter_grade << " which is a "
             << (isPassingGrade ? "passing" : "failing") << " grade." << endl;
        cout << "Numeric grade:\t" << setw(5) << numeric_grade << endl;
        cout << "Quality point:\t" << setw(5) << quality_point << endl;
        cout << "Semester GPA:\t" << product_credits << endl;
    }

    return 0;
}
