/*
This program calculates either:
1. The Present Value (P) of a future amount using:
       P = F / (1 + r)^n
   where:
       P = present value
       F = future value
       r = annual interest rate (decimal)
       n = number of years

2. The Future Value (F) of a present amount using:
       F = P * (1 + i)^t
   where:
       F = future value
       P = present value
       i = monthly interest rate
       t = number of months
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Function prototypes
void showMenu();
double presentValue(double, double, int);
double futureValue(double, double, int);

int main()
{
    double f_value, p_value, annual_iRate, monthly_iRate;
    int years, months, user_choice;

    cout << fixed << setprecision(2);

    do
    {
        showMenu();
        cout << "Enter your choice: ";
        cin >> user_choice;
        cout << endl;

        switch (user_choice)
        {
        case 1:
            // --- Present Value Calculation ---
            cout << "Enter the amount you want in your account (Future Value): $";
            cin >> f_value;
            while (f_value <= 0)
            {
                cout << "Invalid input. Amount must be positive. Try again: $";
                cin >> f_value;
            }

            cout << "Enter the annual interest rate (in %): ";
            cin >> annual_iRate;
            while (annual_iRate <= 0)
            {
                cout << "Invalid input. Interest rate must be positive. Try again: ";
                cin >> annual_iRate;
            }

            cout << "Enter the number of years: ";
            cin >> years;
            while (years <= 0)
            {
                cout << "Invalid input. Years must be positive. Try again: ";
                cin >> years;
            }

            // Convert percentage to decimal
            annual_iRate /= 100.0;

            // Calculate present value
            p_value = presentValue(f_value, annual_iRate, years);

            cout << "\n=====================================\n";
            cout << "Future Value: $" << f_value << endl;
            cout << "Annual Interest Rate: " << (annual_iRate * 100) << "%" << endl;
            cout << "Years: " << years << endl;
            cout << "-------------------------------------\n";
            cout << "You need to deposit: $" << p_value << " today.\n";
            cout << "=====================================\n\n";
            break;

        case 2:
            // --- Future Value Calculation ---
            cout << "Enter the amount you will deposit today (Present Value): $";
            cin >> p_value;
            while (p_value <= 0)
            {
                cout << "Invalid input. Amount must be positive. Try again: $";
                cin >> p_value;
            }

            cout << "Enter the monthly interest rate (in %): ";
            cin >> monthly_iRate;
            while (monthly_iRate <= 0)
            {
                cout << "Invalid input. Interest rate must be positive. Try again: ";
                cin >> monthly_iRate;
            }

            cout << "Enter the number of months: ";
            cin >> months;
            while (months <= 0)
            {
                cout << "Invalid input. Months must be positive. Try again: ";
                cin >> months;
            }

            // Convert percentage to decimal
            monthly_iRate /= 100.0;

            // Calculate future value
            f_value = futureValue(p_value, monthly_iRate, months);

            cout << "\n=====================================\n";
            cout << "Present Value: $" << p_value << endl;
            cout << "Monthly Interest Rate: " << (monthly_iRate * 100) << "%" << endl;
            cout << "Months: " << months << endl;
            cout << "-------------------------------------\n";
            cout << "Future Value: $" << f_value << endl;
            cout << "=====================================\n\n";
            break;

        case 3:
            cout << "Thank you for using the Financial Calculator. Goodbye!\n";
            break;

        default:
            cout << "Invalid choice. Please select 1, 2, or 3.\n\n";
            break;
        }

    } while (user_choice != 3);

    return 0;
}

// --- Function Definitions ---

// Calculates present value
double presentValue(double future_value, double annual_interest_rate, int years)
{
    return future_value / pow((1 + annual_interest_rate), years);
}

// Calculates future value
double futureValue(double present_value, double monthly_iRate, int months)
{
    return present_value * pow((1 + monthly_iRate), months);
}

// Displays menu
void showMenu()
{
    cout << "==============================\n";
    cout << "   FINANCIAL CALCULATOR MENU\n";
    cout << "==============================\n";
    cout << "1. Calculate Present Value\n";
    cout << "2. Calculate Future Value\n";
    cout << "3. Exit\n";
    cout << "==============================\n";
}