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
     // Mutators (Setters)
    void setLength(double);
    void setWidth(double);

    // Accessors (Getters)
    double getLength() const;
    double getWidth() const;
    double getArea() const;

    // Display rectangle info
    void showRect(const char *roomName) const;
};

#endif
