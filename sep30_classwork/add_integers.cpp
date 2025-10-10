/*
This program adds up the integers from 1 to N. The user inputs a value for N.
*/

#include <iostream>

using namespace std;

int main()
{
    int total = 0;
    int n;
    cout << "Type a whole number, n = ";
    cin >> n;

    for (int i = 1 /*, total = 0*/; i <= n; i++)
    {
        cout << total << " + " << i << " = ";
        total += i;
        cout << total << endl;
    }

    cout << "====================================" << endl;
    cout << "Total is: " << total << endl;

    return 0;
}