/*
This program uses a function to duplicate an int array of any size and display the arrays.
*/

#include <iostream>

using namespace std;

int *duplicateArray(const int *, int);
void displayArray(const int[], int);

int main()
{
    // define the const for the array size
    const int SIZE1 = 5, SIZE2 = 7,
              SIZE3 = 10;

    // difine three arrays of different sizes
    int array1[SIZE1] = {1, 2, 3, 4, 5};
    int array2[SIZE2] = {10, 20, 30, 40, 50, 60, 70};
    int array3[SIZE3] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};

    // define three pointers for the duplicte arrays
    int *dup1 = nullptr, *dup2 = nullptr, *dup3 = nullptr;

    // duplicate the array
    dup1 = duplicateArray(array1, SIZE1);
    dup2 = duplicateArray(array2, SIZE2);
    dup3 = duplicateArray(array3, SIZE3);

    // display the original arrays
    cout << "Here are the original array contents:" << endl;
    displayArray(array1, SIZE1);
    displayArray(array2, SIZE2);
    displayArray(array3, SIZE3);

    // display the new array
    cout << "Here are the duplicated array contents:" << endl;
    displayArray(dup1, SIZE1);
    displayArray(dup2, SIZE2);
    displayArray(dup3, SIZE3);

    // free the dynamically allocated memory and set the pointer to 0
    delete[] dup1;
    delete[] dup2;
    delete[] dup3;

    dup1 = nullptr;
    dup2 = nullptr;
    dup3 = nullptr;

    return 0;
}

// this function accept an array and its size as an arguments and duplicate the array
int *duplicateArray(const int *arrayPtr, int size)
{

    // validate the size
    if (size <= 0)
        return nullptr;

    int *newArray = new int[size]; // dyn allocate memory for int array of [size]

    // copy the array content to new array
    for (int i = 0; i < size; i++)
    {
        *(newArray + i) = *(arrayPtr + i);
        // newArray[i] = arrayPtr[i]
    }

    // return the pointer to new array
    return newArray;
}

// this function diplay the content of the array
void displayArray(const int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}