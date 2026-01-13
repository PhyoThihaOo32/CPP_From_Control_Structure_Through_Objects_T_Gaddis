/*
This program demonstrates an exception being thrown and caught.
*/

#include <iostream>
#include <string>

using namespace std;

double divide(int, int);

int main()
{

    int num1, num2;
    double quotient;

    cout << "Enter numerator: ";
    cin >> num1;

    cout << "Enter Denominator: ";
    cin >> num2;

    try
    {
        quotient = divide(num1, num2);
        cout << "The quotient is: " << quotient << endl;
    }
    catch (string exceptionString)
    {
        cout << exceptionString;
    }

    return 0;
}

double divide(int numerator, int denominator)
{
    if (denominator == 0)
    {
        string exceptionString = "ERROR: Cannot divide by zero.\n";
        throw exceptionString;
    }
    else
    {
        return static_cast<double>(numerator) / denominator;
    }
}