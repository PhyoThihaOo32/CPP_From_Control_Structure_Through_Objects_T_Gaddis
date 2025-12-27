/*
    Program: Compare Two Distances Using Overloaded Relational Operators
    Author:  Phyo Thiha Oo

    Purpose:
        - Prompts the user to enter two distances in feet and inches.
        - Compares them using overloaded comparison operators (>, <, ==).
        - Displays which distance is greater or if they are equal.
*/

#include <iostream>
#include "FeetInches.h"
using namespace std;

int main()
{
    int feet, inches;

    FeetInches first, second;

    cout << "===============================" << endl;
    cout << "     Distance Comparison Tool   " << endl;
    cout << "===============================" << endl;

    // Input for first distance
    cout << "\nEnter distance #1 (feet inches): ";
    cin >> feet >> inches;
    first.setFeet(feet);
    first.setInch(inches);

    // Input for second distance
    cout << "Enter distance #2 (feet inches): ";
    cin >> feet >> inches;
    second.setFeet(feet);
    second.setInch(inches);

    cout << "\n--------------------------------" << endl;
    cout << "First distance:  " << first.getFeet() << " feet, " << first.getInch() << " inches" << endl;
    cout << "Second distance: " << second.getFeet() << " feet, " << second.getInch() << " inches" << endl;
    cout << "--------------------------------" << endl;

    // Comparison logic
    if (first > second)
    {
        cout << "✅ The first distance is greater than the second." << endl;
    }
    else if (second > first)
    {
        cout << "✅ The second distance is greater than the first." << endl;
    }
    else
    {
        cout << "⚖️  Both distances are equal." << endl;
    }

    cout << "--------------------------------" << endl;
    cout << "Comparison complete." << endl;

    return 0;
}