/*
Note: Arrays parameters works very much like reference variables.
They gave the function direct access to the original array.
Any change made with the array parameter are actually made on the original array used as the argument.

Note2: When an array parameter is declared as const, the function is not allowed to make changes to the array's
contents.
*/

#include <iostream>

using namespace std;

void showValue(const int[], int);
void doubleValue(int[], int);

int main()
{
    const int SIZE = 5;
    int number_array[SIZE] = {1, 2, 3, 4, 5};

    // display initial array values
    showValue(number_array, SIZE);

    // double the values of the array
    doubleValue(number_array, SIZE);

    // dispaly the changed values of the array
    showValue(number_array, SIZE);

    return 0;
}

void showValue(const int num[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << num[i] << " ";
    }
    cout << endl;
}

void doubleValue(int num[], int size)
{
    for (int i = 0; i < size; i++)
    {
        num[i] *= 2;
    }
}