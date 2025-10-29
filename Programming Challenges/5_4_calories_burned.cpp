/*
Running on a particular treadmill you burn 3.6 calories per minute.
This program uses a loop to display the number of calories burned
after 5, 10, 15, 20, 25, and 30 minutes (or user-defined intervals).
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    const double CAL_BURN_PER_MIN = 3.6;
    int display_interval, total_running_time;

    cout << "Enter the minute interval to show the calories burned: ";
    cin >> display_interval;

    // Input validation
    while (display_interval <= 0)
    {
        cout << "Invalid input. Please enter a positive interval: ";
        cin >> display_interval;
    }

    cout << "Enter the total running time (in minutes): ";
    cin >> total_running_time;

    cout << fixed << setprecision(1);
    cout << "\nTime (min)" << setw(20) << "Calories Burned\n";
    cout << "---------------------------------\n";

    // Loop from interval up to total time
    for (int i = display_interval; i <= total_running_time; i += display_interval)
    {
        double calories = CAL_BURN_PER_MIN * i;
        cout << setw(5) << i << setw(20) << calories << endl;
    }

    return 0;
}