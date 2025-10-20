/*
This program is a driver that tests a function comparing the contents of two int arrays.
*/

#include <iostream>
#include <fstream>
using namespace std;

bool testPIN(const int[], const int[], int);

int main()
{
    const int SIZE = 7;
    int custPIN[SIZE];
    int databasePIN[SIZE];
    const string FILE_NAME = "customerPIN.txt";

    ofstream outputFile(FILE_NAME);
    if (!outputFile)
    {
        cout << "Error opening file for writing.\n";
        return 1;
    }

    cout << "Please enter your 7-digit PIN number:\n";
    for (int i = 0; i < SIZE; i++)
    {
        cout << "Enter digit " << (i + 1) << ": ";
        cin >> custPIN[i];
        outputFile << custPIN[i] << " ";
    }
    outputFile.close();

    ifstream inputFile(FILE_NAME);
    if (!inputFile)
    {
        cout << "Error opening file for reading.\n";
        return 1;
    }

    for (int i = 0; i < SIZE; i++)
    {
        inputFile >> databasePIN[i];
    }

    if (testPIN(custPIN, databasePIN, SIZE))
        cout << "Access Granted.\n";
    else
        cout << "Access Denied.\n";

    return 0;
}

bool testPIN(const int custPIN[], const int databasePIN[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (custPIN[i] != databasePIN[i])
            return false;
    }
    return true;
}