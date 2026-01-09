#include <iostream>
#include "PassFailExam.h"
using namespace std;

// -----------------------------
// Function Prototype
// -----------------------------
void display(const GradeActivity_Ver2 &activity)
{
  cout << "\n--- Grade Report ---" << endl;
  cout << "Score: " << activity.getScore() << endl;
  cout << "Letter Grade: " << activity.getLetterGrade() << endl;
}

// -----------------------------
// Main Function
// -----------------------------
int main()
{
  // Example: 100 total questions, 5 missed, minimum passing score = 80
  PassFailExam passFailExam(100, 5, 80);

  // Base class object with a direct numeric score
  GradeActivity_Ver2 gradeActivity(60);

  cout << "Displaying results for a regular graded activity (A–F):";
  display(gradeActivity);

  cout << "\nDisplaying results for a pass/fail exam:";
  display(passFailExam);

  return 0;
}

/*
Summary:
---------
This program demonstrates inheritance and polymorphism in grading systems.
- GradeActivity_Ver2 assigns standard letter grades (A–F) from numeric scores.
- PassFailActivity overrides the grading logic to assign Pass/Fail results.
- PassFailExam extends this further by computing the numeric score
  from the total and missed exam questions.
- The setScore() function (from the base) calls determineLetterGrade() virtually,
  ensuring that the derived class version executes for Pass/Fail grading.
- The display() function accepts a base reference, showcasing runtime polymorphism.
*/