#ifndef GASTANK_H
#define GASTANK_H

class GasTank
{
private:
    double amount;
    double capacity;

public:
    GasTank(double);
    void addGas(double);
    void useGas(double);
    bool isEmpty();
    bool isFull();
    double getGasLevel();
    double fillUp();
};

#endif