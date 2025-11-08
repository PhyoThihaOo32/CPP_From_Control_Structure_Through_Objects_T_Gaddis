/*
The automatic conversation mean that an element in an array can be retireved by using its subscript
or by adding its subscript to a pointer to the array.
The parentheses are critical when adding values to pointers.
*/

#include <iostream>

using namespace std;

int main()
{

    const int SIZE = 5;
    int numbers[SIZE];

    // get user input and store it in array
    for (int count = 0; count < SIZE; count++)
    {
        cout << "Enter number " << count + 1 << " :";
        cin >> *(numbers + count); // using pointer notation instead of array subscripts
    }

    // display the numbers
    for (int number : numbers)
    {
        cout << number << " ";
    }

    return 0;
}