#include "ProductionWorker.h"
#include <iostream>

using namespace std;

void ProductionWorker::printInfo() const{
        cout << "Name : " << getName() << endl
             << "Number : " << getNumber() << endl
             << "Hire Date: " << getHireDate() << endl
             << "Shift : ";
        if(shift == 1) cout << "Day shift" << endl;
        else if(shift == 2) cout << "Night shift" << endl;
        else cout << "Unknown" << endl;
    cout << "Pay Rate : " << getPayRate() << endl;     
}