/*
This program test if the number is even or odd.
*/

#include <iostream>

using namespace std;

// function prototype
bool isEven(int);

int main()
{
    // variable
    unsigned number;

    // get the number from the user
    cout << "Enter any number: ";
    cin >> number;

    if (isEven(number))
    {
        cout << number << " is an even number." << endl;
    }
    else
    {
        cout << number << " is an odd number." << endl;
    }

    return 0;
}

// this function check if the number is even or odd.
bool isEven(int number)
{
    if (number % 2 == 0)
        return true;

    else
        return false;
}