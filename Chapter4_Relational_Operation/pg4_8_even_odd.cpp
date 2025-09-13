/*
This program check if the number is even or odd number.
*/

#include <iostream>

using namespace std;

int main()
{

    int num;

    // Get a number from user
    cout << "What is your number?" << endl;
    cin >> num;

    // check if even or odd
    if (num % 2 == 0) // all relational operators have left to right associativity
        cout << "Even!" << endl;
    else
        cout << "Odd!" << endl;

    return 0;
}