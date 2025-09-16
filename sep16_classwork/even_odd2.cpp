/*
This program check the number even or odd only if the number is positive number.
*/

#include <iostream>

using namespace std;

int main()
{

    int user_number;

    // get user input
    cout << "Enter your number: ";
    cin >> user_number;

    if (user_number > 0)
    {
        cout << "Positive number.\n";
        if (user_number % 2 == 0)
        {
            cout << "Even." << endl;
        }
        else
        {
            cout << "Odd." << endl;
        }
    }
    else if (user_number < 0)
    {
        cout << "Negative number." << endl;
    }
    else
    {
        cout << "This is zero." << endl;
    }

    return 0;
}