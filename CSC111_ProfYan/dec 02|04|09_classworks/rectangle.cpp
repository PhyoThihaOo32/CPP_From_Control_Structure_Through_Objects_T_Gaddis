/*
This program is about Rectangle class.
*/

#include <iostream>
#include <iomanip>

using namespace std;

class Rectangle
{
private:
    double length;
    double width;
    double height;

public:
    // constructor purpose is to initiliazed the object.
    // cannot have the return type
    Rectangle() // this is also called parameterless constructor
    {
        length = 0.0;
        width = 0.0;
        height = 0.0;
    }

    Rectangle(double l, double w)
    {
        length = l;
        width = w;
    }

    Rectangle(double l, double w, double h)
    {
        length = l;
        width = w;
        height = h;
    }
    void setLength(double newLength)
    {
        length = newLength;
    }

    void setWidth(double newWidth)
    {
        width = newWidth;
    }

    void setHeight(double newHeight)
    {
        height = newHeight;
    }

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

    double getVolume() const
    {
        return length * width * height;
    }

    double getPerimeter() const
    {
        return (length + width) * 2;
    }

    void showRectangle() const
    {
        cout << "Length: " << getLength() << endl;
        cout << "Width: " << getWidth() << endl;
        cout << "Area: " << getArea() << endl;
        cout << "Volume: " << getVolume() << endl;
        cout << "Perimeter: " << getPerimeter() << endl;
    }
};

int main()
{

    Rectangle r1, r2(3, 3, 3);

    r1.setLength(5.0);
    r1.setWidth(10.0);
    r1.setHeight(10.0);

    cout << "Rectangle No.1" << endl;
    r1.showRectangle();

    cout << "Rectangle No.2" << endl;
    r2.showRectangle();

    return 0;
}