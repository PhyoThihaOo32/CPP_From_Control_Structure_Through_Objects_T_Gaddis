/*
The return statement causes the function to end immdediately.
This program demonstrate the use of return statement in function.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void division(double, double);

int main()
{

    division(2, 0);

    return 0;
}

void division(double num1, double num2)
{

    // get num1 and num2 from the user
    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    // if denominator is zero, terminate the function
    if (num2 == 0.0)
    {
        cout << "Denominator can't be zero." << endl;

        return; // return statement terminate the function immediately
    }

    cout << num1 << " / " << num2 << " = " << num1 / num2;
}