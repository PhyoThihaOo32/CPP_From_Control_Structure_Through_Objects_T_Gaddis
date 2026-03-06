/*
This program demonstrates how the >> operator should not be used to read data
that contain whitespace characters from a file.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{

    string input;
    fstream inputFile;
    inputFile.open("murphy.txt", ios::in);

    if (inputFile)
    { // inputFile.good() - So the loop continues as long as the stream is in a good state(return true)
      // !inputFile.fail()
        // read from the file
        while (inputFile >> input)
        {
            cout << input;
        }
    }
    else
    {
        cerr << "Error opening the file." << endl;
    }

    inputFile.close();

    return 0;
}

/*
inputFile >> input

Meaning in terms of stream state:

Attempt to read a value from the file into variable "input".

If the read succeeds:
    → stream remains in GOOD state
    → expression evaluates TRUE
    → loop continues

If the read fails (EOF or invalid data):
    → failbit / eofbit is set
    → stream becomes FALSE
    → loop stops
*/