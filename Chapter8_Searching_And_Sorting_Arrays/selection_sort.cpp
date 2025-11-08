/*
This program uses the bubble sort algorithm to sort an array in ascending order.
*/

#include <iostream>

using namespace std;

void show_array(int[], int);
void bubble_sort_array(int[], int);
void selection_sort_array(int[], int);

int main()
{
    int randomNum[12] = {42, 7, 89, 23, 56, 18, 91, 63, 34, 77, 10, 52};

    show_array(randomNum, 12);
    selection_sort_array(randomNum, 12);
    show_array(randomNum, 12);

    return 0;
}

void bubble_sort_array(int array[], int size)
{
    bool isSwap;
    int temp;

    do
    {
        isSwap = false;
        for (int count = 0; count < (size - 1); count++)
        {
            if (array[count] > array[count + 1])
            {
                temp = array[count + 1];
                array[count + 1] = array[count];
                array[count] = temp;
                isSwap = true;
            }
        }
    } while (isSwap);
}

void show_array(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void selection_sort_array(int array[], int size)
{
    for (int startScan = 0; startScan < size - 1; startScan++)
    {
        int minValue = array[startScan];
        int minIndex = startScan;
        for (int index = startScan + 1; index < size; index++)
        {
            if (array[index] < minValue)
            {
                minValue = array[index];
                minIndex = index;
            }
        }
        array[minIndex] = array[startScan];
        array[startScan] = minValue;
    }
}