/*
The fixed manipulator is used with cout to format floating-point numbers so that they always show a fixed number of digits after the decimal point.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

    double day1, day2, day3, total;

    // Get the sales for each day.
    cout << "Enter the sales for day 1: ";
    cin >> day1;
    cout << "Enter the sales for day 2: ";
    cin >> day2;
    cout << "Enter the sales for day3; ";
    cin >> day3;

    // Calculate the total sales.
    total = day1 + day2 + day3;

    // Display the sales figures.
    cout << "\n-----Sales Figures-----\n";
    cout << setprecision(4) << fixed; // You can set the precision and fixed manipulator once, and it will apply to all subsequent floating-point outputs using cout — until you change it again.
    cout << "Day 1: " << setw(10) << day1 << endl;
    cout << "Day 2: " << setw(10) << day2 << endl;
    cout << "Day 3: " << setw(10) << day3 << endl;
    cout << "Total: " << setw(10) << total << endl;

    return 0;
}