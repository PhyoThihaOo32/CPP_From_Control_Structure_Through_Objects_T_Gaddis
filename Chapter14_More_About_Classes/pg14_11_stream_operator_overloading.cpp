/*
This program demonstrate the use of << and >> operator overloading.
*/

#include <iostream>
#include "FeetInches.h"

ostream &operator<<(ostream &, const FeetInches &);
istream &operator>>(istream &, const FeetInches &);

using namespace std;

int main()
{

    FeetInches first, second;

    // get the distance for first object
    cout << "Enter the distance in feet and inches: ";
    cin >> first;

    // get the distance for the second object
    cout << "Enter the distance in feet and inches: ";
    cin >> second;

    // display the values in the objects
    cout << "The values in first object: " << first << endl
         << "The values in second object: " << second << endl;

    return 0;
}
