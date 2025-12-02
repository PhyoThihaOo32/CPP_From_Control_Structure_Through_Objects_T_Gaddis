/*
This program demonstrates the use of structures.
[A structure is a user-defined data type that groups related variables of different types under one name.]
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct PayRoll
{
    // declare the members of the struct
    int empNumbers; // employee numbers
    string name;    // employee's name [string object]
    double hours;
    double payRate;
    double grossPay;
};

int main()
{

    PayRoll employee; // employee is a PayRoll structure

    // get the employee number
    cout << "Enter the employee number: ";
    cin >> employee.empNumbers; // the dot operator connect the name of the member variable with the name of the structure variable it belongs to

    // get the employee's name
    cout << "Enter the employee name: ";
    cin.ignore(); // to skip the '\n' in the buffer
    getline(cin, employee.name);

    // get the hours works by the employee
    cout << "How many hours did the employee work? ";
    cin >> employee.hours;

    // get the employee's hourly pay rate
    cout << "Enter the employee hourly payrate: ";
    cin >> employee.payRate;

    // calculate the employee's gross pay
    employee.grossPay = employee.hours * employee.payRate;

    // dispaly the employee date
    cout << fixed << setprecision(2);
    cout << "\nEmployee Number: " << employee.empNumbers << endl;
    cout << "Employee Name: " << employee.name << endl;
    cout << "Hours Worked: " << employee.hours << endl;
    cout << "Hourly Pay Rate: $" << employee.payRate << endl;
    cout << "Gross Pay: $" << employee.grossPay << endl;

    return 0;
}