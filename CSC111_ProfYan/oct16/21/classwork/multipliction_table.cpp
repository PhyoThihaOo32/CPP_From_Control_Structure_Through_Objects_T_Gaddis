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

    return 0;
}