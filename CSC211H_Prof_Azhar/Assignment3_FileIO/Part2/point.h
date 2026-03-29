#ifndef POINT_H
#define POINT_H

class point
{
private:
   int x, y; // x and y co-ordinates

public:
   point() : x(0), y(0) {}
   void print() const;
   void set(int, int); // mutator
   int getX() const;   // accessor
   int getY() const;

   bool operator==(const point &) const;
   bool operator!=(const point &) const;
};

#endif

/*
=========================================================
Point Class Documentation
=========================================================

Overview:
The Point class represents a coordinate in a 2D Cartesian plane.
It stores integer x and y values and provides functions to set,
retrieve, print, and compare coordinates.

---------------------------------------------------------
Header File: point.h
---------------------------------------------------------

Data Members (Private):
- int x : stores the x-coordinate
- int y : stores the y-coordinate

Public Members:

1. Default Constructor
   - Initializes the point to (0, 0).

2. void set(int, int)
   - Assigns values to x and y.

3. int getX() const
   - Returns the x-coordinate.

4. int getY() const
   - Returns the y-coordinate.

5. void print() const
   - Displays the coordinate in format: (x, y)

6. bool operator==(const Point &) const
   - Returns true if both x and y match between
     two Point objects.

---------------------------------------------------------
Implementation File: point.cpp
---------------------------------------------------------

- set() assigns parameter values to data members.
- print() outputs the coordinate.
- getX() and getY() return individual values.
- operator== compares two Point objects for equality.

=========================================================
*/
