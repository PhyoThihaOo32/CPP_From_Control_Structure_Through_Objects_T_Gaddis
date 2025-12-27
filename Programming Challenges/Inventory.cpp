// Implementation file for Inventory class
#include "Inventory.h"

// Default constructor
Inventory::Inventory()
{
    itemNumber = 0;
    quantity = 0;
    cost = 0.0;
    totalCost = 0.0;
}

// Overloaded constructor
Inventory::Inventory(int itemNumber, int quantity, double cost)
{
    this->itemNumber = itemNumber;
    this->quantity = quantity;
    this->cost = cost;
    setTotalCost(); // calculate total cost immediately
}

// Mutator functions
void Inventory::setItemNumber(int n)
{
    itemNumber = n;
}

void Inventory::setQuantity(int q)
{
    quantity = q;
    setTotalCost(); // auto-update total cost when quantity changes
}

void Inventory::setCost(double c)
{
    cost = c;
    setTotalCost(); // auto-update total cost when cost changes
}

void Inventory::setTotalCost()
{
    totalCost = quantity * cost;
}

// Accessor functions
int Inventory::getItemNumber() const
{
    return itemNumber;
}

int Inventory::getQuantity() const
{
    return quantity;
}

double Inventory::getCost() const
{
    return cost;
}

double Inventory::getTotalCost() const
{
    return totalCost;
}