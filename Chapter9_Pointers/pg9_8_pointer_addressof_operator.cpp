/*
This program use the address of each element in the array.
*/

#include <iostream>

using namespace std;

int main()
{

    const int SIZE = 5;
    int numbers[SIZE] = {11, 22, 33, 84, 15};

    int *iptr = nullptr;

    for (int i = 0; i < SIZE; i++)
    {
        iptr = &numbers[i];
        cout << "Adress of " << *iptr << " :" << iptr << endl;
    }

    return 0;
}