/*
This program reads data from a file into an array.
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    // setting an array large enought to hold the data from the file
    const int SIZE = 100;
    int numbers[SIZE];

    // creating the input file stream object and open it
    ifstream inputFile("numbers.txt");

    // setting counter variables to count the number of elements stored in the array
    int count = 0;

    // reading data from the file and count the elements
    while (count < SIZE && inputFile >> numbers[count])
    {
        count++;
    }

    // close the file
    inputFile.close();

    // re-reading the data from the array
    for (int i = 0; i < count; i++)
    {
        cout << numbers[i] << " ";
    }

    return 0;
}