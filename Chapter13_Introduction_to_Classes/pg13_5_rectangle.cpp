#include <iostream>
#include "Rectangle.h"
#include <iomanip>

using namespace std;

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