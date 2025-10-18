/*
By using same subscript, you can build relationships between data stored in two or more arrays.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

    // setting up the hours and pay_rate arrays for 5 employees
    const int EMPLOYEE = 5;
    float hours[EMPLOYEE];
    double pay_rate[EMPLOYEE];
    double weekly_salary[EMPLOYEE];

    // ask the user to enter the hours and pay_rate for each employees
    for (int count = 0; count < EMPLOYEE; count++)
    {
        cout << "For employee number " << (count + 1) << endl;
        cout << "Enter the weekly working hour: ";
        cin >> hours[count];
        cout << "Enter the pay rate: ";
        cin >> pay_rate[count];

        // calculate the weekly salary and store it in an array
        weekly_salary[count] = hours[count] * pay_rate[count];

        // display the working hour, pay rate and weekly salary for each employees
        cout << "Employee : " << count + 1 << endl;
        cout << "Weekly working hours: " << hours[count] << endl;
        cout << "Hourly pay rate: " << pay_rate[count] << endl;
        cout << "Weekly Salary: " << weekly_salary[count] << endl;
    }

    return 0;
}