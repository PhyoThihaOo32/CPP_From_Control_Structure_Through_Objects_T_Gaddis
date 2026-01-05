// This program demonstrates the FeetInches class's conversion functions.

#include <iostream>
#include "FeetInches.h"

using namespace std;

int main()
{

    double d;
    int i;

    FeetInches distance;

    cout << "Enter the distance in feet and inches: ";
    cin >> distance;

    d = distance;

    i = distance;

    cout << "The value " << distance
         << " is equivalent to " << d << " feet\n"
         << " or " << i << " feet, rounded down.\n";

    return 0;
}