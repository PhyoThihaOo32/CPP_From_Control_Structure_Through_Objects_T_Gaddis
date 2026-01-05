#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
private:
    double length;
    double width;

public:
    Rectangle() : length(0.0), width(0.0) {}

    Rectangle(double l, double w) : length(l), width(w) {}

    void setLength(double l) { length = l; }
    void setWidth(double w) { width = w; }

    double getLength() const { return length; }
    double getWidth() const { return width; }

    double getArea() const { return length * width; }
};

#endif