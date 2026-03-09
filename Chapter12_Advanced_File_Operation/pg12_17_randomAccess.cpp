/*
In Random file access, a program may immediately jump to any byte in the file without first reading the preceding bytes.
The seekp function is used with file opened for output ( p for put ).
The seekg function is used with file opened for input  ( g for get ).
The first argument is a long integer representing an offset into the file. This is the number
of the byte you wish to move to.
The second argument is called the mode. It designates where to calculate the offset from.

Negative offset result in the read or write position being moved backward in the file,
while positive offsets result in a forward movement.
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    char ch; // to hold a character

    // open file for input
    fstream file("letters.txt", ios::in);

    // move to 5bytes from the beginning of the file (the 6th byte) and read the character there
    file.seekg(5L, ios::beg);
    file.get(ch);

    cout << "Byte 5 from beginning: " << ch << endl;

    // move to the 10th byte from the end of the file
    file.seekg(-10L, ios::end);
    file.get(ch);
    cout << "10th byte from the end: " << ch << endl;

    // move to 3 byte forward from the current position
    file.seekg(3L, ios::cur);
    file.get(ch);

    cout << "Byte 3 from current position: " << ch << endl;

    file.close();

    return 0;
}