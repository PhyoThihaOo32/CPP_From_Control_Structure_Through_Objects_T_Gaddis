/*
This program demonstrates functions that accept structure variables as arguments.
It collects and displays inventory information for a single item.
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Structure to hold inventory item information
struct InventoryItems
{
    int partNum;        // part number
    string description; // item description
    int onHand;         // quantity available
    double price;       // unit price
};

// Function prototypes
void getItems(InventoryItems &);
void showItems(const InventoryItems &);

int main()
{
    InventoryItems laptop;

    // Get item information from the user
    getItems(laptop);

    // Display the collected information
    showItems(laptop);

    return 0;
}

// Function to get item data from the user
void getItems(InventoryItems &invItem)
{
    cout << "Enter part number: ";
    cin >> invItem.partNum;
    cin.ignore(); // clear newline from buffer

    cout << "Enter description: ";
    getline(cin, invItem.description);

    cout << "Enter number of items on hand: ";
    cin >> invItem.onHand;

    cout << "Enter price: $";
    cin >> invItem.price;
}

// Function to display item information
void showItems(const InventoryItems &it)
{
    cout << "\n---------------------------------------------\n";
    cout << "Inventory Item Information\n";
    cout << "---------------------------------------------\n";
    cout << "Part Number: " << it.partNum << endl;
    cout << "Description: " << it.description << endl;
    cout << "Quantity on Hand: " << it.onHand << endl;
    cout << fixed << setprecision(2);
    cout << "Price: $" << it.price << endl;
    cout << "---------------------------------------------\n";
}