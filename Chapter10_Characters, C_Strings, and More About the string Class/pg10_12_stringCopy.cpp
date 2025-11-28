/*
This program uses a function to copy a C-string (character array)
from one array to another using pointer arithmetic.
It checks if there is enough space before copying and displays
how many characters were copied.
*/

#include <iostream>
#include <cstring> // ✅ Needed for strlen()

using namespace std;

// ✅ Function prototype — returns number of characters copied
int copyString(char *, char *);

int main()
{
    const int LENGTH = 30;
    char first[LENGTH], second[LENGTH];
    int available_space, required_space, copied_chars;

    // 🧑‍💻 Get input from user
    cout << "Enter a string with no more than " << LENGTH - 1 << " characters:" << endl;
    cin.getline(first, LENGTH);

    // ✅ Initialize second as empty string
    second[0] = '\0';

    // Calculate available and required space
    available_space = sizeof(second) - (strlen(second) + 1);
    required_space = strlen(first) + 1;

    // Check if there is enough space to copy
    if (available_space >= required_space)
    {
        // Copy and get number of characters copied
        copied_chars = copyString(first, second);

        // Display results
        cout << "\nCopied contents: " << second << endl;
        cout << "Number of characters copied: " << copied_chars << endl;
    }
    else
    {
        cout << "\nNot enough space to copy into second." << endl;
    }

    return 0;
}

/*
This function copies a C-string from 'string1' to 'string2'
character by character using pointer arithmetic until the
null terminator ('\0') is reached.
It returns the number of characters copied.
*/
int copyString(char *string1, char *string2)
{
    int index = 0;

    // Copy characters from source to destination
    while (*(string1 + index) != '\0')
    {
        *(string2 + index) = *(string1 + index);
        index++;
    }

    // Add null terminator at end of destination
    *(string2 + index) = '\0';

    // Return number of characters copied
    return index;
}