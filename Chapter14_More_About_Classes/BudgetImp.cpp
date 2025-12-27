#include "Budget.h"

// Define and initialize the static corporate budget (only one exists for the class)
double Budget::corpBudget = 0;

/*
    Static member function definition.
    Because it is static, it can be called without any specific object:
    Example: Budget::getCorpBudget()
*/
double Budget::getCorpBudget()
{
    return corpBudget;
}

/*
    Adds a main office budget amount directly to the corporate budget.
    Called before processing any division budgets.
*/
void Budget::addMainOfficeBudget(double d)
{
    corpBudget += d;
}