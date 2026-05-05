// specification file for ShiftSupervisor class

#ifndef SHIFTSUPERVISOR_H
#define SHIFTSUPERVISOR_H

#include "Employee.h"

class ShiftSupervisor: public Employee{
    private:
        double annualSalary;
        double prodBonus;
    public:
        ShiftSupervisor();

        ShiftSupervisor(string, int ,int, double, double);

        ShiftSupervisor(double, double);

        // accessor function
        double getAnnualSalary() const;
        double getProdBonus() const;

        // mutator function
        void setAnnualSalary(double);
        void setProdBonus(double);

        void printInfo()const override;

};


#endif

