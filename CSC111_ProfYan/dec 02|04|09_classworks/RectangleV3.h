// Rectangle class version 3
#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
private:
    double length;
    double width;
    double height;

public:
    Rectangle();
    Rectangle(double, double);
    Rectangle(double, double, double);
    void setLength(double);
    void setWidth(double);
    void setHeight(double);
    double getLength() const;
    double getWidth() const;
    double getArea() const;
    double getVolume() const;
    double getPerimeter() const;
    void showRectangle() const;
};

#endif