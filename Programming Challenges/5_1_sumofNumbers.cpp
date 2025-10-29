/*
This program asks the user for a positive integer value. The prgram should use a loop to get the sum
of all the integers from 1 up to the number entered. For example, if the user enters 50, the loop will find
the sum of 1, 2, 3, 4, ...50.
Input validation: Do not accept a negative starting number.
*/

#include <iostream>

using namespace std;

int main()
{

    int user_num,
        total = 0; // accumulator

    // asks the user for a positive integer value
    cout << "Enter the positive integer number\n[the sum of all the integers from 1 up to the number entered]" << endl;
    cin >> user_num;

    while (user_num < 0)
    {
        cout << "Invalid Input. Please enter the positive integer number.";
        cin >> user_num;
    }

    cout << "Total: ";
    for (int i = 1; i <= user_num; i++)
    {
        cout << i;
        total += i;
        if (i < user_num)
        {
            cout << " + ";
        }
    }

    cout << " = " << total << endl;

    return 0;
}
