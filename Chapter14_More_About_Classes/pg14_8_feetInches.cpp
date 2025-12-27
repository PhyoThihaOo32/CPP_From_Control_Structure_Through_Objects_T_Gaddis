/*
This program demonstrates the FeetInches class's overloaded + and - operators.
*/

#include <iostream>
#include "FeetInches.h"

using namespace std;

int main()
{

    int feet, inches;

    // create three FeetInches objects
    FeetInches first, second, third;

    // get user inputs first and second
    cout << "Enter a distance in feet and inches: " << endl;
    cin >> feet >> inches;

    // store it in first
    first.setFeet(feet);
    first.setInch(inches);

    cout << "Enter a distance in feet and inches: " << endl;
    cin >> feet >> inches;

    // store it in second
    second.setFeet(feet);
    second.setInch(inches);

    // assign first + second to third
    third = first + second;

    // display the result
    cout << " first + second = " << third.getFeet() << " feet "
         << third.getInch() << " inches." << endl;

    // assign first - second to third
    third = first - second;

    cout << " first - second = " << third.getFeet() << " feet "
         << third.getInch() << " inches." << endl;

    return 0;
}