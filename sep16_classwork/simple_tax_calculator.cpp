/*
This program calculate tax as 10% of annual salary and if salary < 20000 or the person is exempt from paying tax.
Otherwise, they pay taxes.
Finally, the program will print the user's income after tax.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

    // const for 10% tax
    const float TAX_RATE = 0.1;

    float annual_salary,
        tax_amount,
        net_salary,   // Net income is the amount of money left after all deductions
        gross_salary; // Gross income is the total amount of money earned before any deductions

    // ask user for annual salary or total income
    cout << "What is your annual income or salary? ";
    cin >> annual_salary;

    // calculate net_salary
    tax_amount = annual_salary * TAX_RATE;
    net_salary = annual_salary - tax_amount;

    // set format for numeric data
    cout << setprecision(3) << showpoint << fixed;

    // check if the person free of tax
    if (annual_salary < 20000)
    {
        gross_salary = annual_salary;
        cout << "You total income is " << gross_salary << " $." << endl;
    }
    else
    {
        cout << "Your tax amout will be:\t\t" << tax_amount << " $" << endl;
        cout << "Your net salary will be:\t" << net_salary << " $" << endl;
    }

    return 0;
}