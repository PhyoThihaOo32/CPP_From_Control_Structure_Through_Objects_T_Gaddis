/*
This program demonstrate using push_back function with empty vector.
*/

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{

    // define empty vector for hours, pay_rate and salary
    vector<int> hours;
    vector<double> payrate;
    vector<double> salary;

    int num_employees,
        index;

    // get number of employees from the user
    cout << "Enter the number of employees: ";
    cin >> num_employees;

    for (index = 0; index < num_employees; index++)
    {
        int temp_hours; // to hold the hour and pay rate for each employees
        double temp_payrate;

        cout << "Getting information for Employee " << (index + 1) << endl;
        cout << "Enter the working hour: ";
        cin >> temp_hours;
        hours.push_back(temp_hours); // add the hour to hours vector of int

        cout << "Enter the pay rate: ";
        cin >> temp_payrate;
        payrate.push_back(temp_payrate); // add the pay_rate to payrate vector of double

        // calculate the salary for each employee
        double temp_salary; // to hold the salary then later push back into salary vector
        temp_salary = hours[index] * payrate[index];
        salary.push_back(temp_salary);
    }

    // set numeric output format
    cout << setprecision(2) << showpoint << fixed;

    // display the salary for each employees
    int employee_counter = 1;
    for (double salary : salary)
    {
        cout << "Employee " << employee_counter << " salary: " << salary << endl;
        employee_counter++;
    }

    return 0;
}