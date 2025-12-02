/*
This program demonstrates the use of an enumerated data type (enum)
to record and calculate total sales for each day of the work week.
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Define enumeration for weekdays
enum Days
{
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY
};

int main()
{
    const int NUM_DAYS = 5;
    double sales[NUM_DAYS];
    double totalSales = 0.0;

    // Array of day names for user-friendly display
    string dayNames[NUM_DAYS] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

    // Input: get sales for each day
    for (int day = MONDAY; day <= FRIDAY; day++)
    {
        cout << "Enter the sales figure for " << dayNames[day] << ": $";
        cin >> sales[day];
    }

    // Processing: calculate total sales
    for (int day = MONDAY; day <= FRIDAY; day++)
    {
        totalSales += sales[day];
    }

    // Output: display all daily sales and total
    cout << fixed << setprecision(2) << showpoint;
    cout << "\n--- Weekly Sales Report ---\n";
    for (int day = MONDAY; day <= FRIDAY; day++)
    {
        cout << setw(10) << left << dayNames[day] << ": $" << sales[day] << endl;
    }
    cout << "----------------------------\n";
    cout << setw(10) << left << "Total" << ": $" << totalSales << endl;

    return 0;
}