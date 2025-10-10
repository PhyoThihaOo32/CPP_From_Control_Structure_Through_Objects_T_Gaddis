/*
This program asks for the number of hours worked by six employees. It stores the values in an array.
*/

#include <iostream>

using namespace std;

int num_employees();

int main()
{

    // const int NUM_EMPLOYEES = 6;
    // int hours[NUM_EMPLOYEES];

    // let the user enter the number of employees
    const int NUM_EMPLOYEES = num_employees(); // size declarator
    int hours[NUM_EMPLOYEES];                  //

    // and then enter the hours of work for each employees
    for (int i = 0; i < NUM_EMPLOYEES; i++)
    {
        cout << "Enter the working hour for employee#" << (i + 1) << " : ";
        cin >> hours[i]; // subscript
    }

    // print out the hours
    for (int i = 0; i < NUM_EMPLOYEES; i++)
    {
        cout << hours[i] << " ";
    }

    return 0;
}

int num_employees()
{
    int num_employee;
    cout << "Enter the number of employees: ";
    cin >> num_employee;

    return num_employee;
}
