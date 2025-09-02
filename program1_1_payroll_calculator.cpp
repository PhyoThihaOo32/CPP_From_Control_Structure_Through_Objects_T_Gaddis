/*
simple payroll calculator
*/

#include <iostream>

using namespace std;

int main()
{

    double hours, rate, total_pay;

    cout << "How many hours did you work? " << endl;
    cin >> hours;

    cout << "How much do you get paid per hour? " << endl;
    cin >> rate;

    // calculate total_pay
    total_pay = hours * rate;

    cout << "This is the amount of money you earned: " << total_pay << " $" << endl;

    return 0;
}
