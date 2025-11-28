/*
This program use the return value of strcmp to alphabetically sort two strings enter by the user.
[Note: Because the value returned by strcmp is based on the relative alphabetic order of the two strings being
compared, it can be used in programs that sort strings.]
*/

#include <iostream>
#include <cstring>

using namespace std;

int main()
{

    const int LENGTH = 40;
    char string1[LENGTH], string2[LENGTH];

    cout << "Enter the first string: ";
    cin.getline(string1, LENGTH);

    cout << "Enter the second string: ";
    cin.getline(string2, LENGTH);

    // sort the string
    if (strcmp(string1, string2) < 0)
    {
        cout << string1 << endl
             << string2 << endl;
    }
    else if (strcmp(string1, string2) > 0)
    {
        cout << string2 << endl
             << string1 << endl;
    }
    else
    {
        cout << "You entered the same string twice." << endl;
    }

    return 0;
}