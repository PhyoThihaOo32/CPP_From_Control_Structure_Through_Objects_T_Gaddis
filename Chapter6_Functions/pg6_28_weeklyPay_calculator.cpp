/*
This program demonstrate overloaded functions to calculate the gross weekly pay of hourly paid or salaried employees.
*/

#include <iostream>
#include <iomanip>

using namespace std;

// function prototype
void displayMenu();
void getUserChoice(char &);
double calWeeklyPay(int hours, double pay_rate);
double calWeeklyPay(double annual_salary);

int main()
{
    char choice;
    int hours;
    double pay_rate, annual_salary;

    // set numeric data output
    cout << setprecision(2) << fixed << showpoint;

    // display option menu
    displayMenu();
    getUserChoice(choice);

    // calculation based on user choice
    switch (choice)
    {
    case '1':
        cout << "Enter your weekly working hour: ";
        cin >> hours;
        cout << "Enter your pay rate: ";
        cin >> pay_rate;
        cout << "Weekly Pay: " << calWeeklyPay(hours, pay_rate) << endl;
        break;
    case '2':
        cout << "Enter your annual salary: ";
        cin >> annual_salary;
        cout << "Weekly Pay: " << calWeeklyPay(annual_salary) << endl;
        break;
    }

    return 0;
}

// this function display option menu
void displayMenu()
{

    cout << "This program will calculate your weekly salary based on\n"
         << "Option 1: working hours and pay rate\n"
         << "Option 2: annual salary\n"
         << "Enter 1 for option1 Enter 2 for option2." << endl;
}

// this function get the user option and validate the input
void getUserChoice(char &user_choice)
{
    cin >> user_choice;
    while (!(user_choice == '1' || user_choice == '2'))
    {
        cout << "Enter 1 for option1 Enter 2 for option2." << endl;
        cin >> user_choice;
    }
}

// this function calculate weekly pay based on hours and pay rate
double calWeeklyPay(int hours, double pay_rate)
{
    return hours * pay_rate;
}

// this function calculate weekly pay based on annual salary
double calWeeklyPay(double annual_salary)
{
    return annual_salary / 52;
}
