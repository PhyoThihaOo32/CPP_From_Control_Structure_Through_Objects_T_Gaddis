/*
When only a copy of argument is passed to a function, it is said to passed by value - which means
the function receives a copy of the argument's value and does not have access to the original argument.
*/

// This program demonstrates the passing data by value.

#include <iostream>

using namespace std;

// creating prototype
void change_number_zero(int);

// main function
int main()
{

    int number = 12;

    cout << "Number: " << number << endl;

    // call function chaged_number_zero
    change_number_zero(number);

    // printing out the original number
    cout << "Number: " << number << endl;

    return 0;
}

// definition of function changeNumber
// this function change any argument number to zero and display number
void change_number_zero(int input_number)
{
    input_number = 0;

    // display the number
    cout << "This function has changed the number: " << input_number << endl;
}