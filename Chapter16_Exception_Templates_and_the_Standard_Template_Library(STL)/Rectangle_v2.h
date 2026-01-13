#ifndef RECTANGLE_V2_H
#define RECTANGLE_V2_H

/*
    Rectangle_v2 Class
    -------------------
    • Demonstrates custom exception classes for input validation.
    • Throws:
        - NegativeLength  → if a negative value is passed to setLength()
        - NegativeWidth   → if a negative value is passed to setWidth()
*/

class Rectangle_v2
{
private:
    double length;
    double width;

public:
    // Exception classes
    class NegativeLength
    {
    }; // Thrown for invalid length
    class NegativeWidth
    {
    }; // Thrown for invalid width

    // Default constructor
    Rectangle_v2() : length(0.0), width(0.0) {}

    // Mutators
    void setLength(double len);
    void setWidth(double w);

    // Accessors
    double getLength() const { return length; }
    double getWidth() const { return width; }

    // Utility
    double getArea() const { return length * width; }
};

#endif