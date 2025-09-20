/*
This program demonstrate the use of muliple statments in for loop.
*/

#include <iostream>

using namespace std;

int main()
{

    int x, y;

    for (x = 1, y = 1; x <= 10; x++, y++)
    {

        cout << x << " * " << y << " = " << (x * y) << endl;
    }

    return 0;
}