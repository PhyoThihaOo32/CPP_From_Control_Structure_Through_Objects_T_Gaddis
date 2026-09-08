#ifndef RECTANGLE_V1_H
#define RECTANGLE_V1_H

/*
    Rectangle_v1 Class
    -------------------
    • Demonstrates basic exception handling in C++.
    • Throws a custom exception (NegativeValue) when a negative length or width is set.
*/

class Rectangle_v1
{
private:
    double length;
    double width;

public:
    // Exception class for negative input
    class NegativeValue
    {
    };

    // Default constructor
    Rectangle_v1() : length(0.0), width(0.0) {}

    // Mutator functions (throw exceptions on invalid input)
    void setLength(double);
    void setWidth(double);

    // Accessor functions
    double getLength() const { return length; }
    double getWidth() const { return width; }

    // Utility function
    double getArea() const { return length * width; }
};

#endif