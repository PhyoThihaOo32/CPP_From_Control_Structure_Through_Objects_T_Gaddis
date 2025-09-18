/*
This program ask user a character.
Then check if it is digit, lowercase letter or uppercase letter.
If it is lowercase to change it to the uppercase and vice visa.
Finally print the result letter.
*/

#include <iostream>

using namespace std;

int main()
{

    char user_char;

    // ask user for a character
    cout << "Enter a character:";
    cin >> user_char;

    // check if it a digit
    if (user_char >= 48 && user_char <= 57)
    {
        cout << "Digit." << endl;
    }
    // check if it a uppercase
    else if (user_char >= 65 && user_char <= 90)
    {
        cout << user_char << " is uppercase letter." << endl;
        user_char += 32;
        cout << "Converted to: " << user_char << endl;
    }
    // check if it a lowercase
    else if (user_char >= 97 && user_char <= 122)
    {
        cout << user_char << " is a lowercase letter." << endl;
        user_char -= 32;
        cout << "Converted to: " << user_char << endl;
    }
    else
    {
        cout << "This might be a symbol." << endl;
    }

    return 0;
}