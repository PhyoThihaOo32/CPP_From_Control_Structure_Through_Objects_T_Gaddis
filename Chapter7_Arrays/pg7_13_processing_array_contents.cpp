/*
This program stores, in an array, the hours worked by employees who all make the same hourly wage.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

    const int NUM_EMPLOYEES = 5; // number of employees
    int hours[NUM_EMPLOYEES];
    double payrates; // hourly pay rate
    double grossPay; // to hold the gross pay

    // input the hour worked
    cout << "Enter the hour of works for " << NUM_EMPLOYEES
         << " employees." << endl;
    for (int i = 0; i < NUM_EMPLOYEES; i++)
    {
        cout << "Employee " << (i + 1) << " : ";
        cin >> hours[i];
    }

    // input the hourly rate for all employees
    cout << "Enter ther hourly pay rate for all the employees: ";
    cin >> payrates;

    // set the numeric data output format
    cout << setprecision(2) << fixed << showpoint;

    // display each employee gross pay
    for (int i = 0; i < NUM_EMPLOYEES; i++)
    {
        grossPay = hours[i] * payrates;
        cout << "Gross pay for Employee " << (i + 1) << " : " << grossPay << endl;
    }

    return 0;
}