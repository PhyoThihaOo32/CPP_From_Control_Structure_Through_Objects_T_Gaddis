/*
This program calculate the sum of three integers. Save them on file.
*/

#include <iostream>
#include <fstream>

using namespace std;

// function prototype
int sum_three_numbers(int, int, int);

// main function
int main()
{
    // variable
    int num1, num2, num3, result;

    // get user input
    cout << "Enter three numbers seperated by space: ";
    cin >> num1 >> num2 >> num3;

    // call sum_three_numbers function
    result = sum_three_numbers(num1, num2, num3);

    // display total
    cout << "Total: " << result << endl;

    return 0;
}

// definition of function sum_three_numbers.
// This function add three numbers and return the result.

int sum_three_numbers(int num1, int num2, int num3)
{
    return (num1 + num2 + num3);
}
