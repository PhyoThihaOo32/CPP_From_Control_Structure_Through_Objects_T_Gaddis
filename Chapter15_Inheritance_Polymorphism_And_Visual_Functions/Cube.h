#ifndef CUBE_H
#define CUBE_H

#include "Rectangle.h"

class Cube : public Rectangle
{
private:
    double height;

public:
    Cube() : Rectangle(), height(0.0) {}

    Cube(double l, double w, double h) : Rectangle(l, w), height(h) {}

    void setHeight(double h) { height = h; }
    double getHeight() const { return height; }

    double getVolume() const { return getArea() * height; }
};

#endif