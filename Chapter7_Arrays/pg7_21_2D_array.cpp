/*
This program demonstrates the two dimensional arrays.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

    const int NUM_DIVS = 3;
    const int NUM_QTRS = 4;
    double sales[NUM_DIVS][NUM_QTRS]; // sales as per company's division and qtrs
    double total_sales = 0;
    int div, qtr;

    // promt the user to enter the sales information for each division on every quaters
    cout << "This program will calculate the total sales of\n"
         << "all the company's division."
         << "Enter the following sales information." << endl;

    for (div = 0; div < NUM_DIVS; div++)
    {
        for (qtr = 0; qtr < NUM_QTRS; qtr++)
        {
            cout << "Division " << (div + 1) << " , Quarter " << (qtr + 1) << " : ";
            cin >> sales[div][qtr];
        }
        cout << endl;
    }

    // display the sales information and total
    cout << setprecision(2) << showpoint << fixed;
    for (div = 0; div < NUM_DIVS; div++)
    {
        for (qtr = 0; qtr < NUM_QTRS; qtr++)
        {
            cout << "Division " << (div + 1) << " , Quarter " << (qtr + 1) << " : " << sales[div][qtr] << endl;
            total_sales += sales[div][qtr];
        }
        cout << "-------------------------------------" << endl;
    }
    cout << "Total sales for the company : " << total_sales << endl;
    return 0;
}