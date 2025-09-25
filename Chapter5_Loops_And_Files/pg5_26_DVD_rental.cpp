/*
This program calculates the charges for DVD rentals, where the current releases cost 3.50 and all others cost 2.50.
If customer rents several DVDs, every third one is free.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

    // constants for charges
    const double CURRENT_RELEASE = 3.50,
                 OLD_RELEASE = 2.50;

    // variables
    int total_number_dvd,
        count_dvd;
    char user_option;
    double charges = 0; // accumulater initialized to zero

    // get the totat number of dvd that user renting
    cout << "Enter the total number of DVD that you are renting: ";
    cin >> total_number_dvd;

    for (count_dvd = 1; count_dvd <= total_number_dvd; count_dvd++)
    {
        if (count_dvd % 3 == 0)
        {
            cout << "You are getting one free dvd for every three!" << endl;
            continue;
        }

        // ask if the dvd is current release or old release
        cout << "Is the DVD No: " << count_dvd << " is current release?\nPlease enter y/Y: ";
        cin >> user_option;

        if (user_option == 'y' || user_option == 'Y')
        {
            charges += CURRENT_RELEASE;
        }
        else
        {
            charges += OLD_RELEASE;
        }
    }

    // print out the total charges
    cout << "Thank you and this will be the total charges: " << charges
         << " for " << total_number_dvd << " DVDs." << endl;

    return 0;
}
