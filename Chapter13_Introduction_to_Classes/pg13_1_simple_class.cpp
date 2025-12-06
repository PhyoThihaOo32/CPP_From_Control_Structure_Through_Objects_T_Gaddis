/*
This program demonstrates a simple Rectangle class.
It shows how to use encapsulation with private data members,
public setter/getter functions, and const member functions.
*/

#include <iostream>
#include <iomanip>
using namespace std;

// Rectangle class declaration
class Rectangle
{
private:
    double length;
    double width;

public:
    // Mutators (Setters)
    void setLength(double);
    void setWidth(double);

    // Accessors (Getters)
    double getLength() const;
    double getWidth() const;
    double getArea() const;
};

// ----- Member function definitions -----

// Sets the rectangle's length
void Rectangle::setLength(double l)
{
    if (l > 0)
        length = l;
    else
    {
        cout << "Invalid length. Setting to 0.\n";
        length = 0;
    }
}

// Sets the rectangle's width
void Rectangle::setWidth(double w)
{
    if (w > 0)
        width = w;
    else
    {
        cout << "Invalid width. Setting to 0.\n";
        width = 0;
    }
}

// Returns the length
double Rectangle::getLength() const
{
    return length;
}

// Returns the width
double Rectangle::getWidth() const
{
    return width;
}

// Calculates and returns the area
double Rectangle::getArea() const
{
    return length * width;
}

// ----- Main function -----
int main()
{
    double rectLength, rectWidth;
    Rectangle rect;

    cout << fixed << setprecision(2);

    // Get the length from the user
    cout << "Enter the rectangle length: ";
    cin >> rectLength;
    rect.setLength(rectLength);

    // Get the width from the user
    cout << "Enter the rectangle width: ";
    cin >> rectWidth;
    rect.setWidth(rectWidth);

    // Display rectangle details
    cout << "\nRectangle Details:\n";
    cout << "Length: " << rect.getLength() << endl;
    cout << "Width:  " << rect.getWidth() << endl;
    cout << "Area:   " << rect.getArea() << endl;

    return 0;
}