/*
=========================================================
<cctype> HEADER IN C++
=========================================================

Definition:
- <cctype> provides functions to test and manipulate
  single characters.
- Used for character classification and conversion.

Header:
    #include <cctype>

---------------------------------------------------------

1) CHARACTER TEST FUNCTIONS
=========================================================

isalnum(c)
- Checks if character is letter OR digit

isalpha(c)
- Checks if character is a letter (A–Z, a–z)

isdigit(c)
- Checks if character is a digit (0–9)

islower(c)
- Checks if character is lowercase

isupper(c)
- Checks if character is uppercase

isspace(c)
- Checks if whitespace (space, tab, newline)

ispunct(c)
- Checks if punctuation (!, ?, ., etc.)

---------------------------------------------------------

2) CHARACTER CONVERSION FUNCTIONS
=========================================================

toupper(c)
- Converts character to uppercase

tolower(c)
- Converts character to lowercase

---------------------------------------------------------

3) IMPORTANT NOTES
=========================================================

- All functions take ONE character as input
- Return type is int (non-zero = true, 0 = false)
- Works only with char, NOT string

Example:
    isalpha('A')  → true
    isdigit('5')  → true
    isspace(' ')  → true

---------------------------------------------------------

4) COMMON USE CASES
=========================================================

- Input validation
- Ignoring spaces
- Converting text case
- Checking digits/letters

---------------------------------------------------------

5) EXAMPLE
=========================================================

char c = 'a';

if (isalpha(c))
{
    cout << "Letter";
}

c = toupper(c);  // 'A'

---------------------------------------------------------

EXAM ONE-LINER
=========================================================

<cctype> provides functions to test and manipulate
characters such as checking type (digit, letter) and
changing case (upper/lower).

=========================================================
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