/*
Write a program that reads a text file with names and converts its input to all lower
case, producing a new file.
*/

#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

int main()
{

    fstream fileIn("UpperCase.txt", ios::in);
    fstream fileOut("LowerCase.txt", ios::out);
    char upper;
    char lower;

    if (fileIn)
    {
        fileIn.get(upper);
        while (fileIn)
        {
            lower = tolower(upper);
            fileOut << lower;
            fileIn.get(upper);
        }
    }
    else
    {
        cout << "Error opening the file." << endl;
    }

    fileIn.close();
    fileOut.close();

    return 0;
}