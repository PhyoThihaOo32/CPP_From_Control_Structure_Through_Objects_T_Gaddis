/// implementation file for Point class
#include <iostream>
#include "point.h"

using namespace std;

// This function prints out the values of the data members x and y.
void point::print() const
{
    cout << "(" << x << ", " << y << ")" << endl;
}

// This function sets the values of the data members x and y.
void point::set(int x, int y)
{
    this->x = x;
    this->y = y;
}

// This function returns the value of the x data member.
int point::getX() const { return x; }

// This function returns the value of the y data member.
int point::getY() const { return y; }

// overloaded operator == | check if the two point objects are equals
bool point::operator==(const point &p) const
{
    return (x == p.x && y == p.y) ? true : false;
}

// overloaded operator != | check if the two points objects are not equals
bool point::operator!=(const point &p) const
{
    return (x != p.x && y != p.y) ? true : false;
}
