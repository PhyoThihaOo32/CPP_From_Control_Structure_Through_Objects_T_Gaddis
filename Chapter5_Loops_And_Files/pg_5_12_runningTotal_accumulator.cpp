/*
A running total is a sum of numbers that accumulates with each iteration of a loop.
The variable used to keep the running total is called an accumulator.

This program takes daily sales figures over a period of time and calculate their total.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

    // variables
    double total_sales = 0; // accumulator, initialized with 0
    int days;
    double sales;

    // get the number of days
    cout << "For how many days do you have sales figures?" << endl;
    cin >> days;

    // get the sales for each days and calculate the total sales
    for (int count = 1; count <= days; count++)
    {

        cout << "Enter the sales for day " << count << ":\t";
        cin >> sales;

        total_sales += sales;
        cout << "Sales for day " << count << ":\t" << total_sales << endl;
    }

    cout << "Total number of sales in " << days << " days:\t" << total_sales << " $" << endl;

    return 0;
}
