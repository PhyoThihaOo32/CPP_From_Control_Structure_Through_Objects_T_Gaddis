#include <iostream>
using namespace std;

/*
This function takes two already-sorted parts of the array and merges them back together in sorted order.

Examples:
    left part: [3,8]
    right part: [1,5]
After merge:
    [1,3,5,8]
*/

void merge(int arr[], int left, int mid, int right)
{
    // Find the size of the left temporary array
    int sizeLeft = mid - left + 1;

    // Find the size of the right temporary array
    int sizeRight = right - mid;

    // creates temporary arrays
    int leftArr[sizeLeft];
    int rightArr[sizeRight];

    // Copy values from the original array into the left temporary array
    for (int i = 0; i < sizeLeft; i++)
    {
        leftArr[i] = arr[left + i];
    }

    // Copy values from the original array into the right temporary array
    for (int j = 0; j < sizeRight; j++)
    {
        rightArr[j] = arr[mid + 1 + j];
    }

    // i tracks the index of leftArr
    int i = 0;

    // j tracks the index of rightArr
    int j = 0;

    // k tracks the index of the original array
    int k = left;

    /*
    Compare elements from leftArr and rightArr
    The smaller value is copied back into the original array.
    This continue until one temporary array is fully copied.
    */
    while (i < sizeLeft && j < sizeRight)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    // if there are remaining values in the left array, copy them back into the original array
    while (i < sizeLeft)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // if there are remaining values in the right array, copy them back into the original array
    while (j < sizeRight)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

/*
mergeSort()
This function recursively splits the array into smaller parts.
Base case:
    If left is not less than right, the section has 0 or 1 elements. A section with one element is already sorted.
Recursive case:
    1. Find the middle.
    2. Sort the left half.
    3. Sort the right half,
    4. Merge both sorted halves.
*/

void mergeSort(int arr[], int left, int right)
{
    // continue only if there is more than one element
    if (left < right)
    {
        // Find the middle index
        int mid = (left + right) / 2;
        // Recursively sort the left half
        mergeSort(arr, left, mid);
        // Recursively sort the right half
        mergeSort(arr, mid + 1, right);
        // Merge the two sorted halves
        merge(arr, left, mid, right);
    }
}

/*

    printArray()

    -------------------------

    This helper function prints all elements of the array.

*/

void printArray(int arr[], int size)

{

    for (int i = 0; i < size; i++)

    {

        cout << arr[i] << " ";
    }

    cout << endl;
}

int main()

{

    // Original unsorted array
    int arr[] = {8, 3, 5, 1};

    // Find the number of elements in the array
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, size);

    // Sort the array using merge sort
    mergeSort(arr, 0, size - 1);

    cout << "Sorted array: ";
    printArray(arr, size);

    return 0;
}
