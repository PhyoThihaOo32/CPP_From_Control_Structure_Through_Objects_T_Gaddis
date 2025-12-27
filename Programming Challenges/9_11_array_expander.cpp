/*
This program expands an existing array to twice its size.
The new array:
  - Copies all elements from the old array
  - Fills the rest with zeros
  - Returns a pointer to the new dynamically allocated array
It also reverses the original array into a new dynamic array.
*/

#include <iostream>
using namespace std;

// Function prototypes
int *expandArray(const int *, int);
int *reverseArray(const int *, int);
void showArray(const int *, int);

int main()
{
    const int SIZE = 10;
    int oldArray[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "Original array:\n";
    showArray(oldArray, SIZE);

    // Expand array
    int *expandedArrayPtr = expandArray(oldArray, SIZE);
    cout << "\nExpanded array:\n";
    showArray(expandedArrayPtr, SIZE * 2);

    // Reverse array
    int *reversedArrayPtr = reverseArray(oldArray, SIZE);
    cout << "\nReversed array:\n";
    showArray(reversedArrayPtr, SIZE);

    // Free dynamically allocated memory
    delete[] expandedArrayPtr;
    delete[] reversedArrayPtr;

    expandedArrayPtr = nullptr;
    reversedArrayPtr = nullptr;

    return 0;
}

// Expands the array to twice its size and fills new elements with zeros
int *expandArray(const int *oldArray, int size)
{
    int newSize = size * 2;
    int *newArray = new int[newSize];

    for (int i = 0; i < newSize; i++)
        *(newArray + i) = (i < size) ? *(oldArray + i) : 0;

    return newArray;
}

// Reverses the array elements and returns a pointer to the new reversed array
int *reverseArray(const int *array, int size)
{
    int *revArray = new int[size];

    for (int i = 0; i < size; i++)
        *(revArray + i) = *(array + (size - 1 - i));

    return revArray;
}

// Displays array elements
void showArray(const int *array, int size)
{
    for (int i = 0; i < size; i++)
        cout << *(array + i) << " ";
    cout << endl;
}