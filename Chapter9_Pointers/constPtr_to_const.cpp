/*
const int * const ptr = &value;
Because ptr is a const pointer, we cannot write code that makes the ptr point to anything else.
Because ptr is a pointer to a const, we cannot use it to change the contents of value.
*/

#include <iostream>

using namespace std;

void displayArrayValue(const int *const, int);

int main()
{

    const int SIZE = 10;
    const int NUMBERS[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    displayArrayValue(NUMBERS, SIZE);

    return 0;
}

void displayArrayValue(const int *const ptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << *(ptr + i) << " "; // “ptr + i → compute a new address (temporary)”
                                   // “ptr++ → modify the pointer’s address (permanent)”
    }
    cout << endl;
}