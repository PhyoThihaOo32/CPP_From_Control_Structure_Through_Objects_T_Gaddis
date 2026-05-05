// implementation file for ShiftSupervisor Class

#include <iostream>
#include "ShiftSupervisor.h"

using namespace std;

ShiftSupervisor::ShiftSupervisor() : Employee(), annualSalary(0), prodBonus(0){}

ShiftSupervisor::ShiftSupervisor(string name, int number, int date, double salary, double bonus) : Employee(name, number, date), annualSalary(salary), prodBonus(bonus){}

ShiftSupervisor::ShiftSupervisor(double salary, double bonus): Employee(), annualSalary(salary), prodBonus(bonus){}

double ShiftSupervisor::getAnnualSalary()const {return annualSalary;}

double ShiftSupervisor::getProdBonus()const{return prodBonus;}


void ShiftSupervisor::setAnnualSalary(double annualSalary)
{
    this->annualSalary = annualSalary;
}

void ShiftSupervisor::setProdBonus(double prodBonus){
    this->prodBonus = prodBonus;
}

void ShiftSupervisor::printInfo()const{
    cout << "Name : " << getName() << endl
         << "Number : " << getNumber() << endl
         << "Hire Date: " << getHireDate() << endl
         << "Annual Salary: " << annualSalary << endl
         << "Production Bonus: " << prodBonus << endl;
}