/*
(Assuming that ocean's level is currently rising at about 1.5 millimeters per year) This program display
at table showing the number of millimeters that the ocean will have risen each year for the next 25 years.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

    const int STARTING_YEAR = 2025;
    const float RISE_PER_YEAR = 1.5;
    float cur_ocean_lvl = 0.0;

    cout << setprecision(2) << showpoint << fixed;

    // Table header
    cout << "Year" << setw(17) << "Rise (mm)" << endl;
    cout << "-------------------------" << endl;

    for (int i = STARTING_YEAR; i <= (STARTING_YEAR + 25); i++)
    {
        cur_ocean_lvl += RISE_PER_YEAR;
        cout << i << setw(12) << cur_ocean_lvl << endl;
    }

    cout << "-------------------------" << endl;

    return 0;
}