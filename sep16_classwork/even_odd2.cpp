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


    // check the number is positive, negative or zero and aslo check even or odd.
    if (user_number > 0)
    {
        cout << "Positive number.\n";
        if (user_number % 2 == 0)
        {
            cout << "And even." << endl;
        }
        else
        {
            cout << "And odd number." << endl;
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