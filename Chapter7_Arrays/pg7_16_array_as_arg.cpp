/*
This program passing array element as argument into a function.
*/

#include <iostream>

using namespace std;

void showValue(int);

int main()
{

    const int SIZE = 5;
    int number[SIZE] = {1, 2, 3, 4, 5};

    for (int index = 0; index < SIZE; index++)
    {
        showValue(number[index]);
    }

    return 0;
}

void showValue(int num)
{
    cout << num << " ";
}