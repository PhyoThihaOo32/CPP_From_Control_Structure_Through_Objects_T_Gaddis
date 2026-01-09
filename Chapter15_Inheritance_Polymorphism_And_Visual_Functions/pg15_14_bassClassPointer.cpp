/*
    Demonstration: Base Class Pointer to Derived Class Object
    ---------------------------------------------------------
    • A base class pointer (GradeActivity_Ver2*) can point to derived class objects.
    • Polymorphism allows calling the correct overridden method (e.g., Pass/Fail grading).
    • However, base class pointers can only access base class members directly.
*/

#include <iostream>
#include "PassFailExam.h"

using namespace std;

// Function prototype — accepts a pointer to the base class
void displayGrade(const GradeActivity_Ver2 *activity);

int main()
{
    const int NUM_TEST = 4;

    // Create an array of base class pointers — each may point to a derived object
    GradeActivity_Ver2 *test[NUM_TEST] = {
        new GradeActivity_Ver2(40),   // regular graded activity
        new PassFailExam(100, 5, 85), // derived (pass/fail exam)
        new GradeActivity_Ver2(90),   // regular graded activity
        new PassFailExam(100, 2, 90)  // derived (pass/fail exam)
    };

    // Display grades for all tests
    for (int i = 0; i < NUM_TEST; i++)
    {
        cout << "\nTest " << i + 1 << ":\n";
        displayGrade(test[i]);
    }

    // Properly release dynamically allocated memory
    for (int i = 0; i < NUM_TEST; i++)
    {
        delete test[i];
        /*
            You must use delete test[i]; for each object.
            You cannot use delete[] test; because 'test' is a static array of pointers,
            not a dynamically allocated array itself.
        */
    }

    return 0;
}

// ---------------------------------------------------------------
// Function: displayGrade()
// Purpose : Demonstrates polymorphic behavior using base pointer
// ---------------------------------------------------------------
void displayGrade(const GradeActivity_Ver2 *activity)
{
    cout << "Score: " << activity->getScore() << endl;
    cout << "Letter Grade: " << activity->getLetterGrade() << endl;

    /*
        ⚠️ Note:
        Although a base class pointer can reference a derived class object,
        it can only access members that are defined in the base class.

        Example:
        activity->getPointsEach(); // ❌ ERROR — not accessible via base pointer
    */
}