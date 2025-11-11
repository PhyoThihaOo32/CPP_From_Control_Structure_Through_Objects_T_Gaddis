/*
This program demonstrates that a pointer may be used as a parameter
to accept the address of an array.
*/

#include <iostream>
#include <iomanip>
using namespace std;

void getSales(double *sales, int size);
double totalSales(double *sales, int size);

int main()
{
    const int SIZE = 4;
    double sales[SIZE];

    // Get user input
    getSales(sales, SIZE);

    // Display total sales
    cout << fixed << showpoint << setprecision(2);
    cout << "Total sales: $" << totalSales(sales, SIZE) << endl;

    return 0;
}

void getSales(double *sales, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the sales figure for Quarter " << (i + 1) << ": ";
        cin >> *(sales + i);
    }
}

double totalSales(double *sales, int size)
{
    double sum = 0.0;
    for (int i = 0; i < size; i++)
    {
        sum += *(sales + i); // pointer arithmetic form (same as sales[i])
    }
    return sum;
}