/*
This program keeps track of sales for five different types of salsa.
It reports the sales for each salsa, total sales, highest and lowest selling salsa.
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Function prototypes
void showSales(string[], int[], int);
int cal_totalSales(int[], int);
int findHighestSales(int[], int);
int findLowestSales(int[], int);

int main()
{
    const int SIZE = 5;
    string salsa[SIZE] = {"mild", "medium", "sweet", "hot", "zesty"};
    int sales[SIZE];
    int total_sales, highest, lowest;

    // Get user input
    for (int i = 0; i < SIZE; i++)
    {
        do
        {
            cout << "Enter the number of jars sold for " << salsa[i] << " salsa: ";
            cin >> sales[i];
            if (sales[i] < 0)
                cout << "Sales cannot be negative. Please enter again.\n";
        } while (sales[i] < 0);
    }

    cout << "\n--- Salsa Sales Report ---\n";
    showSales(salsa, sales, SIZE);

    // Calculate total, highest, and lowest sales
    total_sales = cal_totalSales(sales, SIZE);
    highest = findHighestSales(sales, SIZE);
    lowest = findLowestSales(sales, SIZE);

    cout << "\nTotal jars sold: " << total_sales << endl;
    cout << "Highest selling salsa: " << salsa[highest] << " (" << sales[highest] << " jars)" << endl;
    cout << "Lowest selling salsa: " << salsa[lowest] << " (" << sales[lowest] << " jars)" << endl;

    return 0;
}

// Display sales for each salsa type
void showSales(string salsa[], int sales[], int size)
{
    cout << left << setw(10) << "Salsa" << "Sales\n";
    cout << "-----------------\n";
    for (int i = 0; i < size; i++)
    {
        cout << left << setw(10) << salsa[i] << sales[i] << endl;
    }
}

// Calculate total sales
int cal_totalSales(int sales[], int size)
{
    int total = 0;
    for (int i = 0; i < size; i++)
        total += sales[i];
    return total;
}

// Find index of highest sales
int findHighestSales(int sales[], int size)
{
    int highest = 0;
    for (int i = 1; i < size; i++)
    {
        if (sales[i] > sales[highest])
            highest = i;
    }
    return highest;
}

// Find index of lowest sales
int findLowestSales(int sales[], int size)
{
    int lowest = 0;
    for (int i = 1; i < size; i++)
    {
        if (sales[i] < sales[lowest])
            lowest = i;
    }
    return lowest;
}