/*
This program demonstrates a simple Rectangle class.
It shows encapsulation, const member functions,
dynamic allocation using pointers, and total area calculation.
*/

#include <iostream>
#include <iomanip>
using namespace std;

// Rectangle class declaration
class Rectangle
{
private:
    double length = 0;
    double width = 0;

public:
    // Constructors
    Rectangle() = default;
    Rectangle(double l, double w)
    {
        setLength(l);
        setWidth(w);
    }

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
         << roomName << " Dimensions:\n";
    cout << "Length: " << setw(6) << length << " ft\n";
    cout << "Width:  " << setw(6) << width << " ft\n";
    cout << "Area:   " << setw(6) << getArea() << " sq ft\n";
}

// Function to calculate total area of multiple rooms
double totalHouseArea(Rectangle *r1, Rectangle *r2, Rectangle *r3)
{
    return r1->getArea() + r2->getArea() + r3->getArea();
}

// ----- Main function -----
int main()
{
    double number;
    // Create three pointers to store Rectangle objects
    Rectangle *kitchenPtr = nullptr,
              *bedroomPtr = nullptr,
              *livingRoomPtr = nullptr;

    // Dynamically allocate memory
    kitchenPtr = new Rectangle;
    bedroomPtr = new Rectangle;
    livingRoomPtr = new Rectangle;

    cout << fixed << setprecision(2);

    // Get kitchen dimensions
    cout << "Enter the kitchen length: ";
    cin >> number;
    kitchenPtr->setLength(number);

    cout << "Enter the kitchen width: ";
    cin >> number;
    kitchenPtr->setWidth(number);

    // Get bedroom dimensions
    cout << "\nEnter the bedroom length: ";
    cin >> number;
    bedroomPtr->setLength(number);

    cout << "Enter the bedroom width: ";
    cin >> number;
    bedroomPtr->setWidth(number);

    // Get living room dimensions
    cout << "\nEnter the living room length: ";
    cin >> number;
    livingRoomPtr->setLength(number);

    cout << "Enter the living room width: ";
    cin >> number;
    livingRoomPtr->setWidth(number);

    // Display room details
    cout << "\n========================================";
    kitchenPtr->showRect("Kitchen");
    bedroomPtr->showRect("Bedroom");
    livingRoomPtr->showRect("Living Room");
    cout << "========================================\n";

    // Calculate and display total area
    cout << "\nTotal House Area: "
         << totalHouseArea(kitchenPtr, bedroomPtr, livingRoomPtr)
         << " sq ft\n";

    // Deallocate the objects from memory (not the pointers)
    delete kitchenPtr;
    delete bedroomPtr;
    delete livingRoomPtr;

    // Set pointers back to null for safety
    kitchenPtr = bedroomPtr = livingRoomPtr = nullptr;

    return 0;
}