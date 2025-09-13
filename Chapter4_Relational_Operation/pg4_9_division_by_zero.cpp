/*
This program demostrate division by zero.
*/

#include <iostream>

using namespace std;

int main()
{

    int num1, num2;

    // Get user input
    cout << "Enter 1st Number(Numerator): " << endl;
    cin >> num1;

    cout << "Enter 2nd Number(Denominator): " << endl;
    cin >> num2;

    if (num2 == 0)
        cout << "Ops! Denominator can't be zero." << endl;
    else
        cout << "Result: " << num1 / num2 << endl;

    return 0;
}