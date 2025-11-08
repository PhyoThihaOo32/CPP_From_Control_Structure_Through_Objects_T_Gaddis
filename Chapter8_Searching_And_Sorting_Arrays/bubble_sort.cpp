/*
This program uses the bubble sort algorithm to sort an array in ascending order.
*/

#include <iostream>

using namespace std;

void show_array(int[], int);
void sort_array(int[], int);

int main()
{
    int randomNum[12] = {42, 7, 89, 23, 56, 18, 91, 63, 34, 77, 10, 52};

    show_array(randomNum, 12);
    sort_array(randomNum, 12);
    show_array(randomNum, 12);

    return 0;
}

void sort_array(int array[], int size)
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