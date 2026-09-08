/*
This program demonstrates robust exception handling with recovery.
---------------------------------------------------------------
• It uses the Rectangle_v2 class, which throws exceptions when
  negative values are entered for length or width.
• Instead of terminating the program immediately,
  it catches the exception, displays an error message,
  and prompts the user to re-enter valid input.
*/

#include <iostream>
#include "Rectangle_v2.h"
using namespace std;

int main()
{
    double length, width;
    bool tryAgain = true; // control flag for input validation

    Rectangle_v2 rect; // Rectangle object

    // Prompt initial input
    cout << "Enter length: ";
    cin >> length;

    cout << "Enter width: ";
    cin >> width;

    // Validate and set length
    while (tryAgain)
    {
        try
        {
            rect.setLength(length); // may throw NegativeLength
            tryAgain = false;       // success → exit loop
        }
        catch (Rectangle_v2::NegativeLength)
        {
            cout << "Invalid input! Length cannot be negative.\n"
                 << "Please enter a valid length: ";
            cin >> length;
        }
    }

    // Reset flag for width validation
    tryAgain = true;

    // Validate and set width
    while (tryAgain)
    {
        try
        {
            rect.setWidth(width); // may throw NegativeWidth
            tryAgain = false;     // success → exit loop
        }
        catch (Rectangle_v2::NegativeWidth)
        {
            cout << "Invalid input! Width cannot be negative.\n"
                 << "Please enter a valid width: ";
            cin >> width;
        }
    }

    // Display final result
    cout << "\nArea of the rectangle is: "
         << rect.getArea() << endl;

    return 0;
}