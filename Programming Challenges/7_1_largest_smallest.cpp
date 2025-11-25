/*
This program lets the user enter 10 values into an array and then display the largest and smallest values
stored in the array.
*/

#include <iostream>

using namespace std;

int *getArray(int &);
void showArray(int[], int);
int findSmallest(int[], int);
int findLargest(int[], int);

int main()
{
    int size;
    int *pArray = getArray(size);

    showArray(pArray, size);

    cout << findSmallest(pArray, size) << endl;
    cout << findLargest(pArray, size) << endl;

    return 0;
}

int *getArray(int &size)
{

    cout << "How many elements you want for the array? ";
    cin >> size;
    int *ptr = new int[size]; // dynamically allocated int array

    // let the user enter the value into the array
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the value for index: " << i << " :";
        cin >> *(ptr + i);
    }

    return ptr;
}

void showArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int findSmallest(int array[], int size)
{
    int index;
    int smallest = array[0];
    for (index = 1; index < size; index++)
    {
        if (array[index] < smallest)
        {
            smallest = array[index];
        }
    }
    return smallest;
}

int findLargest(int array[], int size)
{
    int largest = array[0];
    for (int i = 1; i < size; i++)
    {
        if (array[i] > largest)
        {
            largest = array[i];
        }
    }
    return largest;
}
