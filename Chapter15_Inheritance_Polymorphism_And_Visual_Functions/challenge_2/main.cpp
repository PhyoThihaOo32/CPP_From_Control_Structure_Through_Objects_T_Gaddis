#include <iostream>
#include "MilTime.h"

using namespace std;

int main(){

    int milhour, milsec;

    cout << "Enter military hour: " << endl;
    cin >> milhour;

    cout << "Enter military second: " << endl;
    cin >> milsec;

    Time* mt = new MilTime(milhour, milsec);

    cout << "Standard Time Format" << endl;
    mt->Time::showTime();
    cout << "Military Time Format" << endl;
    mt->showTime();

    delete mt;

    return 0;
}