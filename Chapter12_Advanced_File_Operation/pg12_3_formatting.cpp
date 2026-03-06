/*
This program uses the setprecision and fixed manipulators to format file output.
*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{

    fstream dataFile("dataFile.txt", ios::out);

    double num = 3.141592;

    dataFile << fixed << num << endl;

    dataFile << setprecision(4) << num << endl;
    dataFile << setprecision(3) << num << endl;
    dataFile << setprecision(2) << num << endl;
    dataFile << setprecision(1) << num << endl;

    dataFile.close();

    return 0;
}