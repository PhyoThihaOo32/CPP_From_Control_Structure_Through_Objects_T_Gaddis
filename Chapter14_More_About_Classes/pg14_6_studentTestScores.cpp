#include <iostream>
#include "StudentTestScores.h"
#include <string>

using namespace std;

void displayStudentInfo(const StudentTestScores &);

int main()
{

    // create student test score object and assign test scores
    StudentTestScores student1{"Pepito Mucho", 3};
    student1.setTestScore(100, 0);
    student1.setTestScore(100, 1);
    student1.setTestScore(100, 2);

    // create two more students test score object
    StudentTestScores student2("Holdor", 3);
    StudentTestScores student3("Bully Tommy", 3);

    // display the contents of student1 and student2
    displayStudentInfo(student1);
    displayStudentInfo(student2);
    displayStudentInfo(student3);

    // assign student 1 to student 2
    student3 = student2 = student1;

    // display the contents of student1 and student2
    displayStudentInfo(student1);
    displayStudentInfo(student2);
    displayStudentInfo(student3);

    return 0;
}

void displayStudentInfo(const StudentTestScores &s)
{
    cout << "Name: " << s.getName() << endl;
    cout << "Number of Tests: " << s.getNumTestScores() << endl;

    for (int i = 0; i < s.getNumTestScores(); i++)
    {
        cout << "Test Scores " << (i + 1) << " : " << s.getTestScore(i) << endl;
    }
}