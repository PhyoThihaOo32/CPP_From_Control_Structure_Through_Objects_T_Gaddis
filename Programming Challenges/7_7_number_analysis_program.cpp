/*
7. Number Analysis Program

Write a program that asks the user for a file name. Assume the file contains a series of numbers, each written on a separate line. The program should read the contents of the file into an array and then display the following data:

• The lowest number in the array
• The highest number in the array
• The total of the numbers in the array
• The average of the numbers in the array
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream inputFile;
    string fileName;

    int array[100];
    int count = 0;

    int lowest, highest;
    int total = 0;
    double avg; // average should be double for accuracy

    cout << "Enter the file name: ";
    cin >> fileName;

    inputFile.open(fileName);

    // check if file opened successfully
    if (!inputFile)
    {
        cout << "Error opening file." << endl;
        return 1;
    }

    // read numbers into array
    while (count < 100 && inputFile >> array[count])
    {
        count++;
    }

    // check if file had no numbers
    if (count == 0)
    {
        cout << "File is empty." << endl;
        return 1;
    }

    // ✅ initialize lowest & highest
    lowest = array[0];
    highest = array[0];

    // ✅ compute total, lowest, highest
    for (int i = 0; i < count; i++)
    {
        total += array[i];

        if (array[i] < lowest)
            lowest = array[i];

        if (array[i] > highest)
            highest = array[i];
    }

    // ✅ calculate average
    avg = static_cast<double>(total) / count;

    // ✅ display results
    cout << "\nLowest number: " << lowest << endl;
    cout << "Highest number: " << highest << endl;
    cout << "Total: " << total << endl;
    cout << "Average: " << avg << endl;

    inputFile.close(); // good practice

    return 0;
}