/*
This program write the rows of numbers to the file.
*/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{

    // create fsteam object (output mode)
    fstream dataFile("dataFile.txt", ios::out);

    // create 2D array
    const int ROWS = 3;
    const int COLS = 3;
    int num[ROWS][COLS] = {{1, 3, 4},
                           {4, 5, 6},
                           {9, 8, 3}};

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            dataFile << setw(4) << num[i][j];
        }
        dataFile << endl;
    }

    // close the file
    dataFile.close();

    return 0;
}