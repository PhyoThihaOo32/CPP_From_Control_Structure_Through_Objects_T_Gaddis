// implementation file for Point class

#include "Point.h"
#include <iostream>

using namespace std;

// constructors

Point::Point(): x(0), y(0){}

Point::Point(int x, int y) : x(x), y(y){}


int Point::getX() const{return x;}
int Point::getY() const{return y;}

void Point::set(int x, int y){
    this->x = x;
    this->y = y;
}

void Point::print()const{
    cout << "(" << x << ", " << y << ")" << endl;
}