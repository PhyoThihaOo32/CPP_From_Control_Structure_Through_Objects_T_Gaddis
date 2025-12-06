/*
This program demonstrates a simple Rectangle class.
It shows encapsulation, const member functions,
and use of const char* for simple string labels.
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

    // Display rectangle info
    void showRect(const char *roomName) const;
};

// ----- Member function definitions -----

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

// Display rectangle dimensions and area
void Rectangle::showRect(const char *roomName) const
{
    cout << "\n"
         << roomName << " Dimensions:\n"; // Because cout is overloaded to treat a char* as the start of a C-string, not just a raw address.
                                          // It keeps printing characters until it finds the null terminator ('\0').
    cout << "Length: " << setw(6) << length << " ft\n";
    cout << "Width:  " << setw(6) << width << " ft\n";
    cout << "Area:   " << setw(6) << getArea() << " sq ft\n";
}

// ----- Main function -----
int main()
{
    double number;
    Rectangle kitchen, bedroom, livingRoom;

    cout << fixed << setprecision(2);

    // Get kitchen dimensions
    cout << "Enter the kitchen length: ";
    cin >> number;
    kitchen.setLength(number);

    cout << "Enter the kitchen width: ";
    cin >> number;
    kitchen.setWidth(number);

    // Get bedroom dimensions
    cout << "\nEnter the bedroom length: ";
    cin >> number;
    bedroom.setLength(number);

    cout << "Enter the bedroom width: ";
    cin >> number;
    bedroom.setWidth(number);

    // Get living room dimensions
    cout << "\nEnter the living room length: ";
    cin >> number;
    livingRoom.setLength(number);

    cout << "Enter the living room width: ";
    cin >> number;
    livingRoom.setWidth(number);

    // Display room details
    cout << "\n========================================";
    kitchen.showRect("Kitchen");
    bedroom.showRect("Bedroom");
    livingRoom.showRect("Living Room");
    cout << "========================================\n";

    return 0;
}