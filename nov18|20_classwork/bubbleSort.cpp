/*
This program demonstrate bubble sort algorithm.
*/

#include <iostream>

using namespace std;

void bubbleSort(float[], int);
void selectionSort(float[], int);
void printArray(float[], int);

int main()
{
    const int SIZE = 10;
    float arr[SIZE] = {23.5, 67.2, 12.8, 45.9, 89.1, 34.6, 78.3, 56.7, 10.4, 92.0};

    cout << "Before Sorting" << endl;
    printArray(arr, SIZE);
    // bubbleSort(arr, SIZE);
    bubbleSort(arr, SIZE);
    cout << "After Sorting" << endl;
    printArray(arr, SIZE);

    return 0;
}

void bubbleSort(float array[], int size) // arrays are passed into function by references
{
    bool swap_flag;
    do
    {
        swap_flag = false;
        for (int i = 0; i < size - 1; i++)
        {
            if (array[i] > array[i + 1])
            {                          // if first element is greater than second element
                float temp = array[i]; // then use the two element
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swap_flag = true;
            }
        }

    } while (swap_flag == true);
}

void selectionSort(float array[], int size)
{
    for (int startScan = 0; startScan < size - 1; startScan++)
    {
        int index = startScan;
        int minIndex = startScan;
        float minValue = array[startScan];
        for (index = startScan + 1; index < size; index++)
        {
            if (array[index] < minValue)
            {
                minValue = array[index];
                minIndex = index; // after inner loop we found the min index already
            }
        }

        // minValue already has the value of min. It can be the 'temp' for swapping
        array[minIndex] = array[startScan];
        array[startScan] = minValue;
    }
}

void printArray(float array[], int size) // think of parameter like variables when writing a function
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}
