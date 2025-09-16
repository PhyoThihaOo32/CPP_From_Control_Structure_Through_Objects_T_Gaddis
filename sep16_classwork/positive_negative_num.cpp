/*
This program check if the number is positive, negative or zero number.
*/

#include <iostream>

using namespace std;

int main()
{

    float user_num;

    // get user input
    cout << "What is your number? ";
    cin >> user_num;

    // facotoring
    cout << "This is ";

    // check if the number is positive, negative or zero.
    if (user_num == 0)
    {
        cout << "zero." << endl;
    }
    else if (user_num > 0)
    {
        cout << "positive number." << endl;
    }
    else if (user_num < 0)
    {
        cout << "negative number." << endl;
    }
    else
    {
        cout << "not a number." << endl;
    }

    return 0;
}