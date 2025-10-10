/*
This program read a keyboards symbols files, stores the characters into arrays and convert into ascii codes.
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    char keyboard_characters[] = {
        // Uppercase letters
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
        'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
        'U', 'V', 'W', 'X', 'Y', 'Z',

        // Lowercase letters
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
        'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
        'u', 'v', 'w', 'x', 'y', 'z',

        // Digits
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',

        // Symbols
        '!', '@', '#', '$', '%', '^', '&', '*', '(', ')',
        '-', '_', '=', '+', '[', ']', '{', '}', '\\', '|',
        ';', ':', '\'', '"', ' ', ',', '.', '<', '>', '/', '?',
        '`', '~'};
    auto array_size = sizeof(keyboard_characters) / sizeof(char);

    cout << "Character\t" << "ASCII code" << endl;
    cout << "===========================" << endl;
    for (int i = 0; i < array_size; i++)
    {

        cout << keyboard_characters[i] << "\t\t" << static_cast<int>(keyboard_characters[i]) << endl;
    }

    return 0;
}