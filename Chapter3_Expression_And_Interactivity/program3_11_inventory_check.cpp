/*
This program tracks the inventory of three widget stores.
*/

#include <iostream>

using namespace std;

int main()
{

    int begInv, // Beginning Inventory for all stores
        sold,   // Number of widgets sold
        store1, // Store 1's Inventory
        store2, // Store 2's Inventory
        store3; // Store 3's Inventory

    // Get the beginning inventory for all the stores.
    cout << "What was the beginning inventory for the stores? " << endl;
    cin >> begInv;

    // Multi Assiging the inventory for three stores
    store1 = store2 = store3 = begInv;

    // Get the number of widget sold at store 1.
    cout << "How many widget has store 1 sold?" << endl;
    cin >> sold;
    store1 -= sold; // Adjust store 1 inventory

    // Get the number of widget sold at store 2.
    cout << "How many widget has store 2 sold?" << endl;
    cin >> sold;
    store2 -= sold; // Adjust store 2 inventory

    // Get the number of widget sold at store 3.
    cout << "How many widget has store 3 sold?" << endl;
    cin >> sold;
    store3 -= sold; // Adjust store 3 inventory

    // Display updated store inventory
    cout << "-----Here is the updated store inventory List-----" << endl;
    cout << "Store 1:\t " << store1 << "\n"
         << "Store 2:\t " << store2 << "\n"
         << "Store 3:\t " << store3 << endl;

    return 0;
}