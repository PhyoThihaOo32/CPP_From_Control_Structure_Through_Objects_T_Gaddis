/*
This program stores the address of a variable in a pointer.
*/

#include <iostream>

using namespace std;

int main()
{

    int x = 24;
    int *ptr = nullptr; // pointer variable can point to an int

    ptr = &x; // store the address of x

    cout << "The value of x is " << x << endl;
    cout << "The address of x is " << ptr << endl;

    return 0;
}