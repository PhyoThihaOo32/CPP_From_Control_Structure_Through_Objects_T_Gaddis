/*
This program demonstrates an overloaded [] operator.
*/

#include <iostream>
#include "IntArray.h"

using namespace std;

int main()
{

    const int SIZE = 10;

    // define array with 10 elements
    IntArray myArray(SIZE);

    // store value in the array
    for (int i = 0; i < SIZE; i++)
    {
        myArray[i] = i * 2;
    }

    // display the values in the array
    for (int i = 0; i < SIZE; i++)
    {
        cout << myArray[i] << " ";
    }
    cout << endl;

    // use the standart + operator on array elements
    for (int i = 0; i < SIZE; i++)
    {
        myArray[i] = myArray[i] + 10;
    }

    // display the value in the array
    for (int i = 0; i < SIZE; i++)
    {
        cout << myArray[i] << " ";
    }
    cout << endl;

    // use the standart ++operator on array elements
    for (int i = 0; i < SIZE; i++)
    {
        myArray[i]++;
    }

    // display the value in the array
    for (int i = 0; i < SIZE; i++)
    {
        cout << myArray[i] << " ";
    }
    cout << endl;

    // attempt to use the invalid subscript
    cout << "Attempting to use the invalid subscript" << endl;
    myArray[SIZE + 1] = 0;

    return 0;
}