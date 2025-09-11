/*
This program calculate the user income - weekly, monthly and yearly.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

    // set variables
    double annual_salary, monthly_pay, weekly_pay;

    // ask user for annual salary
    cout << "What is your annual salary?" << endl;
    cin >> annual_salary;

    // calculate monthly_pay
    monthly_pay = annual_salary / 12;

    // calculate  the weekly_pay
    weekly_pay = annual_salary / 52;

    // set the format for the output - 2 digit after the decimal
    cout << setprecision(2) << showpoint << fixed;

    // display the result
    cout << "Monthly pay:\t " << monthly_pay << endl;
    cout << "Weekly pay:\t " << weekly_pay << endl;

    return 0;
}