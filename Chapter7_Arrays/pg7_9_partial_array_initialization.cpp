/*
When array is being initialized, C++ does not require a value for every element.
Note: When a array is being partialy initialized, the uninitialized elements will be set to zero.
It is possible to define an array without specifying its size, as long as you provide an initialization list.
This program demonstrate partial array initialization.
*/

#include <iostream>

using namespace std;

int main()
{

    const int ARRAY_SIZE = 10;
    int number_array[ARRAY_SIZE] = {1, 2, 3, 4};

    for (auto number : number_array)
    {
        cout << number << " ";
    }

    return 0;
}
