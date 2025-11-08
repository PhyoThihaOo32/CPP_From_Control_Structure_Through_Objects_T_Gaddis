/*
This program collects and calculates the average rainfall over a period of years.
The user enters the number of years, and for each month in each year,
the program asks for the inches of rainfall.
At the end, it displays the total months, total rainfall, and average rainfall per month.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    const int MONTHS = 12;
    int years;
    double amount_rainfall;
    double ttl_amount_rainfall = 0.0;

    cout << "Enter the number of years: ";
    cin >> years;

    // Validate input
    while (years <= 0)
    {
        cout << "Invalid input. Number of years must be greater than 0: ";
        cin >> years;
    }

    // Collect rainfall data
    for (int i = 1; i <= years; i++)
    {
        cout << "\n---------- Year " << i << " ----------" << endl;

        for (int month = 1; month <= MONTHS; month++)
        {
            cout << "Enter the inches of rainfall for month " << month << ": ";
            cin >> amount_rainfall;

            // Validate rainfall input
            while (amount_rainfall < 0)
            {
                cout << "Invalid input. Rainfall cannot be negative. Try again: ";
                cin >> amount_rainfall;
            }

            ttl_amount_rainfall += amount_rainfall;
        }
    }

    // Calculate totals
    int total_months = years * MONTHS;
    double avg_rainfall_per_month = ttl_amount_rainfall / total_months;

    // Display results
    cout << fixed << showpoint << setprecision(2);
    cout << "\n=====================================\n";
    cout << "Total number of months: " << total_months << endl;
    cout << "Total inches of rainfall: " << ttl_amount_rainfall << endl;
    cout << "Average rainfall per month: " << avg_rainfall_per_month << " inches" << endl;
    cout << "=====================================\n";

    return 0;
}