/*
This program demostrate use of cin/ getline/ cin.ignore() - and keyboard buffer.
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{

    unsigned st_number, zip_code;
    string st_name, city;
    char state_abbrev1, state_abbrev2;

    // Ask user information - street number
    cout << "Enter street number:\t";
    cin >> st_number;
    cin.ignore(); //  discards that leftover newline.

    // Ask user street name
    cout << "Enter street name:\t";
    getline(cin, st_name);

    // Ask user city
    cout << "Enter city:\t";
    getline(cin, city);

    // Ask user state abbravation
    cout << "Enter state abbravation1:\t";
    cin.get(state_abbrev1);

    cout << "Enter state abbravation2:\t";
    cin >> state_abbrev2;

    // Ask zipcode
    cout << "Enter zipcode:\t";
    cin >> zip_code;

    // print the address
    cout << "Address:\t" << st_number << " "
         << st_name << ", " << city << ", "
         << state_abbrev1 << state_abbrev2 << ", " << zip_code << endl;

    return 0;
}

/*

 1. cin >> variable

➤ What it does:
    •	Reads input until the first whitespace (space, tab, or newline).
    •	Automatically skips any leading whitespace before reading.
    •	Works with all standard types (like int, double, string, etc).

2. cin.get()

➤ What it does:
    •	Reads a single character (including whitespace and newline).
    •	Does not skip whitespace automatically.

3. getline(cin, stringVariable)

➤ What it does:
    •	Reads an entire line of text from cin (including spaces).
    •	Stops when it encounters a newline ('\n'), but does not include it in the string.
    •	It’s a string-safe version that works with the std::string type.

4. cin.getline(charArray, size)

➤ What it does:
    •	Similar to getline(cin, string), but works with C-style character arrays (char[]).
    •	Reads up to size - 1 characters or until newline ('\n'), whichever comes first.
    •	Automatically adds a null terminator '\0' at the end.
*/