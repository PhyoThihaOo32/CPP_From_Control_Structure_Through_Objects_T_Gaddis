/*
When writing a function that use a pointer parameter, and the function is not intended to change the data
the parameter points to, its always a good idea to make the parameter a pointer to a const.
1. to prevent from writing code in the function that accidentally changes the argument
2. to be able to accept the addresses of both constant and nonconstant arguments.
*/

#include <iostream>

using namespace std;

void displaySales(const double *, int);

int main()
{
    const int SIZE = 5;
    const double SALES[SIZE] = {1200.50, 950.75, 1100.00, 875.25, 1340.60};
    double monthly_sales[SIZE] = {900.50, 80.75, 110.00, 85.25, 23.60};
    displaySales(SALES, SIZE);

    cout << "\nA pointer to const can also recevied the address of a nonconstant item." << endl;
    displaySales(monthly_sales, SIZE);
    return 0;
}

void displaySales(const double *ptr_array, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << *(ptr_array + i) << " ";
    }
}