/*
    This program demonstrates the use of static member variables,
    friend functions, and interaction between multiple classes.

    It creates several Budget objects (divisions) and corresponding
    Auxil objects (auxiliary offices), collects user input for budgets,
    and displays both individual and corporate totals.
*/

#include <iostream>
#include <iomanip>
#include "Budget.h"
#include "Auxil.h"

using namespace std;

int main()
{
    const int NUM_DIVISIONS = 4;    // number of divisions
    double budgetInput;             // user input
    Budget division[NUM_DIVISIONS]; // array of Budget objects
    Auxil auxOffice[NUM_DIVISIONS]; // array of Auxil objects (one per division)

    cout << fixed << setprecision(2);

    // ---- Main Office Budget ----
    cout << "Enter the budget request for the Main Office: ";
    cin >> budgetInput;

    while (budgetInput < 0)
    {
        cout << "Budget cannot be negative. Enter again: ";
        cin >> budgetInput;
    }

    Budget::addMainOfficeBudget(budgetInput);

    // ---- Division & Auxiliary Input ----
    cout << "\n=== Company Budget Entry ===\n";
    for (int i = 0; i < NUM_DIVISIONS; i++)
    {
        // Division Budget
        cout << "Enter the budget request for Division " << (i + 1) << ": ";
        cin >> budgetInput;
        while (budgetInput < 0)
        {
            cout << "Budget cannot be negative. Enter again: ";
            cin >> budgetInput;
        }
        division[i].addBudget(budgetInput);

        // Auxiliary Office Budget
        cout << "Enter the auxiliary office budget for Division " << (i + 1) << ": ";
        cin >> budgetInput;
        while (budgetInput < 0)
        {
            cout << "Budget cannot be negative. Enter again: ";
            cin >> budgetInput;
        }
        auxOffice[i].addAuxBudget(budgetInput, division[i]);
    }

    // ---- Output Phase ----
    cout << "\n=== Budget Summary ===\n";
    for (int i = 0; i < NUM_DIVISIONS; i++)
    {
        cout << "Division " << (i + 1)
             << " Budget: $" << setw(10) << division[i].getDivisionBudget() << endl;

        cout << "Auxiliary Office " << (i + 1)
             << " Budget: $" << setw(10) << auxOffice[i].getAuxBudget() << endl;
    }

    cout << "\nCorporate Budget Total (Including Main Office): $"
         << Budget::getCorpBudget() << endl;

    cout << "\nProgram complete.\n";

    return 0;
}