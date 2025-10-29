/*
A country club, which currently charges $2,500 per year for membership, has announced it will
increase its membership fee by 4% each year for the next six years.
This program uses a loop to display the projected rates for the next six years.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

    const double CURR_MEMBERSHIP = 2500.00;
    const double ANNUAL_INCREASE_RATE = 0.04;

    double total_amount = CURR_MEMBERSHIP;

    cout << fixed << showpoint << setprecision(2);
    cout << "Years" << setw(30) << "Projected Membership Fee\n";
    cout << "------------------------------------------\n";

    for (int year = 1; year <= 6; year++)
    {
        total_amount += total_amount * ANNUAL_INCREASE_RATE;

        cout << year << setw(15) << total_amount << "$" << endl;
    }

    return 0;
}