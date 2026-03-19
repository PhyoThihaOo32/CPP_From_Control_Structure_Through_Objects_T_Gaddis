/*
This program sets up a file of blank inventory records.
*/

#include <iostream>
#include <fstream>

using namespace std;

// constants
const int DESC_SIZE = 31;
const int NUM_RECORDS = 5;

// declaration of InventoryItem structure
struct InventoryItem
{
    char desc[DESC_SIZE];
    int qty;
    double price;
};

int main()
{
    // create an empty InventoryItem structure
    InventoryItem record = {"", 0, 0.0};

    // open the file for binary output
    fstream inventory("Inventory.dat", ios::out | ios::binary);

    // write the blank records
    for (int count = 0; count < NUM_RECORDS; count++)
    {
        cout << "Now writing record " << count << endl;
        inventory.write(reinterpret_cast<char *>(&record), sizeof(record));
    }

    // close the file
    inventory.close();

    return 0;
}