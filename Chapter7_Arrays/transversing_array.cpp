/*
This program demonstrate reversing the elements of an array involves swapping the corresponding
elements of the array. first to last, second with next to last and so on.
*/

#include <iostream>

using namespace std;

int *reverseArray(int[], int);

int main()
{
    const int SIZE = 10;
    int array[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    reverseArray(array, SIZE);

    // print the reverse array
    for (int i = 0; i < SIZE; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}

int *reverseArray(int array[], int size)
{
    int *ptr = nullptr;
    ptr = array; // pointer to the address of the array
    int temp;    // to hold temporary the first element of the array
    for (int i = 0; i < size / 2; i++)
    {
        temp = ptr[i];
        ptr[i] = ptr[size - 1 - i];
        ptr[size - 1 - i] = temp;
    }

    return ptr;
}