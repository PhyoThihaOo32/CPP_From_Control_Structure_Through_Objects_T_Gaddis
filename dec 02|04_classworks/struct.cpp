#include <iostream>
#include <string>

using namespace std;

struct Date
{
    string month;
    int day;
    int year;
};

struct Employee
{
    string first_name,
        last_name;
    int employee_id;
    float hour_work;
    float hourly_pay;
};

void printEmployeeInfo(const Employee &);
Employee getEmployeeData();

int main()
{
    Employee emp1 = getEmployeeData();
    Employee emp2 = getEmployeeData();
    Employee emp[100];
    Employee *eptr = nullptr;
    eptr = &emp1;

    cout << (*eptr).first_name << " " << (*eptr).last_name << endl; // . operator higher precedence than * operator
    cout << eptr->first_name << " " << eptr->last_name << endl;     // arrow operator

    printEmployeeInfo(emp1);
    printEmployeeInfo(emp2);

    return 0;
}

void printEmployeeInfo(const Employee &emp)
{
    cout << emp.first_name << " " << emp.last_name << endl;
    cout << "Employee ID: " << emp.employee_id << endl;
    cout << "Working hour: " << emp.hour_work << endl;
    cout << "Hourly pay rate: " << emp.hourly_pay << endl;
}

Employee getEmployeeData()
{

    Employee emp;

    cout << "Enter first name: ";
    cin >> emp.first_name;

    cout << "Enter last name: ";
    cin >> emp.last_name;

    cout << "What is the employee id: ";
    cin >> emp.employee_id;

    cout << "What is your working hour: ";
    cin >> emp.hour_work;

    cout << "What is your hourly pay rate: ";
    cin >> emp.hourly_pay;

    return emp;
}