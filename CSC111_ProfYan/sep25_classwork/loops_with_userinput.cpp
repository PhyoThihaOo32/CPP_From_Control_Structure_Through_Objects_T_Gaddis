/*
This program demonstrate the use of loops [ for loop, while loop, do while loop ].
*/

#include <iostream>

using namespace std;

int main()
{

    // variable
    int user_input;

    // get user input
    cout << "How many times you want to print: ";
    cin >> user_input;

    // print "Hello World" 5 times

    cout << "\nPrint Hello World 5 times" << endl;
    for (int i = 1; i <= user_input; i++)
    {
        cout << "Hello World " << i << endl;
    }

    cout << "\nHow many times you want to print: ";
    cin >> user_input;

    cout << "Print integers " << user_input << " times seperated by space" << endl;
    for (int i = 1; i <= user_input; i++)
    {
        cout << i << " ";
    }

    cout << "\nHow many times you want to print: ";
    cin >> user_input;

    // print integers backway seperated by space
    cout << "\nprint integers backward seperated by space" << endl;
    for (int i = user_input; i >= 0; i--)
    {
        cout << i << " ";
    }

    return 0;
}