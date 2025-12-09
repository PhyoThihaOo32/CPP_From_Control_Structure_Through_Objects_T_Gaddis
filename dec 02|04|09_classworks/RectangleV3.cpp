#include "RectangleV3.h"
#include <iostream>

using namespace std;

Rectangle::Rectangle()
{
    length = 0.0;
    width = 0.0;
    height = 0.0;
}

Rectangle::Rectangle(double l, double w)
{
    length = l;
    width = w;
}

Rectangle::Rectangle(double l, double w, double h)
{
    length = l;
    width = w;
    height = h;
}
void Rectangle::setLength(double newLength)
{
    length = newLength;
}

void Rectangle::setWidth(double newWidth)
{
    width = newWidth;
}

void Rectangle::setHeight(double newHeight)
{
    height = newHeight;
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

double Rectangle::getVolume() const
{
    return length * width * height;
}

double Rectangle::getPerimeter() const
{
    return (length + width) * 2;
}

void Rectangle::showRectangle() const
{
    cout << "Length: " << getLength() << endl;
    cout << "Width: " << getWidth() << endl;
    cout << "Area: " << getArea() << endl;
    cout << "Volume: " << getVolume() << endl;
    cout << "Perimeter: " << getPerimeter() << endl;
}
