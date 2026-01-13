/*
This program demonstrates the use of function templates in C++
to create a generic swap function that works with multiple data types.
---------------------------------------------------------------
• The same function `swapVar()` can swap values of int, char, double, etc.
• The compiler automatically generates a type-specific version at compile time.
*/

#include <iostream>
using namespace std;

// Template definition for the swapVar function
// T represents a generic data type (int, double, char, etc.)
template <class T>
void swapVar(T &var1, T &var2)
{
    T temp = var1; // temporarily hold the first value
    var1 = var2;   // assign the second value to the first
    var2 = temp;   // move the stored first value into the second
}

int main()
{
    char char1, char2;
    int int1, int2;
    double double1, double2;

    // Prompt user input
    cout << "Enter two characters (char1 char2): ";
    cin >> char1 >> char2;

    cout << "Enter two integers (int1 int2): ";
    cin >> int1 >> int2;

    cout << "Enter two doubles (double1 double2): ";
    cin >> double1 >> double2;

    // Display before swapping
    cout << "\nBefore Swapping:" << endl;
    cout << "Char:   " << char1 << " " << char2 << endl;
    cout << "Int:    " << int1 << " " << int2 << endl;
    cout << "Double: " << double1 << " " << double2 << endl;

    // Perform swapping using the template function
    swapVar(char1, char2);
    swapVar(int1, int2);
    swapVar(double1, double2);

    // Display after swapping
    cout << "\nAfter Swapping:" << endl;
    cout << "Char:   " << char1 << " " << char2 << endl;
    cout << "Int:    " << int1 << " " << int2 << endl;
    cout << "Double: " << double1 << " " << double2 << endl;

    return 0;
}

/*
Summary:
--------
• The template function `swapVar()` works for any data type.
• The compiler creates specific versions when called:
     - swapVar(int&, int&)
     - swapVar(char&, char&)
     - swapVar(double&, double&)
• Demonstrates compile-time polymorphism (template instantiation).
*/