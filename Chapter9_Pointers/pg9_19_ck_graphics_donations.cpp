/*
This program shows the donations made to the United Cause by the employees of CK Graphics, Inc.
It displays the donations in order from lowest to highest and in the original order they were received.
*/

#include <iostream>

using namespace std;

// functions prototypes
void arrSelectSort(int *[], int);
void showArray(int[], int);
void showArrPtr(int *[], int);

int main()
{
    const int NUM_DONATIONS = 15; // numbers of donations

    // an array containing the donation amounts
    int donations[NUM_DONATIONS] = {5, 100, 5, 25, 10, 5, 25, 5, 5, 100, 10, 15, 10, 5, 10};

    // an array of pointers to int
    int *arrPtr[NUM_DONATIONS] = {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};

    // Assign the address of each element of donations to arrPtr
    for (int i = 0; i < NUM_DONATIONS; i++)
        arrPtr[i] = &donations[i];

    // sort the elements of the array of pointers
    arrSelectSort(arrPtr, NUM_DONATIONS);

    // display the donations using the array of pointers - in sorted order
    showArrPtr(arrPtr, NUM_DONATIONS);

    // display the donations in their original order
    showArray(donations, NUM_DONATIONS);

    return 0;
}

/*
This function perform ascending order selection sort on arr, which is an array of pointers to int.
*/

void arrSelectSort(int *arrPtr[], int size)
{
    int start, minIndex;
    int *ptr_minEle;

    for (int start = 0; start < size - 1; start++)
    {
        minIndex = start;
        ptr_minEle = arrPtr[minIndex];
        for (int index = start + 1; index < size; index++)
        {
            if (*(arrPtr[index]) < *ptr_minEle)
            {
                ptr_minEle = arrPtr[index];
                minIndex = index;
            }
        }
        arrPtr[minIndex] = arrPtr[start];
        arrPtr[start] = ptr_minEle;
    }
}

/*
This function will show the contents of the array.
*/

void showArray(int array[], int size)
{

    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

// This function will show the contents of the array pointed to by array of pointers.
void showArrPtr(int *arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << *arr[i] << " ";
    }
    cout << endl;
}