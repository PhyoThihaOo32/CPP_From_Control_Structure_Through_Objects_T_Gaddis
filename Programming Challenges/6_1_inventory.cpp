#include <iostream>
#include <iomanip>
#include "Inventory.h"
using namespace std;

int main()
{
    Inventory item1(1001, 5, 29.99);
    Inventory item2;

    cout << fixed << setprecision(2);

    cout << "Item 1 Info:\n";
    cout << "Item Number: " << item1.getItemNumber() << endl;
    cout << "Quantity: " << item1.getQuantity() << endl;
    cout << "Cost per unit: $" << item1.getCost() << endl;
    cout << "Total Cost: $" << item1.getTotalCost() << endl
         << endl;

    // Setting values for item2
    item2.setItemNumber(1002);
    item2.setQuantity(10);
    item2.setCost(15.50);

    cout << "Item 2 Info:\n";
    cout << "Item Number: " << item2.getItemNumber() << endl;
    cout << "Quantity: " << item2.getQuantity() << endl;
    cout << "Cost per unit: $" << item2.getCost() << endl;
    cout << "Total Cost: $" << item2.getTotalCost() << endl;

    return 0;
}