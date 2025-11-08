/*
The ++ and -- operator may be used to increment and decrement a pointer variable.
An integer may be added to or subtracted from a pointer variable.(+ , - , +=, -= operators.)
A pointer may be subtracted from another pointer.
*/

#include <iostream>

using namespace std;

int main()
{

    const int SIZE = 3;
    int numbers[SIZE];
    int *iPtr = numbers;

    for (int i = 0; i < SIZE; i++)
    {
        cout << "Enter number " << i + 1 << endl;
        cin >> *iPtr++;
    }

    // set the pointer to the start of the array
    iPtr = numbers;

    // display the numbers in ascending order
    for (int i = 0; i < SIZE; i++)
    {
        cout << *iPtr << " ";
        iPtr++;
    }

    cout << endl;

    // now the pointer is already at the end of the array - but explictly setting the pointer to the end
    iPtr = numbers + SIZE;

    // display the numbers in descending order
    for (int i = 0; i < SIZE; i++)
    {
        iPtr--;
        cout << *iPtr << " ";
    }

    return 0;
}