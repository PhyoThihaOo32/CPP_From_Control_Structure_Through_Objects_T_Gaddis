/*
This program read data from file into array.
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    const int ARRAY_SIZE = 6; // array size
    int numbers[ARRAY_SIZE];  // array with 10 elements
    int count = 0;            // loop counter

    ifstream inputFile; // input file stream object

    // open the file
    inputFile.open("numbers.txt");

    while (count < ARRAY_SIZE && inputFile >> numbers[count])
    {

        count++;
    }

    // close the file
    inputFile.close();

    // display the number read
    for (count = 0; count < ARRAY_SIZE; count++)
    {
        cout << numbers[count] << " ";
    }

    return 0;
}