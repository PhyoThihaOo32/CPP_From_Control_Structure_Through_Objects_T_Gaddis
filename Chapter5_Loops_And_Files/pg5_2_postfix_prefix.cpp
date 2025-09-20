/*
This program demonstrates the prefix and postfix modes of the increment and decrement operators.
*/

#include <iostream>

using namespace std;

int main()
{

    int num = 4;

    cout << num << endl;
    cout << num++ << endl; // display 4 and then add 1 to num
    cout << ++num << endl; // add 1 to num and then display 6

    int x = 1;
    int y = x++; // 1. assign x value to y and then increment 1 to x

    cout << "y: " << y << "\nx: " << x << endl; // display y = 1 and x = 2

    return 0;
}