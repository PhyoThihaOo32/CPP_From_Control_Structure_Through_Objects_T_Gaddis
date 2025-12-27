/*
This program demonstrate reading from the file.
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    int numbers, count = 0, total = 0;
    ifstream inputFile("lottoNumbers.txt");

    if (inputFile)
    {
        cout << "Now reading from the file." << endl;
        while (inputFile >> numbers) //
        {
            cout << numbers << " ";
            count++;
            total += numbers;
        }
    }
    else
    {
        cout << "Error opening the file." << endl;
    }

    inputFile.close();

    if (!inputFile.is_open())
    {
        cout << "File closed successfully." << endl;
    }

    cout << "Total lotto Number in the file: " << count << endl;
    cout << "Sum of the total numbers: " << total << endl;

    return 0;
}