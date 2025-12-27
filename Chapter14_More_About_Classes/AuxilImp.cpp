#include "Auxil.h"
#include "Budget.h"

/*
    Adds an amount to this auxiliary office's local budget,
    and also contributes to the shared corporate budget.
    Because addAuxBudget is a friend of Budget,
    it can access Budget::corpBudget directly.
*/
void Auxil::addAuxBudget(double d, Budget &div)
{
    auxBudget += d;
    div.corpBudget += d; // Accesses Budget’s private static member (allowed via friendship)
}