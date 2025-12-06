// Sale.h
// Specification file for the Sale class
#ifndef SALE_H
#define SALE_H

#include <iostream>
#include <iomanip>
using namespace std;

class Sale
{
private:
    double itemCost;
    double taxRate;

public:
    // Constructor with default values
    Sale(double cost = 0.0, double rate = 0.0)
    {
        setCost(cost);
        setRate(rate);
    }

    // Mutators (Setters)
    void setCost(double cost)
    {
        if (cost >= 0)
            itemCost = cost;
        else
        {
            cout << "Invalid cost. Setting to 0.\n";
            itemCost = 0;
        }
    }

    void setRate(double rate)
    {
        if (rate >= 0)
            taxRate = rate;
        else
        {
            cout << "Invalid tax rate. Setting to 0.\n";
            taxRate = 0;
        }
    }

    // Accessors (Getters)
    double getCost() const { return itemCost; }
    double getRate() const { return taxRate; }

    // Computed values
    double getTaxAmount() const { return itemCost * taxRate; }
    double getTotal() const { return itemCost + getTaxAmount(); }

    // Display function for convenience
    void showSale() const
    {
        cout << fixed << setprecision(2);
        cout << "\nSale Summary\n";
        cout << "--------------------------\n";
        cout << "Item cost : $" << setw(8) << itemCost << endl;
        cout << "Tax rate  : " << setw(8) << (taxRate * 100) << "%\n";
        cout << "Tax amount: $" << setw(8) << getTaxAmount() << endl;
        cout << "Total     : $" << setw(8) << getTotal() << endl;
        cout << "--------------------------\n";
    }
};

#endif