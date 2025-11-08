/*
The program asks the user for a positive integer no greater than 15. The program should then display
a square on the screen using the character 'X'. The number entered by the user will be the length of
each side of the square.
*/

#include <iostream>

using namespace std;

int main()
{

    int usr_input;
    char usr_symbol;

    cout << "Enter the positive integer no greater than 15." << endl;
    cin >> usr_input;

    cout << "What is your favourite keyborad character?" << endl;
    cin >> usr_symbol;

    for (int i = 0; i < usr_input; i++)
    {
        for (int j = 0; j < usr_input; j++)
        {
            cout << usr_symbol;
        }
        for (int k = 0; k < 20; k++)
        {
            cout << '-';
        }
        cout << endl;
    }

    for (int k = 0; k < 2; k++)
    {
        for (int k = 0; k < 25; k++)
        {
            cout << '-';
        }
        cout << endl;
    }

    return 0;
}