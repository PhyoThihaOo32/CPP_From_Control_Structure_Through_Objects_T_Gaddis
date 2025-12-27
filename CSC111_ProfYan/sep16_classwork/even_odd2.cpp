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
    if (user_number == 0)
    {
        cout << "This is a zero." << endl;
    }
    else
    {
        cout << "This is a " << ((user_number > 0) ? "positive " : "negative ");
        cout << "and " << ((user_number % 2 == 0) ? "even " : "odd ") << "numbers" << endl;
    }
    return 0;
}