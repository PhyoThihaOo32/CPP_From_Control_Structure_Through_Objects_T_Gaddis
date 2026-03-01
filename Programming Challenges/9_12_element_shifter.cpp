#include <iostream>
using namespace std;

// Function prototype
// Accepts a pointer to the original array and its size
// Returns a pointer to a new shifted array
int *elementShifter(const int *oldArray, int size);

int main()
{
    const int SIZE = 5;

    // Original array
    int oldArray[SIZE] = {1, 2, 3, 4, 5};

    // Call function to create new shifted array
    int *newArray = elementShifter(oldArray, SIZE);

    // Display new array (size is SIZE + 1)
    cout << "Shifted array: ";
    for (int i = 0; i < SIZE + 1; i++)
    {
        cout << newArray[i] << " ";
    }
    cout << endl;

    // Free dynamically allocated memory (VERY IMPORTANT)
    delete[] newArray;

    return 0;
}

// Function definition
int *elementShifter(const int *oldArray, int size)
{
    // Allocate new array that is one element larger
    int *newArray = new int[size + 1];

    // First element is set to 0
    newArray[0] = 0;

    // Copy elements from old array shifted by one position
    for (int i = 1; i < size + 1; i++)
    {
        newArray[i] = oldArray[i - 1];
    }

    // Return pointer to new array
    return newArray;
}