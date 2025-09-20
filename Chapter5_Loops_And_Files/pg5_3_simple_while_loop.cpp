/*
Loop is a control structure that causes a statement or group of statements to repeat.
This program demonstrate a simple while loop.
*/

#include <iostream>

using namespace std;

int main()
{

    int number = 1; // loop control variable

    while (number <= 5) // loop header
    {
        cout << number << " loop." << endl; // loop body
        ++number;                           // each repetition is called iteration
    }

    cout << "Loop ended." << endl;

    return 0;
}