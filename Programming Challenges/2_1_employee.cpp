// this is the demo client code for employee class

#include "Employee.h"
#include <iostream>

using namespace std;

int main()
{

    Employee emp1("Susan Meyers", 47899, "Accounting", "Vice President"),
        emp2("Mark Jones", 39119, "IT", "Programmer"),
        emp3("Joy Rogers", 81774, "Manufacturing", "Engineer");

    emp1.displayInfo();
    emp2.displayInfo();
    emp3.displayInfo();

    return 0;
}