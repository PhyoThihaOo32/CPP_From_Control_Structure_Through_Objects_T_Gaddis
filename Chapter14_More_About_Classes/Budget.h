#ifndef BUDGET_H
#define BUDGET_H
#include "Auxil.h"

/*
    The Budget class models budget management for company divisions.
    Each division has its own local budget (instance member),
    while all divisions share one corporate budget (static member).

    The class interacts with the Auxil class (for auxiliary office budgets)
    using a friend function, allowing controlled access to its static data.
*/

class Budget
{
private:
    static double corpBudget; // Shared by ALL objects (corporate total)
    double divisionBudget;    // Unique to each division (instance variable)

public:
    // Default constructor — initializes division budget to 0
    Budget()
    {
        divisionBudget = 0;
    }

    // Add a new budget amount to both division and corporate totals
    void addBudget(double d)
    {
        divisionBudget += d; // update this division’s total
        corpBudget += d;     // update corporate total (shared)
    }

    // Static function — adds budget directly to the corporate total (main office)
    static void addMainOfficeBudget(double d);

    // Return this division's budget (does not modify any data)
    double getDivisionBudget() const
    {
        return divisionBudget;
    }

    // Static function — returns the shared corporate total
    static double getCorpBudget();

    // Declare the Auxil::addAuxBudget function as a friend
    // This allows Auxil to access private static member corpBudget
    friend void Auxil::addAuxBudget(double, Budget &);
};

#endif
