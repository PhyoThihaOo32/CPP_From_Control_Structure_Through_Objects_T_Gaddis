/*
get member function - reads a single character from the file.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{

    fstream ifile;
    string fileName;
    char c;

    // ask user to enter the file name
    cout << "Enter the file name: ";
    cin >> fileName;

    // open the file - in
    ifile.open(fileName, ios::in | ios::out);

    // check if the file is opened
    if (ifile)
    {
        // then user can write
        ifile.get(c);
        while (ifile)
        {
            cout << c;
            ifile.get(c);
        }
    }
    else
    {
        cout << "Error opening the file." << endl;
    }
    ifile.close();

    return 0;
}

/*
iFile is a stream object (ifstream / fstream).

When used like:
    if(iFile)

the stream is implicitly converted to a boolean. This checks whether
the stream is still usable.

Internally it behaves like:
    if(!iFile.fail() && !iFile.bad())

So:
    TRUE  → stream is good enough to keep reading
    FALSE → a read error occurred (failbit or badbit set)

This is different from:
    iFile.good()

because good() returns true only when NO state flags are set
(eofbit, failbit, badbit all must be 0).

Example:
If eofbit = 1 but failbit = 0

    iFile.good() → false
    if(iFile)    → true

Therefore most programs use:
    while(iFile)
or
    while(iFile >> value)

since it checks whether the stream is still usable.
*/