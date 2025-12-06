// specification file for rectangle.h
#ifndef RECTANGLE_H
#define RECTANGLE_H

// Rectangle class declaration
class Rectangle
{
private:
    double length = 0;
    double width = 0;

public:
    // constructor
    Rectangle();
    Rectangle(double, double); // constructor overloading - accepting two double parameters

    // Mutators (Setters)
    void setLength(double);
    void setWidth(double);

    // Accessors (Getters)
    // inline memeber functions
    double getLength() const
    {
        return length;
    }

    double getWidth() const
    {
        return width;
    }

    double getArea() const
    {
        return length * width;
    }

    // Display rectangle info
    void showRect(const char *roomName) const;
};

#endif
