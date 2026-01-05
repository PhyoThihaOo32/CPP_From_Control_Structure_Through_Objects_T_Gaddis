#include <iostream>
#include <iomanip>
#include "FinalExam.h"

using namespace std;

int main()
{

    int numQuestions;
    int missedQuestions;

    FinalExam final;

    // get user input
    cout << "Enter the number of questions: ";
    cin >> numQuestions;

    cout << "Enter the number of questions that you missed: ";
    cin >> missedQuestions;

    final.set(numQuestions, missedQuestions);

    // display the test result
    cout << setprecision(2) << showpoint << fixed;

    cout << "Point for Each Question: " << final.getPointsEach() << endl;
    cout << "Total Test Score: " << final.getTestScore() << endl;
    cout << "Letter Grade: " << final.getLetterGrade() << endl;

    return 0;
}