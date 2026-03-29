#include <iostream>
#include <string>
using namespace std;

// structure definitions
struct date
{
    int day, month, year;
};

struct emp_info
{
    date birthday;
    date hire_date;
    string id_number;
    double salary;
};

int main()
{
    // given variables
    date some_day;
    emp_info some_employee;
    emp_info all_employees[100];

    // -----------------------------------------
    // 1) assign June 14, 1995 to some_day
    // -----------------------------------------
    some_day.day = 14;
    some_day.month = 6; // June
    some_day.year = 1995;

    // -----------------------------------------
    // sample data for some_employee
    // -----------------------------------------
    some_employee.hire_date.day = 12;
    some_employee.hire_date.month = 1;
    some_employee.hire_date.year = 2001;
    some_employee.salary = 50000;

    // -----------------------------------------
    // 2) print hire_date and salary
    // -----------------------------------------
    cout << "Hire Date: "
         << some_employee.hire_date.day << "/"
         << some_employee.hire_date.month << "/"
         << some_employee.hire_date.year << endl;

    cout << "Salary: " << some_employee.salary << endl;

    // -----------------------------------------
    // initialize all_employees (example data)
    // -----------------------------------------
    for (int i = 0; i < 100; i++)
    {
        all_employees[i].id_number = "EMP" + to_string(i + 1);

        all_employees[i].birthday.day = (i % 28) + 1;
        all_employees[i].birthday.month = (i % 12) + 1;
        all_employees[i].birthday.year = 1990 + (i % 10);
    }

    // -----------------------------------------
    // 3) print ids and birthdays of ALL employees
    // -----------------------------------------
    cout << "\nAll Employees:\n";

    for (int i = 0; i < 100; i++)
    {
        cout << "ID: " << all_employees[i].id_number << endl;

        cout << "Birthday: "
             << all_employees[i].birthday.day << "/"
             << all_employees[i].birthday.month << "/"
             << all_employees[i].birthday.year << endl;

        cout << "-----------------------------" << endl;
    }

    return 0;
}