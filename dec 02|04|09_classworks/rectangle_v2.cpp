// Rectangle Version 2

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

Rectangle::Rectangle() // this is also called parameterless constructor
{
    length = 0.0;
    width = 0.0;
    height = 0.0;
}

Rectangle::Rectangle(double l, double w)
{
    length = l;
    width = w;
}

Rectangle::Rectangle(double l, double w, double h)
{
    length = l;
    width = w;
    height = h;
}
void Rectangle::setLength(double newLength)
{
    length = newLength;
}

void Rectangle::setWidth(double newWidth)
{
    width = newWidth;
}

void Rectangle::setHeight(double newHeight)
{
    height = newHeight;
}

double Rectangle::getLength() const
{
    return length;
}

double Rectangle::getWidth() const
{
    return width;
}

double Rectangle::getArea() const
{
    return length * width;
}

double Rectangle::getVolume() const
{
    return length * width * height;
}

double Rectangle::getPerimeter() const
{
    return (length + width) * 2;
}

void Rectangle::showRectangle() const
{
    cout << "Length: " << getLength() << endl;
    cout << "Width: " << getWidth() << endl;
    cout << "Area: " << getArea() << endl;
    cout << "Volume: " << getVolume() << endl;
    cout << "Perimeter: " << getPerimeter() << endl;
}
