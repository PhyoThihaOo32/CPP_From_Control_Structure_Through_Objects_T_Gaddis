/*
This program demonstrate the use of array.
*/

#include <iostream>

using namespace std;

int main()
{

    const int DAYS = 7;

    double temperature[DAYS] = {50.5, 52.3, 48.7, 49.2, 51.0}; // initialized first 5 days

    temperature[5] = 49.2; // assign the 6 element in the array

    // ask the user for the temperature for sunday(day 7)
    cout << "Enter the temperature for Sunday. ";
    cin >> temperature[6];

    // print out the array using range-based for loop
    for (double temp : temperature)
    {
        cout << temp << " ";
    }

    // using for loop
    for (int i = 0; i < DAYS; i++)
    {
        cout << "Temperature for day " << i + 1 << " :" << temperature[i] << endl;
    }

    cout << endl;

    // printing reverse using for loop
    for (int i = DAYS - 1; i >= 0; i--)
    {
        cout << "Temperature for day " << i + 1 << " :" << temperature[i] << endl;
    }

    return 0;
}