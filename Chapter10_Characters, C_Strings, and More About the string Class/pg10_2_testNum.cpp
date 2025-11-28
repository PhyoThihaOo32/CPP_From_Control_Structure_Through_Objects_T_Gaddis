/*
This program test a customer number to determine whether it is in the proper format.
*/

#include <iostream>
#include <cctype>

using namespace std;

bool testNum(char[], int);

int main()
{

    const int SIZE = 8;
    char customer[SIZE];

    // get the customer number
    cout << "Enter the customer number in the form LLLNNNN" << endl;
    cout << "LLL = letter and NNNN = numbers" << endl;
    cin.getline(customer, SIZE);

    // validate the customer input
    if (testNum(customer, SIZE))
    {
        cout << "That is a valid customer number." << endl;
    }
    else
    {
        cout << "That is not a valid customer number." << endl;
    }

    return 0;
}

bool testNum(char cusNum[], int size)
{
    int count;
    for (count = 0; count < 3; count++)
    {
        if (!isalpha(cusNum[count]))
        {
            return false;
        }
    }
    for (count = 3; count < size - 1; count++)
    { // size - 1 (don't forget the white space character after LLLNNNN)
        if (!isdigit(cusNum[count]))
        {
            return false;
        }
    }
    return true;
}