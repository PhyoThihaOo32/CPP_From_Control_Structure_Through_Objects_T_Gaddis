/*
This program produces a sales report for DLC, Inc.
*/

#include <iostream>
#include <iomanip>

using namespace std;

// function prototypes
void calcSales(const int[], const double[], double[], int);
void showSales(const double[], int);
void dualSort(double[], int[], int);
void showOrder(const int[], const double[], int);
void showTotal(const int[], const double[], int);

// global const for ttl elements for all arrays
const int NUM_PRODS = 9;

int main()
{

    // array with product id numbers
    int id[NUM_PRODS] = {914, 915, 916, 917, 918, 919, 920, 921, 922};

    // array with number of units sold for each product
    int units[NUM_PRODS] = {842, 416, 127, 514, 437, 269, 97, 492, 212};

    // array wih product price
    double prices[NUM_PRODS] = {12.95, 14.95, 18.95, 16.95, 21.95, 31.95, 14.95, 16.95, 14.95};

    // array to hold the computed sales amount
    double sales[NUM_PRODS];

    // set numeric data output
    cout << setprecision(2) << showpoint << fixed;

    // calculate sales and display
    calcSales(units, prices, sales, NUM_PRODS);
    showSales(sales, NUM_PRODS);

    // sort sales and product id in descending order and display
    dualSort(sales, id, NUM_PRODS);
    showOrder(id, sales, NUM_PRODS);

    // calculate and display ttl units and ttl sales
    showTotal(units, sales, NUM_PRODS);

    return 0;
}

// This function calculates each product's sales by multiplying its units sold by each unit's price.
void calcSales(const int units[], const double price[], double sales[], int size)
{
    for (int i = 0; i < size; i++)
    {
        sales[i] = units[i] * price[i];
    }
}

void showSales(const double sales[], int size)
{
    cout << "-----Sales------" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << setw(10) << sales[i] << endl;
    }
}

// This function performs a descending order selection sort on the sales array. The elements of the id array are exchanged
// identically as those of the sales array.(In other word, this function sort sales and id array in descending order parallelly.)

void dualSort(double sales[], int id[], int size)
{
    int startScan, maxIndex, maxId;
    double maxSaleValue;
    for (startScan = 0; startScan < size - 1; startScan++)
    {
        maxSaleValue = sales[startScan];
        maxId = id[startScan];
        maxIndex = startScan;
        for (int index = startScan + 1; index < size; index++)
        {
            if (sales[index] > maxSaleValue)
            {
                maxSaleValue = sales[index];
                maxId = id[index];
                maxIndex = index;
            }
        }
        // swap the values
        sales[maxIndex] = sales[startScan];
        sales[startScan] = maxSaleValue;
        id[maxIndex] = id[startScan];
        id[startScan] = maxId;
    }
}

// This function first display a heading, then the sorted list of product numbes and sales.
void showOrder(const int id[], const double sales[], int size)
{
    cout << "Product ID" << setw(15) << "Sales" << endl;
    cout << "--------------------------------------" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << setw(5) << id[i] << setw(20) << sales[i] << endl;
    }
}

// This function calculates and display the total units(of all products) sold and the total sales.

void showTotal(const int units[], const double sales[], int size)
{
    int ttl_units = 0;
    double ttl_sales = 0;
    for (int i = 0; i < size; i++)
    {
        ttl_units += units[i];
        ttl_sales += sales[i];
    }

    cout << "Total Units Sold: " << ttl_units << endl;
    cout << "Total Sales: " << ttl_sales << endl;
}