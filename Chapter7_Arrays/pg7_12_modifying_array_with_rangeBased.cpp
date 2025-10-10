/*
This program demonstrate modifying an array by using range-based for loop.
*/

#include <iostream>

using namespace std;

int main()
{
    const int ARRAY_SIZE = 5;
    int number_array[ARRAY_SIZE];

    for (auto &number : number_array)
    {
        cout << "Enter an number: ";
        cin >> number;
    }

    // display the values in the array
    for (auto number : number_array)
    {
        cout << number << endl;
    }

    return 0;
}
