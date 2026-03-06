/*
Part 1: (5 points)
Revise your  CSC211H assignment 1 and add the following features (implement and test) using file input/output:
●	Write out the commands user entered in a file
●	Read from the files to print all past commands

*/

#include <iostream>
#include "roomba.h"
#include <fstream>
#include <string>

using namespace std;

int main()
{

    fstream outputFile;
    string fileName;
    Roomba roomba;

    cout << "Enter the file name: ";
    cin >> fileName;

    outputFile.open(fileName, ios::out | ios::app);

    if (outputFile)
    {
        roomba.setLimits();
        roomba.displayLimits();
        roomba.displayPosition();
        roomba.runRoomba(outputFile);
    }
    else
    {
        cerr << "Error opening the file." << endl;
    }

    outputFile << "\nCommands Saved Successfully." << endl
               << "----------------------------" << endl;
    outputFile.close();

    return 0;
}
