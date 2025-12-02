/*
This program demonstrates using an enum variable as an array subscript
to store and calculate sales for each weekday.
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Define days of the work week as enumerated constants
enum Days
{
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY
};

void displayDays(Days);

int main()
{
    const int NUM_DAYS = 5;
    double sales[NUM_DAYS];
    string dayNames[NUM_DAYS] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    Days workDay; // enum variable
    double totalSales = 0.0;

    // Input: Get sales for each day
    for (workDay = MONDAY; workDay <= FRIDAY; workDay = static_cast<Days>(workDay + 1))
    {
        cout << "Enter sales for ";
        displayDays(workDay);
        cout << ": $";
        cin >> sales[workDay];
    }

    cout << "\n--- Weekly Sales Summary ---\n";

    // Processing: Calculate total and display each day's sales
    cout << fixed << setprecision(2) << showpoint;
    for (workDay = MONDAY; workDay <= FRIDAY; workDay = static_cast<Days>(workDay + 1))
    {
        cout << setw(10) << left << dayNames[workDay]
             << ": $" << sales[workDay] << endl;
        totalSales += sales[workDay];
    }

    // Output: Display total sales
    cout << "----------------------------\n";
    cout << setw(10) << left << "Total"
         << ": $" << totalSales << endl;

    return 0;
}

void displayDays(Days d)
{
    switch (d)
    {
    case MONDAY:
        cout << "Monday";
        break;
    case TUESDAY:
        cout << "Tuesday";
        break;
    case WEDNESDAY:
        cout << "Wednesday";
        break;
    case THURSDAY:
        cout << "Thursday";
        break;
    case FRIDAY:
        cout << "Friday";
        break;
    default:
        cout << "Invalid Day";
        break;
    }
}