#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{

    ofstream outputFile("multiplication_table.txt");

    outputFile << setw(2) << "x";
    for (int i = 0; i <= 15; i++)
    {
        outputFile << setw(5) << i;
    }
    outputFile << endl;
    for (int i = 0; i <= 15; i++)
    {
        outputFile << setw(2) << i;
        for (int j = 0; j <= 15; j++)
        {
            outputFile << setw(5) << (i * j);
        }
        outputFile << endl;
    }

    outputFile.close();

    ifstream inputFile("multiplication_table.txt");
    int numbers;
    while (inputFile >> numbers)
    {
        cout << numbers;
    }

    inputFile.close();

    return 0;
}