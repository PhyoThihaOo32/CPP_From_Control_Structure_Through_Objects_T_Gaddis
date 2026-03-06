/*
This program writes data to file, closes the file, then reopens the file and appends more data.
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // create fstream object
    fstream dataFile;

    // open the file
    dataFile.open("dataFile.txt", ios::out);
    // wrtie to file
    dataFile << "Data1" << endl;
    dataFile << "Data2" << endl;
    dataFile << "Data3" << endl;
    // close the file
    dataFile.close();

    // reopen the file (with append mode)
    dataFile.open("dataFile.txt", ios::out | ios::app);

    // append to the file
    dataFile << "Data4" << endl;
    dataFile << "Data5" << endl;

    // close the file
    dataFile.close();

    return 0;
}