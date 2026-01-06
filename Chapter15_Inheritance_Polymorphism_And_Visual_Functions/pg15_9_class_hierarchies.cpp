#include <iostream>
#include "GradeActivity_Ver2.h"
#include "PassFailActivity.h"
#include "PassFailExam.h"
using namespace std;

int main()
{
    int questions, missed;
    double minPassingScore;

    cout << "Enter the number of questions: ";
    cin >> questions;

    cout << "Enter the number of questions missed: ";
    cin >> missed;

    cout << "Enter the minimum passing score: ";
    cin >> minPassingScore;

    // Create the PassFailExam object
    PassFailExam exam(questions, missed, minPassingScore);

    cout << "\n===== Exam Summary =====" << endl;
    cout << "Total Questions: " << exam.getNumQuestion() << endl;
    cout << "Questions Missed: " << exam.getMissedQuestion() << endl;
    cout << "Points Per Question: " << exam.getPointsEach() << endl;
    cout << "Numeric Score: " << exam.getScore() << endl;
    cout << "Minimum Passing Score: " << exam.getMinPassScore() << endl;
    cout << "Result: " << exam.getLetterGrade() << endl;
    cout << "Pass/Fail: " << exam.getPassLetterGrade() << endl;

    return 0;
}