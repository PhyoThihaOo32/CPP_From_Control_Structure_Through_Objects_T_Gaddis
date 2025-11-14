/*
This program asks the user to enter the item's wholesale cost and its markup percentage.
Then it displays the item's retail price.
*/

#include <iostream>
#include <iomanip>
using namespace std;

// Function prototype
double calculateRetail(double wholesale_cost, double markup_percent);

int main()
{
    double wholesale, markup_perc, retail_price;

    // Get user input with validation
    do
    {
        cout << "Enter the item's wholesale cost: $";
        cin >> wholesale;
    } while (wholesale < 0);

    do
    {
        cout << "Enter the markup percentage: ";
        cin >> markup_perc;
    } while (markup_perc < 0);

    // Calculate retail price
    retail_price = calculateRetail(wholesale, markup_perc);

    // Display results
    cout << fixed << showpoint << setprecision(2);
    cout << "\n--------------------------------------\n";
    cout << "Wholesale Cost:    $" << setw(8) << wholesale << endl;
    cout << "Markup Percentage: " << setw(8) << markup_perc << "%" << endl;
    cout << "Retail Price:      $" << setw(8) << retail_price << endl;
    cout << "--------------------------------------\n";

    return 0;
}

// Function definition
double calculateRetail(double wholesale_cost, double markup_percent)
{
    return wholesale_cost += (wholesale_cost * (markup_percent / 100));
}