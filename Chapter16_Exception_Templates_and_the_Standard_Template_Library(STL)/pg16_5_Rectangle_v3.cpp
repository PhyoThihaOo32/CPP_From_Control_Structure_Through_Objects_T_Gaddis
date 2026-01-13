/*
This program demonstrates exception handling using classes that carry data.
---------------------------------------------------------------------------
• The Rectangle_v3 class throws exceptions (NegativeLength / NegativeWidth)
  containing the invalid value entered by the user.
• The program catches these exceptions and displays informative error messages.
• It allows the user to re-enter valid input, instead of terminating abruptly.
*/

#include <iostream>
#include "Rectangle_v3.h"
using namespace std;

int main()
{
    double length, width;
    Rectangle_v3 rect;
    bool tryAgain = true; // flag to recover from errors

    // Prompt user for initial input
    cout << "Enter Length: ";
    cin >> length;
    cout << "Enter Width: ";
    cin >> width;

    // Handle invalid length
    while (tryAgain)
    {
        try
        {
            rect.setLength(length); // may throw NegativeLength
            tryAgain = false;
        }
        catch (Rectangle_v3::NegativeLength e)
        {
            cout << "ERROR: " << e.getValue() << " is an invalid number."
                 << "\nPlease Enter a valid Length: ";
            cin >> length;
        }
    }

    // Reset flag for width validation
    tryAgain = true;

    // Handle invalid width
    while (tryAgain)
    {
        try
        {
            rect.setWidth(width); // may throw NegativeWidth
            tryAgain = false;
        }
        catch (Rectangle_v3::NegativeWidth e)
        {
            cout << "ERROR: " << e.getValue() << " is an invalid number."
                 << "\nPlease Enter a valid Width: ";
            cin >> width;
        }
    }

    // Display area
    cout << "\nArea of the rectangle ("
         << rect.getLength() << " x " << rect.getWidth()
         << ") is " << rect.getArea() << endl;

    return 0;
}