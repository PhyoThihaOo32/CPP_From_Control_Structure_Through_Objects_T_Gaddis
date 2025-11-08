/*
This program use a loop that lets the user enter a series of integers. The user should enter -99
to signal the end of the series. After all the numbers have been entered, the program should display the
largest and smallest numbers entered.
*/

#include <iostream>

using namespace std;

int main()
{

    const int SENTINEL = -99;
    int largest, smallest, num;
    bool firstInput = true; // just to get the first input

    cout << "Enter any integer. or  -99 to stop." << endl;

    while (cin >> num && num != -99)
    {
        if (firstInput)
        {
            largest = smallest = num; // 8
            firstInput = false;       // this condition will only execute once
        }
        else
        {
            if (num > largest) // 8 15
                largest = num;
            if (num < smallest)
                smallest = num; // 3
        }
    }

    cout << "Largest: " << largest << endl;
    cout << "Smallest: " << smallest << endl;

    return 0;
}