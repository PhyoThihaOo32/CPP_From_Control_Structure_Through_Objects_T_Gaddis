/*
This program demonstrates some character-testing functions.
*/

#include <iostream>
#include <cctype>

using namespace std;

int main()
{

    char input;

    cout << "Enter any character: ";
    cin.get(input);
    // cin >>      → reads input until whitespace (stops at space/newline)
    // cin.get()   → reads a single char or line (keeps newline in buffer)
    // cin.getline() → reads an entire line including spaces (discards newline)

    cout << "The character you enter is: " << input << endl;

    // testing the character
    if (isalpha(input))
        cout << "That's an alphabetic character." << endl;
    if (isdigit(input))
        cout << "That's a numeric digit." << endl;
    if (islower(input))
        cout << "That's a lower case character." << endl;
    if (isupper(input))
        cout << "That's a upper case character." << endl;
    if (isspace(input))
        cout << "That's a white space character." << endl;

    return 0;
}