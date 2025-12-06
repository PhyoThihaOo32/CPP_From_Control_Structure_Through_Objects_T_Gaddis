// implementation file for rectangle class
#include <iostream>
#include "Rectangle.h"
#include <iomanip>

using namespace std;

// ----- Member function definitions -----
Rectangle::Rectangle()
{
    length = 0.0;
    width = 0.0;
}

Rectangle::Rectangle(double len, double w)
{
    length = len;
    width = w;
}

void Rectangle::setLength(double l)
{
    if (l > 0)
        length = l;
    else
    {
        cout << "Invalid length. Setting to 0.\n";
        length = 0;
    }
}

void Rectangle::setWidth(double w)
{
    if (w > 0)
        width = w;
    else
    {
        cout << "Invalid width. Setting to 0.\n";
        width = 0;
    }
}

// Display rectangle dimensions and area
void Rectangle::showRect(const char *roomName) const
{
    cout << "\n"
         << roomName << " Dimensions:\n";
    cout << "Length: " << setw(6) << length << " ft\n";
    cout << "Width:  " << setw(6) << width << " ft\n";
    cout << "Area:   " << setw(6) << getArea() << " sq ft\n";
}
