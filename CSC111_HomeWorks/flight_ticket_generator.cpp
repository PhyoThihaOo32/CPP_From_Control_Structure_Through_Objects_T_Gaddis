/*
This program will ask the flight informations from the user and
calculate the distance, time, and speed and set the numeric data format.
Finally will print out the flight summary to the console.
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{

    // constant km to miles conversion
    const double KM_PER_MI = 1.609344;

    // variables for the program
    string city_from,
        city_to,
        name_airline;

    double distance_miles,
        distance_km,
        speed,
        ticket_price;

    float total_duration_min;

    unsigned duration_hour,
        duration_min;

    // get city names(to and from)
    cout << "Which city are you flying from?\t\t";
    getline(cin, city_from);

    cout << "Which city are you flying to?\t\t";
    getline(cin, city_to);

    // get flight distance in miles
    cout << "How many miles is the flight?\t\t";
    cin >> distance_miles;

    // get flight duration in minutes
    cout << "How many minutes is the flight?\t\t";
    cin >> total_duration_min;

    // get the ticket price
    cout << "How much was your ticket?\t\t";
    cin >> ticket_price;
    cin.ignore();

    // get the name of the airline
    cout << "What is the name of the airline?\t";
    getline(cin, name_airline);

    // calculate and convert the distance to kilometer [kilometers will be equal to the miles multiplied by KM_PER_M]
    distance_km = distance_miles * KM_PER_MI;

    // calculate and convert total minutes into hour and minutes
    duration_hour = total_duration_min / 60;
    duration_min = static_cast<int>(total_duration_min) % 60;

    // calulate speed(miles/hour)
    speed = distance_miles / (total_duration_min / 60);

    // format the numeric data and print out the flight summary
    cout << "---------Flight Summary---------" << endl;
    cout << endl;
    cout << "Distance:\t" << distance_miles << " mi ";
    cout << setprecision(3) << showpoint << fixed
         << "(" << distance_km << " km)" << endl;
    cout << "Duration:\t" << duration_hour << " hr " << duration_min << " min" << endl;
    cout << "Speed(mph):\t" << speed << " miles per hour" << endl;
    cout << setprecision(2) << showpoint << "Ticker price:\t" << "$" << ticket_price << endl;
    cout << endl;
    cout << "Thank you for flying from " << city_from << " to "
         << city_to << " with " << name_airline;

    return 0;
}