#ifndef AUXIL_H
#define AUXIL_H

class Budget; // Forward declaration of Budget class

/*
    The Auxil (Auxiliary) class models the budget for smaller, auxiliary offices
    that support each division. Each Auxil object has its own budget.
    The Auxil class can update the shared corporate total through
    its friend relationship with the Budget class.
*/

class Auxil
{
private:
    double auxBudget; // local auxiliary office budget

public:
    Auxil()
    {
        auxBudget = 0.0;
    }

    // Accessor
    double getAuxBudget() const
    {
        return auxBudget;
    }

    // Add to auxiliary office and corporate budgets
    void addAuxBudget(double, Budget &);
};

#endif