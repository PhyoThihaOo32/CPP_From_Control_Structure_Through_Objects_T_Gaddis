/*
This program uses a static local variable.
*/

#include <iostream>

using namespace std;

// function prototype
void increaseNumber();

int main()
{
    for (int count = 0; count < 10; count++)
    {
        increaseNumber();
    }

    return 0;
}

// this function increase a number by 1
void increaseNumber()
{
    static int number; // auto initialized to zero // static local variable is only initialized once in the program lifetime

    cout << number++ << endl;
}