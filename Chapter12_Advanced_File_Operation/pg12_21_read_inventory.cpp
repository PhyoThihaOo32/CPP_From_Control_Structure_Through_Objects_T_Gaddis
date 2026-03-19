/*
This program read the record of inventory and display the data.
*/

#include <iostream>
#include <fstream>

using namespace std;

const int DESC_SIZE = 50;

// inventory record
struct InventoryItem
{
    char desc[DESC_SIZE];
    int quantity;
    double price;
};

int main()
{

    InventoryItem record;

    // file stream object to read
    fstream file("inventory.dat", ios::in | ios::binary);

    file.read(reinterpret_cast<char *>(&record), sizeof(record));

    while (!file.eof())
    {
        cout << "Description: " << record.desc << endl
             << "Quantity: " << record.quantity << endl
             << "Price: " << record.price << endl;

        file.read(reinterpret_cast<char *>(&record), sizeof(record));
    }

    // close the file
    file.close();

    return 0;
}