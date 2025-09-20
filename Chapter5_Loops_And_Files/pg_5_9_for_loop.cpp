/*
This program displays the number 1 through 10 and their squares.
*/

#include <iostream>

using namespace std;

int main()
{

    const int MIN_NUMBER = 1;
    const int MAX_NUMBER = 12;

    int number1, number2;

    for (number1 = MIN_NUMBER; number1 <= MAX_NUMBER; number1++)
    {
        for (number2 = MIN_NUMBER; number2 <= MAX_NUMBER; number2++)
        {
            cout << number1 << " * " << number2 << " = " << (number1 * number2) << endl;
        }
        cout << "----------------" << endl;
    }

    return 0;
}