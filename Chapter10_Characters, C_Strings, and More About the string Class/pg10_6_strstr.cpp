/*
This program uses the strstr function to search an array.
*/

#include <iostream>
#include <cstring>

using namespace std;

int main()
{

    // constant for array
    const int NUM_PRODS = 5;
    const int LENGTH = 30;

    // array of product
    char products[NUM_PRODS][LENGTH] = {
        "Samsung 55-inch UHD Smart TV",
        "Sony VHS VCR Player",
        "Logitech Remote Control",
        "Sony Portable CD Player",
        "Panasonic Tape Recorder"};

    char searchProd[LENGTH]; // to hold the searched product
    int index = 0;           // loop counter
    char *strPtr = nullptr;  // to point to the searched product

    // ask user for a product number to look for
    cout << "Enter the name of the product to look for: ";
    cin.getline(searchProd, LENGTH);

    // search the array for a matching product
    for (index = 0; index < NUM_PRODS; index++)
    {
        strPtr = strstr(products[index], searchProd);
        if (strPtr != nullptr) // that mean we found the product and break the loop
            break;
    }

    // display the product
    if (strPtr != nullptr)
    {
        cout << products[index] << endl;
    }
    else
    {
        cout << "No matching product was found." << endl;
    }

    return 0;
}