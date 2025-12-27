/*
This program calculate sum of all integers from 1 to x times.
*/

#include <iostream>

using namespace std;

int main()
{

    int user_input,
        total = 0;

    // ask userinput
    cout << "How many number: ";
    cin >> user_input;

    for (int i = 1; i <= user_input; i++)
    {
        cout << total << " + " << i << " = " << (total + i) << endl;
        total += i;
    }

    cout << "Sum of number 1 to " << user_input << ":\t" << total << endl;

    return 0;
}