/*
A pointer can be used as a function parameter. It gives the function access to the original argument,
much like a reference parameter does.
*/

#include <iostream>

using namespace std;

void getNum(int *);
void doubleNum(int *);

int main()
{

    int number;

    getNum(&number); // the address of the number used as argument
    doubleNum(&number);

    cout << number << endl;

    return 0;
}

// function get the integer number from the user
void getNum(int *number)
{
    cout << "Enter a number: " << endl;
    cin >> *number;
    // its critical the indirection operator is used, without it cin would store the user input as the address
    // which will result in erroneous, if not disastrous, result.
}

// function double the value
void doubleNum(int *number)
{
    *number *= 2;
}