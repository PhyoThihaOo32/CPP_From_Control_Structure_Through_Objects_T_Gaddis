// specification file for rectangle_v3 class

#ifndef RECTANGLE_V3_H
#define RECTANGLE_V3_H

class Rectangle_v3
{
private:
    double length, width;

public:
    // exception classes
    class NegativeLength
    {
    private:
        double value;

    public:
        NegativeLength(double v) { value = v; }
        double getValue() const { return value; }
    };

    class NegativeWidth
    {
    private:
        double value;

    public:
        NegativeWidth(double v) { value = v; }
        double getValue() const { return value; }
    };

    // constructor
    Rectangle_v3()
    {
        length = 0.0;
        width = 0.0;
    }

    // mutators
    void setLength(double len)
    {
        if (len >= 0)
        {
            length = len;
        }
        else
            throw NegativeLength(len);
    }

    void setWidth(double w)
    {
        if (w >= 0)
        {
            width = w;
        }
        else
            throw NegativeWidth(w);
    }

    // accessors
    double getLength() const { return length; }
    double getWidth() const { return width; }
    double getArea() const { return length * width; }
};

#endif