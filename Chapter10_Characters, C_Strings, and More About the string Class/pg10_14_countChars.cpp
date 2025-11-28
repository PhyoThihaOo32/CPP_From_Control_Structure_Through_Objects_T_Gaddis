/*
This program demonstrates a function, countChars, that counts the number of times
a specific character appears in a string.
*/

#include <iostream>
using namespace std;

// Function prototype
int countChar(char *, char);

int main()
{
    const int SIZE = 40;
    char userString[SIZE];
    char userChar;

    // Get a string from the user
    cout << "Enter a string (up to 39 characters): " << endl;
    cin.getline(userString, SIZE);

    // Get a character to look for
    cout << "Enter a character to search: " << endl;
    cin >> userChar;

    // Display number of occurrences
    cout << "Number of occurrences in the string: "
         << countChar(userString, userChar) << endl;

    return 0;
}

// This function searches for a character in the string and returns the number of occurrences.
int countChar(char *ptr, char ch)
{
    int times = 0;
    while (*ptr != '\0') // iterate the string until null terminator
    {
        if (*ptr == ch) // if match found
        {
            times++; // increment count
        }
        ptr++; // move to next character
    }
    return times;
}