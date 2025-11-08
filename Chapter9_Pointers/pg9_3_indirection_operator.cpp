/*
This program demonstrates the use of the indirection operator.
Note: When the indirection operator (*) is placed infront of the pointer variable name, it dereferences the pointer.
When you are working with a dereferenced pointer, you are actually working with the value the pointer is pointing to.
*/

#include <iostream>

using namespace std;

int main()
{

    int x = 10;
    int *ptr = nullptr; // pointer variable, can point to int
    ptr = &x;           // storing the address of x

    cout << "Using indirection operator to print the value of x: " << endl;
    cout << *ptr << endl;

    cout << "Using indirection operator to assign new value to x: " << endl;
    *ptr = 100;
    cout << x << endl;
    cout << *ptr << endl;

    return 0;
}
