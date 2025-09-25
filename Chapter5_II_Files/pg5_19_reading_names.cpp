/*
This program reading data from the demofile.txt and print it to console.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{

    // create ifstream object
    ifstream inputFile;

    // variable to store the data from the file
    string name1, name2, name3;

    // open the input file
    inputFile.open("demofile.txt");

    // read and store data using >> operator
    inputFile >> name1 >> name2 >> name3;

    // display the data
    cout << name1 << endl
         << name2 << endl
         << name3 << endl;

    // close the file
    inputFile.close();

    return 0;
}