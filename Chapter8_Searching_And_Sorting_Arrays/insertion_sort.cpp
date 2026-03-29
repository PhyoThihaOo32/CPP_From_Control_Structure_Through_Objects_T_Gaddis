/*
Insertion Sort Algorithm
*/

#include <iostream>

using namespace std;

void insertion_sort(int[], int);

int main()
{

    int arr[] = {8, 2, 7, 4, 5, 1, 9, 3};
    int size = 8;

    insertion_sort(arr, size);
    for (int &num : arr)
    {
        cout << num << endl;
    }

    return 0;
}

void insertion_sort(int arr[], int size)
{
    // 5 , 3, 4, 1
    for (int i = 1; i < size; i++)
    {                     // start from index 1 (second element) - the first element index 0 is already sorted
        int key = arr[i]; // element to insert
        int j = i - 1;    // compare with previous element
        while (j >= 0 && arr[j] > key)
        {
            // j >= 0 stay inside the array
            // shift only if the element is bigger than key
            arr[j + 1] = arr[j];
            j--;
            // before 5 , 3
            // after  5 , 5
        }
        arr[j + 1] = key; // put the key in correct position
    }
}