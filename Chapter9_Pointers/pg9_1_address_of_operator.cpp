/*
This program demonstrates:
 - How to use the address-of operator (&)
 - How to create and use pointers
 - How dereferencing (*) works to access or modify variable values
 - Type conversion effects when assigning through pointers

Each variable's address, value, and pointer behavior is displayed clearly.
*/

#include <iostream>
using namespace std;

int main()
{
    // Step 1: Declare and initialize normal variables
    int x = 25;    // integer variable
    float y = 2.5; // floating-point variable

    // Step 2: Declare pointer variables
    int *iptr = &x;   // iptr points to x (stores the memory address of x)
    float *fptr = &y; // fptr points to y (stores the memory address of y)

    // Step 3: Display original values using dereferencing
    cout << "Original values:" << endl;
    cout << "*iptr (x) = " << *iptr << endl; // Dereference iptr → prints x’s value
    cout << "*fptr (y) = " << *fptr << endl; // Dereference fptr → prints y’s value
    cout << endl;

    // Step 4: Demonstrate pointer-based assignments
    // The value of y (2.5) is assigned to x through pointer dereferencing.
    *iptr = *fptr; // int = float → implicit conversion → fractional part dropped (x becomes 2)

    // The new value of x (2) is assigned to y through pointer dereferencing.
    *fptr = *iptr; // float = int → implicit conversion → becomes 2.0

    // Step 5: Display updated values
    cout << "After pointer assignments:" << endl;
    cout << "*iptr = " << *iptr << "  (x = " << x << ")" << endl;
    cout << "*fptr = " << *fptr << "  (y = " << y << ")" << endl;
    cout << endl;

    // Step 6: Display memory information
    cout << "Memory Information:" << endl;
    cout << "The address of x (&x): " << &x << endl;
    cout << "The address of y (&y): " << &y << endl;
    cout << "The size of x (sizeof(x)): " << sizeof(x) << " bytes" << endl;
    cout << "The size of y (sizeof(y)): " << sizeof(y) << " bytes" << endl;
    cout << endl;

    // Step 7: Show pointer variable contents (addresses they store)
    cout << "Pointer Info:" << endl;
    cout << "iptr holds address: " << iptr << " -> value: " << *iptr << endl;
    cout << "fptr holds address: " << fptr << " -> value: " << *fptr << endl;

    return 0;
}