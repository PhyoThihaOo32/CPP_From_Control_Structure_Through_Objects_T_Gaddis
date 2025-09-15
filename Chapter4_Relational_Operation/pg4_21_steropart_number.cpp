/*
This program uses relational operator to compare a string
entered by the user with valid stereo part numbers.
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{

    // constant for prices
    const double PRICE_A = 249.0,
                 PRICE_B = 299.0;

    string part_number; // hold stero part number

    // display available parts and get the user's selection
    cout << "The stero part numbers are:\n"
         << "Boom Box: part number S-29A\n"
         << "Shelf Model: part number S-29B\n"
         << "Enter the part number of the stereo you wish to purchase.\n";
    getline(cin, part_number);

    // set the numberic output formatting
    cout << setprecision(2) << fixed << showpoint;

    // determin and display the price
    if (part_number == "S-29A")
    {
        cout << "The price is $ " << PRICE_A << endl;
    }
    else if (part_number == "S-29B")
    {
        cout << "The price is $ " << PRICE_B << endl;
    }
    else
    {
        cout << part_number << " is not valid part number." << endl;
    }

    return 0;
}