/*
This program demonstrates an array of class objects.
*/

#include <iostream>
#include "InventoryItem.h"
#include <iomanip>

int main()
{

    const int SIZE = 5;
    InventoryItem items[SIZE] = {
        InventoryItem("Hammer"),
        InventoryItem("Knife", 19.99, 100),
        InventoryItem("Needle", 0.99, 1000),
        InventoryItem("Window Blinds", 34.99, 20),
        InventoryItem("Cat Wet Foods", 24.99, 10)};

    cout << setw(20) << left << "Inventory Item"
         << setw(10) << right << "Cost"
         << setw(15) << "Units on Hand" << endl;
    cout << "--------------------------------------------------------\n";

    for (int i = 0; i < SIZE; i++)
    {
        items[i].showItems();
    }

    return 0;
}