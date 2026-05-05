// implementation file for productionWorker

#ifndef PRODUCTIONWORKER_H
#define PRODUCTIONWORKER_H

#include "Employee.h"

class ProductionWorker : public Employee{
    private:
        int shift;
        double pay_rate;
    public:
        ProductionWorker():Employee(), shift(0), pay_rate(0){}
        ProductionWorker(int shift, double pay_rate) : Employee(){
            this->shift = shift;
            this->pay_rate = pay_rate;
        }

        ProductionWorker(string name, int number, int date, int shift, double pay) : Employee(name,number,date){
            this->shift = shift;
            pay_rate = pay;
        }

        // accessor function
        int getShift()const {return shift;}
        double getPayRate() const{return pay_rate;}

        // mutator function
        void setShift(int shift){
            this->shift = shift;
        }

        void setPayRate(double pay_rate){
            this->pay_rate = pay_rate;
        }

        void printInfo()const override;

};

#endif
