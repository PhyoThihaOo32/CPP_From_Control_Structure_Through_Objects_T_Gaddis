/*
This program display a table of speed in kmp with their value converted to mph.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

    // constants
    const int MIN_KPH = 60,
              MAX_KPH = 130;
    const double KPH_TO_MPH = 0.6214;

    // counter variable
    int kph;
    double mph;

    // set the numeric data output
    cout << fixed << showpoint << setprecision(1);

    cout << "KPH\t\t" << "MPH" << endl;
    cout << "--------------------" << endl;

    for (kph = MIN_KPH; kph <= MAX_KPH; kph += 10)
    {
        // convert KPH to MPH
        mph = kph * KPH_TO_MPH;
        cout << kph << "\t\t" << mph << endl;
    }

    return 0;
}