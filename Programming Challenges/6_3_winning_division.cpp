/*
This program determines which of a company's four divisions
(Northeast, Southeast, Northwest, Southwest) has the greatest sales for a quarter.
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

double getSales(const string &);
void findHighest(double, double, double, double);

const int NUM_DIVISION = 4;

int main()
{
    string divName_ne = "North East",
           divName_se = "South East",
           divName_nw = "North West",
           divName_sw = "South West";

    double ne_sale, se_sale, nw_sale, sw_sale;

    cout << fixed << showpoint << setprecision(2);

    ne_sale = getSales(divName_ne);
    se_sale = getSales(divName_se);
    nw_sale = getSales(divName_nw);
    sw_sale = getSales(divName_sw);

    findHighest(ne_sale, se_sale, nw_sale, sw_sale);

    return 0;
}

//--------------------------------------------
// Get and validate the sales for each division
//--------------------------------------------
double getSales(const string &division_name)
{
    double sales;
    do
    {
        cout << "Enter the quarterly sales for " << division_name << " division: $";
        cin >> sales;

        if (sales < 0)
            cout << "Invalid input. Sales cannot be negative. Please re-enter.\n";
    } while (sales < 0);

    return sales;
}

//--------------------------------------------
// Determine and print which division had the highest sales
//--------------------------------------------
void findHighest(double ne_sales, double se_sales, double nw_sales, double sw_sales)
{
    double sales_division[NUM_DIVISION] = {ne_sales, se_sales, nw_sales, sw_sales};
    string div_names[NUM_DIVISION] = {"North East", "South East", "North West", "South West"};

    double max_sales = sales_division[0];
    string max_div = div_names[0];

    for (int i = 1; i < NUM_DIVISION; i++)
    {
        if (sales_division[i] > max_sales)
        {
            max_sales = sales_division[i];
            max_div = div_names[i];
        }
    }

    cout << "\n=========================================\n";
    cout << max_div << " Division had the highest sales: $" << max_sales << endl;
    cout << "=========================================\n";
}