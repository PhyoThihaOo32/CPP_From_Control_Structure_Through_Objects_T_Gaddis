/*
This program demonstrates how to use an array of structures to store
and process multiple employees' pay information. It collects each
employee's name, hours worked, and pay rate, then calculates and
displays their gross pay with proper formatting.
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Structure to hold pay information for each employee
struct PayInfo
{
    string name;    // employee name
    int hours;      // hours worked
    double payRate; // hourly pay rate
};

int main()
{
    const int NUM_WORKERS = 3;    // total number of employees
    PayInfo workers[NUM_WORKERS]; // array of structures

    cout << fixed << setprecision(2); // format output for money

    // Input phase
    for (int i = 0; i < NUM_WORKERS; i++)
    {
        cout << "\nEnter name for employee " << (i + 1) << ": ";
        getline(cin, workers[i].name);

        cout << "Enter working hours for " << workers[i].name << ": ";
        cin >> workers[i].hours;

        cout << "Enter pay rate for " << workers[i].name << ": ";
        cin >> workers[i].payRate;

        cin.ignore(); // clear newline before next getline
    }

    // Output phase
    cout << "\n------------------------------------------" << endl;
    cout << "Employee Gross Pay Report\n";
    cout << "------------------------------------------" << endl;

    for (int i = 0; i < NUM_WORKERS; i++)
    {
        double gross = workers[i].hours * workers[i].payRate;

        cout << left << setw(20) << workers[i].name
             << "Hours: " << setw(4) << workers[i].hours
             << "  Pay Rate: $" << setw(8) << workers[i].payRate
             << "  Gross Pay: $" << setw(8) << gross << endl;
    }

    cout << "------------------------------------------" << endl;

    return 0;
}