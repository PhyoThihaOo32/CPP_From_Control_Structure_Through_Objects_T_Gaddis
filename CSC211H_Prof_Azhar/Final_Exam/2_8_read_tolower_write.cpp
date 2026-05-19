/*
8) Write a program that reads a text file with names and converts its input to all lower
case, producing a new file.
*/

#include <iostream>
#include <fstream>
#include <cctype> // to convert the char to lower case-> tolower()

using namespace std;

int main()
{
    char c;

    // create two file for read and write
    fstream inputFile("letters.txt", ios::in);
    fstream outputFile("lowercases.txt", ios::out);

    /*
    Note: fstream::open() does not throw exception by default, so catch(...)
    will not catch the error.
    */
    // try
    // {

    //     inputFile.open("letters.txt", ios::in);
    //     outputFile.open("lowercases.txt", ios::out);
    // }
    // catch (...)
    // {
    //     cerr << "File Error." << endl;
    // }

    if (!inputFile || !outputFile)
    {
        cerr << "File Error." << endl;
        return 1;
    }

    while (inputFile.get(c))
    { // We use static_cast<char> because tolower() returns int,
        // but ch is a char variable.
        c = static_cast<char>(tolower(c));
        // outputFile.put(c);
        outputFile << c;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
