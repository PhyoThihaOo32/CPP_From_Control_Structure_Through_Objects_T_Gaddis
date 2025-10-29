/*
This program calculates how much a person would earn over a period of time
if their salary starts at one penny the first day and doubles each day after that.
It displays a table showing daily pay and the total pay at the end of the period.
(All amounts are shown in dollars.)
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    int num_days;
    double salary_per_day = 0.01; // starting at 1 penny
    double total_pay = 0.0;

    cout << "Enter the number of days worked: ";
    cin >> num_days;

    // Input validation
    while (num_days < 1)
    {
        cout << "Invalid input. Number of days must be at least 1: ";
        cin >> num_days;
    }

    cout << fixed << showpoint << setprecision(2);
    cout << "\nDay" << setw(20) << "Salary (in $)" << endl;
    cout << "----------------------------------\n";

    // Loop for each day
    for (int day = 1; day <= num_days; day++)
    {
        cout << setw(3) << day << setw(20) << salary_per_day << endl;
        total_pay += salary_per_day; // accumulate total
        salary_per_day *= 2;         // double the pay each day
    }

    cout << "----------------------------------\n";
    cout << "Total pay: $" << setw(11) << total_pay << endl;

    return 0;
}