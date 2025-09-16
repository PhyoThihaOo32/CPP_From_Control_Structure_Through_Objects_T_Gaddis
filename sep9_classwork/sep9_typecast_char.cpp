/*
This program demostrate type casting of char
*/

#include <iostream>

using namespace std;

int main()
{

    char uppercase_A = 'A';              // decimal value for A is 65
    char lowercase_A = uppercase_A + 32; // different between uppercase and lowercase letter would always be 32
    char userinput;

    // cout << uppercase_A + 32 << endl; // char promoted to int
    // cout << static_cast<char>(uppercase_A + 32) << endl;
    // cout << static_cast<int>(uppercase_A) << endl;
    // cout << uppercase_A + 0 << endl;

    cout << "Type a Uppercase letter:\n";
    cin >> userinput;

    cout << " >> " << static_cast<char>(userinput + 32) << endl;

    cout << "Type a Lower case letter:\n";
    cin >> userinput;

    cout << " >> " << static_cast<char>(userinput - 32) << endl;


    return 0;
}