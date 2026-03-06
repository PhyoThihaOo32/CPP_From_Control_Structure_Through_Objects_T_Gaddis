/*
This program uses an fstream object to write data to a file.
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    // create fstream object
    fstream dataFile;
    // opening the file
    dataFile.open("dataFile.txt", ios::out);
    // write to file
    dataFile << "Data1" << endl;
    dataFile << "Data2" << endl;
    dataFile << "Data3" << endl;
    // close the file
    dataFile.close();

    return 0;
}