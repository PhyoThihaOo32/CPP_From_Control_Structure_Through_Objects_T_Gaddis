/*
This program checks if two arrays are reverses of one another.
*/

#include <iostream>
using namespace std;

// Function prototype
bool isReverse(int[], int[], int);
void reverse(int[], int);

int main()
{
    const int SIZE = 7;
    int array1[SIZE] = {1, 2, 3, 4, 5, 6, 7};
    int array2[SIZE] = {7, 6, 5, 4, 3, 2, 1};

    if (isReverse(array1, array2, SIZE))
    {
        cout << "The arrays are reverse of each other." << endl;
    }
    else
    {
        cout << "The arrays are NOT reverse of each other." << endl;
    }

    reverse(array1, SIZE);
    for (int number : array1)
    {
        cout << number << " ";
    }

    return 0;
}

// This function checks if array2 is the reverse of array1
bool isReverse(int array1[], int array2[], int size)
{
    for (int i = 0, k = size - 1; i < size; i++, k--)
    {
        if (array1[i] != array2[k])
        {
            return false; // As soon as one pair doesn’t match, return false
        }
    }
    return true; // All pairs matched
}

void reverse(int array[], int size)
{
    int temp;
    for (int i = 0; i < size / 2; i++)
    {
        temp = array[i];
        array[i] = array[size - 1 - i];
        array[size - 1 - i] = temp;
    }
}