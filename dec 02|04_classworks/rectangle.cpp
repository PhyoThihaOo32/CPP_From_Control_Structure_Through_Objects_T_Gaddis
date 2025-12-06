/*
This program is class - rectangle.
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
    // constructor purpose is to initiliazed the object
    // cannot have the return type
    Rectangle() // this is also called parameterless constructor
    {
        length = 1;
        width = 1;
        height = 1;
    }

    Rectangle(double newLength, double newWidth, double newHeight)
    {
        length = newLength;
        width = newWidth;
        height = newHeight;
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

    double getLength()
    {
        return length;
    }

    double getWidth()
    {
        return width;
    }

    double getArea()
    {
        return length * width;
    }

    double getVolume()
    {
        return length * width * height;
    }
};

int main()
{

    Rectangle r1, r2(3, 3, 3);

    r1.setLength(5.0);
    r1.setWidth(10.0);
    r1.setHeight(10.0);

    cout << "Rectangle No.1" << endl;
    cout << "Length: " << r1.getLength() << endl;
    cout << "Width: " << r1.getWidth() << endl;
    cout << "Area: " << r1.getArea() << endl;
    cout << "Volume: " << r1.getVolume() << endl;

    cout << "Rectangle No.2" << endl;
    cout << "Length: " << r2.getLength() << endl;
    cout << "Width: " << r2.getWidth() << endl;
    cout << "Area: " << r2.getArea() << endl;
    cout << "Volume: " << r2.getVolume() << endl;
}