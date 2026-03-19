/*
This program can edit the inventory records.
*/

#include <iostream>
#include <fstream>

using namespace std;

const int DESC_SIZE = 35;

struct InventoryItem
{
    char desc[DESC_SIZE];
    int quantity;
    double price;
};

int main()
{

    InventoryItem record;
    int recNum;

    fstream file("Inventory.dat", ios::out | ios::in | ios::binary);

    // get the record number from the user
    cout << "Which record you want to edit?" << endl;
    cin >> recNum;

    // move to the record and read it
    file.seekg(recNum * sizeof(record), ios::beg);
    file.read(reinterpret_cast<char *>(&record), sizeof(record));

    // display the record content
    cout << "Description: " << record.desc << endl
         << "Quantity: " << record.quantity << endl
         << "Price: " << record.price << endl;

    // enter data into the record
    cout << "Enter new data" << endl;
    cin.ignore();
    cout << "Description: ";
    cin.getline(record.desc, DESC_SIZE);
    cout << "Quantity: ";
    cin >> record.quantity;
    cout << "Price: ";
    cin >> record.price;

    // move back to the beginning of the record position
    file.seekp(recNum * sizeof(record), ios::beg);
    file.write(reinterpret_cast<char *>(&record), sizeof(record));

    // close the file
    file.close();

    return 0;
}