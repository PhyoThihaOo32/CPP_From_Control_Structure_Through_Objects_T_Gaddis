/*
This program demonstrate a pointer variable referencing different variables.
*/

#include <iostream>

using namespace std;

int main()
{

    int x = 10, y = 12, z = 100;

    int *ptr = nullptr; // pointer variable, can point to int

    // showinng the initial contents of x, y, z
    cout << "x: " << x << "\ny: " << y << "\nz: " << z << endl;

    // manipulate the value of x, y, z with pointer
    ptr = &x;    // store the address of x
    *ptr += 100; // add 100 to x

    ptr = &y; // store the address of y
    *ptr = y + 12;

    ptr = &z;
    *ptr = --z;

    // showinng the manipulated contents of x, y, z
    cout << "x: " << x << "\ny: " << y << "\nz: " << z << endl;

    // pointer pointing back to null
    ptr = nullptr;
    

    return 0;
}