/*
A simple censoring program, replacing an exclamation point by a period and "Boo" by "---" (assuming those items are somehow bad and should be censored.) "Boo" is replaced using the strncpy() function, which is described elsewhere.
Note that only the first occurrence of "Boo" is replaced, as strstr() returns a pointer to the first occurrence. Additional code would be needed to delete all occurrences.
*/

#include <iostream>
#include <cstring>

using namespace std;

int main()
{

    const int SIZE = 100;
    char userInput[SIZE];
    char *cptr = nullptr;

    cout << "Enter a line of text: ";
    cin.getline(userInput, SIZE);

    cout << "Before censor: " << userInput << endl;

    cptr = strchr(userInput, '!');

    if (cptr != nullptr)
    {
        *cptr = '.';
    }

    cout << "After censor: " << userInput << endl;

    cptr = strstr(userInput, "Fuck");

    if (cptr != nullptr)
    {
        strncpy(cptr, "----", 4);
    }

    cout << "Fuck is replaced by ----: " << userInput << endl;

    return 0;
}

/*
strchr()
--------
Searches for the FIRST occurrence of a character in a C-string.

Parameters:
- const char* str : string to search
- int ch          : character to find

Returns:
- Pointer to first occurrence of character
- NULL if character is not found
*/

/*
strrchr()
---------
Searches for the LAST occurrence of a character in a C-string.

Parameters:
- const char* str : string to search
- int ch          : character to find

Returns:
- Pointer to last occurrence of character
- NULL if character is not found
*/

/*
strrchr()
---------
Searches for the LAST occurrence of a character in a C-string.

Parameters:
- const char* str : string to search
- int ch          : character to find

Returns:
- Pointer to last occurrence of character
- NULL if character is not found
*/

/*
strstr()
--------
Searches for the FIRST occurrence of a substring inside another string.

Parameters:
- const char* str    : main string
- const char* substr : substring to search

Returns:
- Pointer to beginning of found substring
- NULL if substring is not found
*/

/*
strcpy()
--------
Copies one C-string into another.

Parameters:
- char* dest        : destination string
- const char* src   : source string

Important:
- Destination must have enough memory.
- Copies until NULL character '\0'.

Returns:
- Pointer to destination string.
*/

/*
strncpy()
---------
Copies up to N characters from source string to destination.

Parameters:
- char* dest        : destination string
- const char* src   : source string
- size_t n          : maximum characters to copy

Important:
- May NOT add '\0' if source length >= n.
- Safer than strcpy but requires caution.

Returns:
- Pointer to destination string.
*/