/*
This program asks the user for the speed of a vehicle (in miles per hour) and how many hours it has
traveled. The program should then use a loop to display the distance the vehicle has traveled for each hour
of that time period.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

    double speed, time_traveled, distance_traveled;

    do
    {
        cout << "Enter the speed(mph) of the vehicle: " << endl;
        cin >> speed;
    } while (speed <= 0);

    do
    {
        cout << "Enter the time traveled in hours: " << endl;
        cin >> time_traveled;
    } while (time_traveled <= 1);

    // Display header
    cout << "\nHour" << setw(20) << "Distance Traveled (miles)\n";
    cout << "----------------------------------------\n";

    // Loop for each hour
    cout << fixed << showpoint << setprecision(2);
    for (int hour = 1; hour <= time_traveled; hour++)
    {
        distance_traveled = speed * hour;
        cout << setw(4) << hour << setw(20) << distance_traveled << endl;
    }

    return 0;
}