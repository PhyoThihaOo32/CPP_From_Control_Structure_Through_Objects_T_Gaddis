/*
The address operator & returns the memory address of a variable.
The address of the variable x is displayed in hexadecimal.
Each byte of memory has a unique address. A variable's address is the address of the first byte allocated to that variable.
*/

#include <iostream>

using namespace std;

int main()
{

    int x = 25;

    cout << "The address of x is: " << &x << endl;
    cout << "The size of x is: " << sizeof(x) << endl;
    cout << "The value of x is: " << x << endl;

    return 0;
}