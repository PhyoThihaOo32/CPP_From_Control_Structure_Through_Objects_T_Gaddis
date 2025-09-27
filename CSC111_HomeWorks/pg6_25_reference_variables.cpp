/*
This program demonstrate the use of reference variables.
Reference variables allow a function to acess the parameter's original argument.
Changes to the parameter are also made to the arguments.
Place ampersand & infront of the name.
When reference parameter is used, it is said that argument is passed by reference.
*/

#include <iostream>

using namespace std;

void getNumber(double &number);
double square(double &);
void doubleNumber(double &);
double sumTwoNumbers(double &);

int main()
{

    double number;

    getNumber(number); // this function use reference parameter - which call the original argument: number and store the user input into original variable

    cout << "You entered number: " << number << endl;

    cout << number << " * " << number << " :" << square(number) << endl;

    cout << "Now the original number is: " << number << endl;

    return 0;
}

// this function get a double data type number from the user
void getNumber(double &number)
{
    cout << "Enter a number: ";
    cin >> number;
}
// this function calculate the square of the number
double square(double &number)
{
    number = number * number;
    return number;
}

// this function double a number
void doubleNumber(double &number)
{
    number *= 2;
}

double sumTwoNumbers(double &sum)
{
    double number1, number2;
    cout << "Enter two numbers: ";
    cin >> number1 >> number2;
    return sum = number1 + number2;
}