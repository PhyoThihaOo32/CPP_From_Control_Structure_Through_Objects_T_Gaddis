/*
This is a simple interger arithmetic calculator program. [ but using switch statment]
This program ask two interger from the user. Display the Operation and Menu and Perform the desired operation.
[if the operation input is not valid - will ask the user one more time to type valid value, or else program will stop.]
*/

#include <iostream>

using namespace std;

int main()
{

    int num1, num2;
    char operator_option;
    char user_option;
    bool isContinue = true; // flag

    while (isContinue)
    {

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

        switch (operator_option)
        {
        case 'A':
        case 'a':
            cout << num1 << " + " << num2 << " = " << (num1 + num2) << endl;
            break;
        case 'S':
        case 's':
            cout << num1 << " - " << num2 << " = " << (num1 - num2) << endl;
            break;
        case 'M':
        case 'm':
            cout << num1 << " * " << num2 << " = " << (num1 * num2) << endl;
            break;
        case 'D':
        case 'd':
            if (num2 == 0)
            {
                cout << "You can't divide with Zero.";
            }
            else
            {
                cout << num1 << " / " << num2 << " = " << (static_cast<float>(num1) / num2) << endl;
            }
            break;
        default:
            cout << "\bInvalid Operator Input." << endl;
        }

        cout << "Enter 'Q' or 'q'  to quit. Or Else to continue.";
        cin >> user_option;

        user_option == 'Q' || user_option == 'q' ? isContinue = false : isContinue = true;
    }
    return 0;
}