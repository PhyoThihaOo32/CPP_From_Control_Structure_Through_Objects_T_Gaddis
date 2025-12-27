/*
This program demonstrates how to format floating-point output in C++ using:
- showpoint  : always show the decimal point
- fixed      : display numbers in fixed-point notation (no scientific notation)
- setprecision : control number of digits or decimal places
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // Constants and variables
    const float PI = 3.14159265359;
    float gpa = 4.0;

    // ===== Without formatting =====
    cout << "Default PI: " << PI << endl;
    cout << "Default GPA: " << gpa << endl;

    // ===== showpoint =====
    cout << "\nUsing showpoint (forces decimal point even for whole numbers):" << endl;
    cout << showpoint << gpa << endl;

    // ===== setprecision =====
    cout << "\nUsing setprecision(9) with showpoint (total digits displayed):" << endl;
    cout << setprecision(9) << showpoint << PI << endl;
    cout << setprecision(9) << 3.142 << endl;

    // ===== fixed + setprecision =====
    cout << "\nUsing fixed + setprecision(5) (controls digits after decimal):" << endl;
    cout << fixed << setprecision(5) << PI << endl;

    return 0;
}