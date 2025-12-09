// Specification file for InventoryItem class

#ifndef INVENTORYITEM_H
#define INVENTORYITEM_H

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class InventoryItem
{
private:
    string description;
    double cost;
    int units;

public:
    // --- Constructors ---
    InventoryItem()
    {
        description = "";
        cost = 0.0;
        units = 0;
    }

    InventoryItem(string d)
    {
        description = d;
        cost = 0.0;
        units = 0;
    }

    InventoryItem(string d, double c, int u)
    {
        description = d;
        cost = c;
        units = u;
    }

    // --- Mutators ---
    void setDescription(string d)
    {
        description = d;
    }

    void setCost(double c)
    {
        cost = c;
    }

    void setUnits(int u)
    {
        units = u;
    }

    // --- Accessors ---
    string getDescription() const
    {
        return description;
    }

    double getCost() const
    {
        return cost;
    }

    int getUnits() const
    {
        return units;
    }

    // --- Display Function ---
    void showItems() const
    {

        cout << setw(20) << left << description
             << setw(10) << right << fixed << setprecision(2) << cost
             << setw(15) << units << endl;
    }
};

#endif