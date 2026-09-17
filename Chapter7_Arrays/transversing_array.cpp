/*
This program demonstrate reversing the elements of an array involves swapping the corresponding
elements of the array. first to last, second with next to last and so on.
*/

#include <iostream>

using namespace std;

int *reverseArray(int[], int);
void reverseArray_2(int[], int);

int main()
{
    const int SIZE = 10;
    int array[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    reverseArray(array, SIZE);

    // print the reverse array
    for (int i = 0; i < SIZE; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    // print the reverse array
    reverseArray_2(array, SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}

int *reverseArray(int array[], int size)
{
    int *ptr = nullptr;
    ptr = array; // pointer to the address of the array
    int temp;    // to hold temporary the first element of the array
    for (int i = 0; i < size / 2; i++)
    {
        temp = ptr[i];
        ptr[i] = ptr[size - 1 - i];
        ptr[size - 1 - i] = temp;
    }

    return ptr;
}

void reverseArray_2(int array[], int size)
{
    int temp;
    for (int i = 0; i < size / 2; i++) // 1 2 3 4 5 6 7 8 9 0
    {
        temp = array[i];
        array[i] = array[size - 1 - i];
        array[size - 1 - i] = temp;
    }
}

/*
Explanation:

When an array is passed to a function, the array name acts like a pointer
to the first element of the original array. Because of this, changes made
to the array inside the function also change the original array in main.

In reverseArray(), ptr is another pointer that points to the same array.
It is not creating a new array. Both ptr and array refer to the same memory.

Returning ptr from reverseArray() is not necessary in this case because
the original array has already been modified directly.

The second function, reverseArray_2(), is simpler because it directly
modifies the array and does not return anything.

A pointer return value would be more useful if the function created a new
array and returned the address of that new array.
*/

/*
Explanation:

When a function creates an array using new, the array is allocated in
dynamic memory (heap memory).

Example:
int* arr = new int[size];

The local pointer variable arr is destroyed when the function ends, but
the array created with new is NOT destroyed automatically.

If the function returns arr, another pointer can still point to that
array after the function has finished.

The dynamically allocated array remains in memory until delete[] is used.

Example:
int* numbers = createArray(5);

delete[] numbers;

If delete[] is never called, the allocated memory is not released during
the program's execution. This is called a memory leak.


In contrast, if an array is created normally inside a function:

int arr[5];

the array is a local array. It is destroyed automatically when the
function ends.

Returning a pointer to that local array is unsafe because the array no
longer exists after the function returns. The returned pointer would be
a dangling pointer.

So:

new int[size]  -> remains in memory after the function ends
                  until delete[] is called

int arr[size]  -> local array, automatically destroyed when
                  the function ends
*/