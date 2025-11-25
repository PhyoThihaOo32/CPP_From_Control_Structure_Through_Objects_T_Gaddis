#include <iostream>

using namespace std;

int main()
{

    const int SIZE = 5;
    int num_array[SIZE] = {10, 20, 30, 40, 50};

    int *ptr = &num_array[2];
    num_array[2] = 110;

    cout << *ptr << endl;

    ptr = &num_array[0];

    cout << &num_array[0] << endl;
    cout << num_array + 0 << endl; // same exact memory address
    cout << ptr << endl;
    cout << num_array << endl; // actually, the name of the array is the (constant) pointer

    cout << endl;

    cout << &num_array[1] << endl;
    cout << num_array + 1 << endl; // we can add an integer and calculate the location of the element
    cout << ptr + 1 << endl;

    cout << endl;
    ptr = num_array; // pointing to the first address of the element of the array
    // cout << *ptr << endl;
    // cout << *(ptr + 1) << endl;  // ptr + 1 add the size of one interger
    // cout << *(ptr + 2) << endl;  // not best practice using pointer with array subscript ptr[subscript]
    // cout << *(ptr + 3) << endl;
    // cout << *(ptr + 4) << endl;

    for (int i = 0; i < SIZE; i++)
    {
        cout << *(ptr + i) << " ";
    }

    cout << endl;

    // array subscripting *can* be used, but not usually recommended
    for (int i = 0; i < SIZE; i++)
    {
        cout << ptr[i] << " ";
    }
    cout << endl;

    // pointer arithmetic *can* be used with the array name too but indexing is easier
    for (int i = 0; i < SIZE; i++)
    {
        cout << *(num_array + i) << " ";
    }
    cout << endl;

    //
    for (int i = 0; i < SIZE; i++)
    {
        cout << *ptr << " ";
        ptr++;
    }
    cout << endl;
    ptr = nullptr;

    return 0;
}