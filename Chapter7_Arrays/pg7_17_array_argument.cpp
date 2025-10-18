/*
This program demonstrate an array being passed to a function.
*/

#include <iostream>

using namespace std;

void showValue(int[], int);

int main()
{

    const int SIZE = 5;
    int numbers[SIZE] = {1, 2, 3, 0, 5};

    showValue(numbers, SIZE);
    // the address of the numbers array is passe as the first arguments
    // the num(special variable) is then used to reference the numbers array

    return 0;
}

// the reason there is no size declarator inside the brackets of nums is
// because nums is not actually an array. It is a special variable that can accept the address of an array.
// when an array is passed to a function, it is not passed by value, but passed by reference.
void showValue(int num[], int size)
{
    for (int index = 0; index < size; index++)
    {
        cout << num[index] << " ";
    }
}