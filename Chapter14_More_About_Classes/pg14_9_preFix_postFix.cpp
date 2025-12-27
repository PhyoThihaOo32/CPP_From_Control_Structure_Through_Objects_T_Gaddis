/*
    Program: Demonstration of FeetInches class's overloaded prefix and postfix operators.
    Author:  Phyo Thiha Oo
    Purpose:
        - Shows how the prefix (++obj) and postfix (obj++) operators behave differently.
        - Prefix returns the incremented object (by reference).
        - Postfix returns the original object (by value, then increments internally).
*/

#include <iostream>
#include "FeetInches.h"
using namespace std;

int main()
{
    FeetInches first;        // Default-initialized to 0 feet 0 inches
    FeetInches second(1, 5); // Initialized to 1 foot 5 inches

    cout << "==============================" << endl;
    cout << "   PREFIX INCREMENT (++obj)   " << endl;
    cout << "==============================" << endl;

    for (int i = 0; i < 5; i++)
    {
        ++first; // Prefix increment — modifies object directly
        cout << "Iteration " << (i + 1) << ": "
             << first.getFeet() << " feet, "
             << first.getInch() << " inches" << endl;
    }

    cout << "\n==============================" << endl;
    cout << "   POSTFIX INCREMENT (obj++)  " << endl;
    cout << "==============================" << endl;

    for (int i = 0; i < 5; i++)
    {
        second++; // Postfix increment — returns old value, then increments
        cout << "Iteration " << (i + 1) << ": "
             << second.getFeet() << " feet, "
             << second.getInch() << " inches" << endl;
    }

    cout << "\n✅ Demonstration complete." << endl;
    return 0;
}