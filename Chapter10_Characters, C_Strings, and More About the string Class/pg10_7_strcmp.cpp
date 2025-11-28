/*
This program tests two C-strings for equality.
*/

#include <iostream>
#include <cstring>

using namespace std;

int main()
{

    const int LENGTH = 40;
    // declare two C-Strings
    char string1[LENGTH], string2[LENGTH];

    // read two C-String from the user
    cout << "Enter first string: ";
    cin.getline(string1, LENGTH);

    cout << "Enter second string: ";
    cin.getline(string2, LENGTH);

    // compare the strings for equality with strcmp
    if (!strcmp(string1, string2))
    {
        cout << "You have enter the same strings twice" << endl;
    }
    else
    {
        cout << "The string are not same." << endl;
    }

    return 0;
}