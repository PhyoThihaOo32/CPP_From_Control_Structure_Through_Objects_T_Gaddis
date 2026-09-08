#include <iostream>
#include "Rectangle_v1.h"
using namespace std;

/*
    Demonstrates:
    -------------
    • How to handle exceptions with try/catch.
    • How to use a custom exception type (Rectangle_v1::NegativeValue).
*/

int main()
{
    double width, length;
    Rectangle_v1 rect;

    cout << "Enter length: ";
    cin >> length;
    cout << "Enter width: ";
    cin >> width;

    try
    {
        rect.setLength(length);
        rect.setWidth(width);

        cout << "The Area of the Rectangle: "
             << rect.getArea() << endl;
    }
    catch (Rectangle_v1::NegativeValue)
    {
        cout << "ERROR: A negative value was entered." << endl;
    }

    cout << "Program ended." << endl;
    return 0;
}