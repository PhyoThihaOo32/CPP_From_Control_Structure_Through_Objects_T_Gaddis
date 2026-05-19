/*
Consider the structure definitions and variables declarations below:

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

date some_day;
emp_info some_employee;
emp_info all_employees[100];

Use the declarations above to do the following:

1) assign June 14, 1995 to some_day.
2) print the hire_date and the salary of some_employee.
3) print the ids and the birthdays of ALL the employees stored in the
array all_employees.
*/

#include <iostream>
#include <string>

using namespace std;

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
    date some_day;
    emp_info some_employee;
    emp_info all_employees[100];

    // 1) assign June 14, 1995 to some_day.
    some_day.day = 14;
    some_day.month = 6;
    some_day.year = 1995;

    cout << "Some Day: "
         << some_day.month << "/"
         << some_day.day << "/"
         << some_day.year << endl;

    // 2) print the hire_date and the salary of some_employee.
    some_employee.hire_date.day = 12;
    some_employee.hire_date.month = 12;
    some_employee.hire_date.year = 2012;
    some_employee.salary = 75000.00;

    cout << "Hire Date: "
         << some_employee.hire_date.month << "/"
         << some_employee.hire_date.day << "/"
         << some_employee.hire_date.year << endl;

    cout << "Salary: " << some_employee.salary << endl;

    // 3) print the ids and the birthdays of ALL the employees stored in the
    // array all_employees.

    // Sample initialization so the output is not garbage values.
    for (int i = 0; i < 100; i++)
    {
        all_employees[i].id_number = "0";
        all_employees[i].birthday.day = 0;
        all_employees[i].birthday.month = 0;
        all_employees[i].birthday.year = 0;
    }

    for (int i = 0; i < 100; i++)
    {
        cout << "Employee ID: " << all_employees[i].id_number << endl;

        cout << "Birthday: "
             << all_employees[i].birthday.month << "/"
             << all_employees[i].birthday.day << "/"
             << all_employees[i].birthday.year << endl;

        cout << "------------------------------" << endl;
    }

    return 0;
}