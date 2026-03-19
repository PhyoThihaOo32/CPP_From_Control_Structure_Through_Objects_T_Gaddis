/*
tellg() and tellp() - return, as long integer, the current byte number of a file's read and
write position.
[-can determine the number of bytes that a file contains.]
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    long offset;   // to hold an offset amount
    long numBytes; // to hold the file size
    char ch;       // to hold a character
    char again;    // to hold Y or N

    // open the file for input
    fstream file("letters.txt", ios::in);

    // check the number of bytes in the file
    file.seekg(0L, ios::end); // pointer at the file end
    numBytes = file.tellg();
    cout << "The file has " << numBytes << " bytes." << endl;

    // go back to the beginning of the file
    file.seekg(0L, ios::beg);

    // let the user move around within the file
    do
    {
        // display the current read position
        cout << "Current at position " << file.tellg() << endl;

        // get a byte number from the user
        cout << "Enter an offset from the beginning of the file: ";
        cin >> offset;

        // move the read position to that byte, read the character there, display it
        if (offset >= numBytes)
        {
            cout << "Cannot read past the end of the file." << endl;
        }
        else
        {
            file.seekg(offset, ios::beg);
            file.get(ch);
            cout << "Character read: " << ch << endl;
        }

        // repeat?
        cout << "Do it again?" << endl;
        cin >> again;
    } while (again == 'Y' || again == 'y');

    // close the file
    file.close();

    return 0;
}