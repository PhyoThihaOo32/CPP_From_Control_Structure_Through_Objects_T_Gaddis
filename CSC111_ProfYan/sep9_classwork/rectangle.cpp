/*
This is another rectangle program using funciton from math library
*/

#include <iostream>
#include <cmath> // for using math function - c programming language already took the name math so it has to be cmath
#include <iomanip>

using namespace std;

int main()
{

    double length, width, diagonal;

    cout << "Enter length: ";
    cin >> length;

    cout << "Enter width: ";
    cin >> width;

    // Calculating Pythagoran Theorem
    diagonal = sqrt(pow(length, 2.0) + pow(width, 2.0));

    cout << "Length of the diagonal: " << setprecision(2) << fixed
         << diagonal << " m" << endl;

    return 0;
}