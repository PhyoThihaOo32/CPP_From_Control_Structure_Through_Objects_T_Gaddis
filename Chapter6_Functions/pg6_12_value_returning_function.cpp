/*
Functions that return a value are known as value_returning functions.
Several arguments may be passed into a function, only one value may be returned from it.
When you call the value-returning function, you usually want to do something meaningful with the value
it returns.
You can use the function's return value anywhere that you can use a regular value of the same data type.
*/

#include <iostream>

using namespace std;

// function prototype
int sum(int, int);

int main()
{
    // call function sum
    cout << sum(3, 2) << endl;

    cout << sum(sum(2, 2), sum(2, 2)) << endl;

    return 0;
}

// this function add two int-numbers and return the result

int sum(int num1, int num2)
{

    return (num1 + num2);
}