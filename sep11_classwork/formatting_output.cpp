/*
This program demostrate formatting output.
showpoint - shows the floating point values.
fixed - doesn't changed the format to e-notation.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

    const float PI = 3.14159265359;
    float gpa = 4.0;

    // cout << fixed << 12345678.12345 << endl; // e notation - 10 to the power.

    // cout << PI << endl;
    // cout << gpa << showpoint << endl; // showpoint shows the floating point values.

    // // cout << noshowpoint << gpa << endl;

    // // controlling the total number of digits ( before and after the decimal)

    // cout << setprecision(9) << showpoint;
    // cout << PI << endl;
    // cout << 3.142 << endl;

    // controlling the number of digits after the decimals

    cout << showpoint << fixed << setprecision(5);
    cout << PI << endl;

    return 0;
}