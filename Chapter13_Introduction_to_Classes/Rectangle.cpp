// implementation file for rectangle class
#include <iostream>
#include "Rectangle.h"
#include <iomanip>

using namespace std;

// ----- Member function definitions -----

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

double Rectangle::getLength() const
{
    return length;
}

double Rectangle::getWidth() const
{
    return width;
}

double Rectangle::getArea() const
{
    return length * width;
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
