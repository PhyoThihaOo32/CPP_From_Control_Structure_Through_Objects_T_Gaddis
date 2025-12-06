/*
This program calculates an item sale — showing cost, tax, and total amount.
*/

#include <iostream>
#include <iomanip>
#include "Sale.h"
using namespace std;

int main()
{
    const double TAX_RATE = 0.06; // 6% sales tax
    double cost;

    cout << "Enter item cost: $";
    cin >> cost;

    // Create a Sale object with the entered cost and predefined tax rate
    Sale shoePrice(cost, TAX_RATE);

    cout << fixed << setprecision(2);

    cout << "\n---- Sale Summary ----\n";
    cout << "Item cost : $" << setw(8) << shoePrice.getCost() << endl;
    cout << "Tax rate  : " << setw(9) << (shoePrice.getRate() * 100) << "%\n";
    cout << "Tax amount: $" << setw(8) << shoePrice.getTaxAmount() << endl;
    cout << "Total     : $" << setw(8) << shoePrice.getTotal() << endl;
    cout << "----------------------\n";

    return 0;
}