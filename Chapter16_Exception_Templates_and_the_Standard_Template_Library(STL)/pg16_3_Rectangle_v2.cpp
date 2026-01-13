#include <iostream>
#include "Rectangle_v2.h"
using namespace std;

/*
    Demonstration:
    --------------
    • Prompts user for rectangle dimensions.
    • Uses try-catch blocks to handle custom exceptions separately.
    • Illustrates how different exception types can be caught and handled
      with meaningful error messages.
*/

int main()
{
    double width, length;
    Rectangle_v2 rect;

    cout << "Enter length: ";
    cin >> length;

    cout << "Enter width: ";
    cin >> width;

    try
    {
        rect.setLength(length);
        rect.setWidth(width);

        cout << "\nThe Area of the Rectangle: "
             << rect.getArea() << endl;
    }
    catch (Rectangle_v2::NegativeLength)
    {
        cout << "ERROR: A negative length was entered." << endl;
    }
    catch (Rectangle_v2::NegativeWidth)
    {
        cout << "ERROR: A negative width was entered." << endl;
    }

    cout << "\nProgram ended." << endl;
    return 0;
}