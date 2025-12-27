/*
    This program demonstrates how the assignment (=) operator works with class objects.

    The '=' operator can:
      1. **Initialize** a new object with another object's data (e.g., Rectangle r2 = r1;)
      2. **Assign** one existing object’s data to another existing object (e.g., r1 = r2;)

    By default, C++ performs a *memberwise copy* — each data member in the source object
    is copied into its corresponding member in the target object.
*/

#include <iostream>
#include "Rectangle.h"
using namespace std;

int main()
{
    // Create two Rectangle objects with different dimensions
    Rectangle rect1{11.5, 12.5};
    Rectangle rect2{22.4, 30.0};

    cout << "=== INITIAL RECTANGLES ===\n";
    cout << "Rectangle 1:\n";
    cout << "  Length: " << rect1.getLength() << "\n";
    cout << "  Width : " << rect1.getWidth() << "\n\n";

    cout << "Rectangle 2:\n";
    cout << "  Length: " << rect2.getLength() << "\n";
    cout << "  Width : " << rect2.getWidth() << "\n\n";

    // Perform assignment between two existing objects
    rect1 = rect2; // memberwise copy

    cout << "=== AFTER ASSIGNMENT (rect1 = rect2) ===\n";
    cout << "Rectangle 1:\n";
    cout << "  Length: " << rect1.getLength() << "\n";
    cout << "  Width : " << rect1.getWidth() << "\n\n";

    cout << "Rectangle 2:\n";
    cout << "  Length: " << rect2.getLength() << "\n";
    cout << "  Width : " << rect2.getWidth() << "\n\n";

    cout << "✅ Assignment completed successfully.\n";

    return 0;
}