#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

using namespace std;

class Employee{
    private:
        string name;
        int number;
        int hire_date;
    public:
        Employee(){
            name = "";
            number = 0;
            hire_date = 0;
        }
        Employee(string name, int number, int hire_date){
            this->name = name;
            this->number = number;
            this -> hire_date = hire_date;
        }

        // accessor function
        string getName() const {return name;}
        int getNumber() const {return number;}
        int getHireDate() const {return hire_date;}

        // mutator function
        void setName(string name){
            this->name = name;
        }
        
        void setNumber(int number){
            this->number = number;
        }

        void setHireDate(int hire_date){
            this->hire_date = hire_date;
        }

        virtual void printInfo() const = 0;
        
        //  because the base class has virtual functions, it is good practice to add a virtual destructor
        virtual ~Employee(){}

};

#endif