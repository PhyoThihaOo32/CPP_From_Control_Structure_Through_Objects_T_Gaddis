/*
This program demostrate the use of NOT operator.
*/

#include <iostream>

using namespace std;

int main()
{

    // Constant for minium income and years
    const double MIN_INCOME = 35000.0;
    const unsigned MIN_YEAR = 5;

    // User income and year
    double annual_income;
    unsigned years;

    // Get user income and years
    cout << "Enter your annual income: ";
    cin >> annual_income;

    cout << "Enter the number of years at the current job: ";
    cin >> years;

    // Determine the loan qualification
    if (!(annual_income >= MIN_INCOME || years >= MIN_YEAR))
    {
        cout << "You must earn at least " << MIN_INCOME
             << " or have been employed more than " << MIN_YEAR << endl;
        }
    else
    {
        cout << "Congragulation.You are approved!" << endl;
    }

    return 0;
}