// specifiction file for inventory class

#ifndef INVENTORY_H
#define INVENTORY_H

class Inventory
{
private:
    int itemNumber;
    int quantity;
    double cost;
    double totalCost;

public:
    Inventory();
    Inventory(int, int, double);

    // mutator functions
    void setItemNumber(int);
    void setQuantity(int);
    void setCost(double);

    void setTotalCost();

    // accessor functions
    int getItemNumber() const;
    int getQuantity() const;
    double getCost() const;

    double getTotalCost() const;
};

#endif