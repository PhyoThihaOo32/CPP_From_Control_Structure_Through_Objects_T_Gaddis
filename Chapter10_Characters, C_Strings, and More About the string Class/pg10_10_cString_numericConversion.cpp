/*
This program demonstrate the strcmp and atoi functions.
cstdlib provide functions for converting a C-String representation of a number to a numeric data type.
atoi - converts the C-String to int
atof - converts the C-String to double( and float)
atol - converts the C-String to long
In vise visa, to_string function converts a numeric value to a string object. (9 overloaded version of to_string function)
*/

#include <iostream>
#include <cstring> // for strcmp
#include <cstdlib> // for atoi
#include <cctype>  // for tolower

using namespace std;

int main()
{

    const int SIZE = 20;
    char input[SIZE];
    int total = 0,
        count = 0;
    double average;

    cout << "The program will average the series of numbers." << endl;
    cout << "Enter the first number or Q or q to quit." << endl;
    cin.getline(input, SIZE);

    while (tolower(input[0]) != 'q')
    {
        total += atoi(input); // convert the C-string into numeric int and total the number
        count++;              // count the number enter

        cout << "Enter the next number or Enter Q or q to quit." << endl;
        cin.getline(input, SIZE);
    }

    if (count != 0)
    {
        average = static_cast<double>(total) / count;
        cout << "Average: " << average << endl;
    }

    return 0;
}