/// implementation file for Point class
#include <iostream>
#include "point.h"

using namespace std;

// This function prints out the values of the data members x and y.
void Point::print() const
{
    cout << "(" << x << ", " << y << ")" << endl;
}

// This function sets the values of the data members x and y.
void Point::set(int x, int y)
{
    this->x = x;
    this->y = y;
}

// This function returns the value of the x data member.
int Point::getX() const { return x; }

// This function returns the value of the y data member.
int Point::getY() const { return y; }

// overloaded operator == | check if the two point objects are equals
bool Point::operator==(const Point &p) const
{
    return (x == p.x && y == p.y) ? true : false;
}
