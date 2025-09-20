/*
This is a simple interger arithmetic calculator program.
This program ask two interger from the user. Display the Operation and Menu and Perform the desired operation.
[if the operation input is not valid - will ask the user one more time to type valid value, or else program will stop.]
*/

#include <iostream>

using namespace std;

int main()
{

    int num1, num2;
    char operator_option;

    // get the user numbers
    cout << "Type an integer for the first operand: ";
    cin >> num1;
    cout << "Type an integer for the second operand: ";
    cin >> num2;

    // diplay the menu
    cout << "Please type the correct operation input. (A/S/M - a/s/m)" << endl;
    cout << "A - for addition.\n"
         << "S - for subtraction.\n"
         << "M - for multiplication.\n"
         << "D - for division.\n";
    cin >> operator_option;

    // check if the valid input
    if (!(operator_option == 'A' || operator_option == 'a' || operator_option == 'S' || operator_option == 's' ||
          operator_option == 'M' || operator_option == 'm' || operator_option == 'D' || operator_option == 'd'))
    {
        cout << "Please type the correct operation input. (A/S/M - a/s/m)";
        cin >> operator_option;
    }

    if (operator_option == 'A' || operator_option == 'a')
    {
        cout << num1 << " + " << num2 << " = " << (num1 + num2) << endl;
    }
    else if (operator_option == 'S' || operator_option == 's')
    {
        cout << num1 << " - " << num2 << " = " << (num1 - num2) << endl;
    }
    else if (operator_option == 'M' || operator_option == 'm')
    {
        cout << num1 << " * " << num2 << " = " << (num1 * num2) << endl;
    }
    else if (operator_option == 'D' || operator_option == 'd')
    {
        if (num2 == 0)
        {
            cout << "You can't divide with Zero.";
        }
        else
        {
            cout << num1 << " / " << num2 << " = " << (num1 / num2) << endl;
        }
    }
    else
    {
        cout << "That ws not an option." << endl;
    }

    return 0;
}