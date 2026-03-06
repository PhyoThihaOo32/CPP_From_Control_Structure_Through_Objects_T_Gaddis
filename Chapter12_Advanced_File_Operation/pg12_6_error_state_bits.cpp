/*
All stream objects have error stat bits that indicate the condition of the stream.
(All stream objects contain a set of bits that act as flags.)

This program demonstrates the return value of the stream object error testing member functions.
*/

#include <iostream>
#include <fstream>

using namespace std;

void showFileSt(fstream &);

int main()
{

    int num = 10;
    fstream testFile("stuff.dat", ios::out);

    if (testFile.fail())
    {
        cout << "Error can't open the file." << endl;
        return 0;
    }

    // write the value to the file
    cout << "Writing " << num << " to the file." << endl;
    testFile << num;

    // show status
    showFileSt(testFile);

    // close the file
    testFile.close();

    // reopne the file for in
    testFile.open("stuff.dat", ios::in);

    if (testFile.fail())
    {
        cout << "Error can't open the file." << endl;
        return 0;
    }

    // read from the file
    cout << "Reading from the file." << endl;

    testFile >> num;
    cout << "The value " << num << " was read." << endl;

    // show bit state
    showFileSt(testFile);

    // no more data in the file, but force invalid operation
    cout << "Forcing a bad read operation." << endl;
    testFile >> num;

    // show bit states
    showFileSt(testFile);

    // close the file
    testFile.close();

    return 0;
}

void showFileSt(fstream &file)
{
    cout << "File Status:" << endl;
    cout << "eof bit: " << file.eof() << endl;
    cout << "fail bit: " << file.fail() << endl;
    cout << "bad bit: " << file.bad() << endl;
    cout << "good bit: " << file.good() << endl;
    file.clear(); // clear any bad bit
}