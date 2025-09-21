/*
This program writes user input[numbers] to a file.
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    ofstream outputFile; // creat ofstream object

    int number1, number2, number3;

    // open an output file
    outputFile.open("numbers.txt");

    // get user input
    cout << "Enter number 1: ";
    cin >> number1;

    cout << "Enter number 2: ";
    cin >> number2;

    cout << "Enter number 3: ";
    cin >> number3;

    // write the number to the file
    outputFile << number1 << endl
               << number2 << endl
               << number3 << endl;

    // close the file
    outputFile.close();

    return 0;
}