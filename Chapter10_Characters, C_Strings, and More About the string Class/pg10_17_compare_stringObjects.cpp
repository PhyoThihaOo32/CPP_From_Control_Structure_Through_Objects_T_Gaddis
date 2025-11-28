/*
This program uses the == operator to compare the string entered by the user with the valid stereo part numbers.
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{

    const double APRICE = 249.0;
    const double BPRICE = 299.0;

    string partNum;

    cout << "The stereo part numbers are:\n";
    cout << "S-29A for the Super Stereo\n";
    cout << "S-29B for the Advanced Stereo\n";
    cout << "Enter the part number of the stereo you wish to purchase: ";
    cin >> partNum;

    cout << fixed << showpoint << setprecision(2);

    if (partNum == "S-29A")
        cout << "The price is $" << APRICE << endl;
    else if (partNum == "S-29B")
        cout << "The price is $" << BPRICE << endl;
    else
        cout << partNum << " is not a valid part number.\n";

    return 0;
}