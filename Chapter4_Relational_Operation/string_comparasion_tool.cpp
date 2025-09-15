/*
This program check and compare the two strings input from the user.

*/

#include <iostream>
#include <string>

using namespace std;

int main()
{

    string string1, string2;

    // Get user input
    cout << "Enter frist string literal: ";
    getline(cin, string1);
    cout << "Enter second string literal: ";
    getline(cin, string2);

    // display user string1 string2
    cout << "First string literal: " << string1 << endl;
    cout << "Second string literal: " << string2 << endl;

    // compare two string
    if (string1 > string2)
    {
        cout << string1 << " is greater than " << string2 << endl;
    }
    else if (string2 > string1)
    {
        cout << string2 << " is greater than " << string1 << endl;
    }
    else
    {
        cout << string1 << " is equal to " << string2 << endl;
    }

    return 0;
}

/*
String literals, are compared lexicographically (like dictionary order), character by character.
Ex. "ABC" and "BCD"
Since 'A' (65) < 'B' (66), the entire string "ABC" is considered less than "BCD".
No need to check further characters — comparison stops at first difference.
*/