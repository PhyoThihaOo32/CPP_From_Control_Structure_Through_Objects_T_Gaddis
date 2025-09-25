/*
This program calculate employee's gross pay, base pay including overtime pay.
*/

#include <iostream>
#include <iomanip>

using namespace std;

// global constants
const double BASE_PAY_RATE = 22.55,
             BASE_HOUR = 40,
             OVERTIME_PAY_RATE = 1.5;

// function prototypes
double calculateBasePay(double);
double calculateOvertimePay(double);

int main()
{

    // variable
    double hours_weekly,
        base_pay,
        overtime_pay;

    // get working hour from the user
    cout << "Enter your weekly working hour: ";
    cin >> hours_weekly;

    // validate the input
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Enter your weekly working hour: ";
        cin >> hours_weekly;
    }

    // calculate basepay
    base_pay = calculateBasePay(hours_weekly);

    // calculate overtime pay
    overtime_pay = calculateOvertimePay(hours_weekly);

    // set the numeric output format
    cout << setprecision(2) << showpoint << fixed;

    // print out the result
    cout << "Base pay:\t" << base_pay << " $\n"
         << "Overtime pay:\t" << overtime_pay << " $\n"
         << "Total pay:\t" << (base_pay + overtime_pay) << " $" << endl;
}

// this function calculate the base pay.
double calculateBasePay(double workingHours)
{
    if (workingHours > BASE_HOUR)
    {
        return BASE_HOUR * BASE_PAY_RATE;
    }
    else
    {
        return workingHours * BASE_PAY_RATE;
    }
}

// this function calculate overtime pay
double calculateOvertimePay(double workingHours)
{
    if (workingHours > BASE_HOUR)
    {
        return (workingHours - BASE_HOUR) * BASE_PAY_RATE * OVERTIME_PAY_RATE;
    }
    else
    {
        return calculateBasePay(workingHours);
    }
}
