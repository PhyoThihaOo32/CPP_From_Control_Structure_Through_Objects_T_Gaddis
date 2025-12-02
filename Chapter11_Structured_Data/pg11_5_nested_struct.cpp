/*
This program demonstrates nested structures in C++.
It stores and displays an employee’s personal information,
including name, employee ID, date of birth, and residence details.
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Structure for storing date information
struct Date
{
    int day;
    int month;
    int year;
};

// Structure for storing address/place information
struct Place
{
    string address;
    string city;
    string state;
    string zip;
};

// Structure that includes other structures (nested)
struct EmployeeInfo
{
    string name;
    int employeeNum;
    Date birthDate;
    Place residence;
};

int main()
{
    EmployeeInfo manager;
    EmployeeInfo employee = {"Mary", 92, {12, 9, 1992}, {"9052 Broadway", "Elmhurst", "NY", "11373"}};

    // Get manager's basic info
    cout << "Enter manager name: ";
    getline(cin, manager.name);

    cout << "Enter manager ID: ";
    cin >> manager.employeeNum;

    // Get birth date
    cout << "Enter manager birth info (mm dd yyyy): ";
    cin >> manager.birthDate.month >> manager.birthDate.day >> manager.birthDate.year;

    cin.ignore(); // clear buffer before using getline

    // Get residence info
    cout << "\nEnter residence details:\n";
    cout << "Address: ";
    getline(cin, manager.residence.address);
    cout << "City: ";
    getline(cin, manager.residence.city);
    cout << "State: ";
    getline(cin, manager.residence.state);
    cout << "ZIP Code: ";
    getline(cin, manager.residence.zip);

    // Display manager's full information
    cout << "\n----------------------------------------\n";
    cout << "Manager Information\n";
    cout << "----------------------------------------\n";
    cout << "Name: " << manager.name << endl;
    cout << "Employee ID: " << manager.employeeNum << endl;
    cout << "Date of Birth: "
         << setw(2) << setfill('0') << manager.birthDate.month << "/"
         << setw(2) << manager.birthDate.day << "/"
         << manager.birthDate.year << endl;
    cout << "Address: " << manager.residence.address << endl;
    cout << "City: " << manager.residence.city << endl;
    cout << "State: " << manager.residence.state << endl;
    cout << "ZIP Code: " << manager.residence.zip << endl;
    cout << "----------------------------------------\n";

    // Display employee’s full information
    cout << "\n----------------------------------------\n";
    cout << "Employee Information\n";
    cout << "----------------------------------------\n";
    cout << "Name: " << employee.name << endl;
    cout << "Employee ID: " << employee.employeeNum << endl;
    cout << "Date of Birth: "
         << setw(2) << setfill('0') << employee.birthDate.month << "/"
         << setw(2) << employee.birthDate.day << "/"
         << employee.birthDate.year << endl;
    cout << "Address: " << employee.residence.address << endl;
    cout << "City: " << employee.residence.city << endl;
    cout << "State: " << employee.residence.state << endl;
    cout << "ZIP Code: " << employee.residence.zip << endl;
    cout << "----------------------------------------\n";

    return 0;
}