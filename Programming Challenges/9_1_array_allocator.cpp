/*
This program demonstrates dynamic memory allocation for an integer array.
It asks the user how many elements to allocate, initializes the array,
displays its contents, and then deallocates the memory.
*/

#include <iostream>
using namespace std;

// Function prototypes
int *dynamicArray(int);
void initializeArray(int *, int);
void showArray(int *, int);

int main()
{
    int number;         // number of elements
    int *ptr = nullptr; // pointer to hold the dynamic array

    cout << "How many elements: ";
    cin >> number;

    // Dynamically allocate array
    ptr = dynamicArray(number);

    // Initialize array with user input
    initializeArray(ptr, number);

    // Display array elements
    cout << "\nArray contents: ";
    showArray(ptr, number);

    // Free dynamically allocated memory
    delete[] ptr;
    ptr = nullptr;

    return 0;
}

// Function to dynamically allocate array
int *dynamicArray(int n)
{
    return new int[n]; // return pointer to array
}

// Function to initialize array with user input
void initializeArray(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Set element " << i << " to: ";
        cin >> *(array + i); // equivalent to array[i]
    }
}

// Function to display array elements
void showArray(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}