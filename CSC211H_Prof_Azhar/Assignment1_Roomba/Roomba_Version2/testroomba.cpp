#include <iostream>
#include "roomba.h"
#include <cstdlib>

using namespace std;

int main()
{

    srand(time(0));
    Roomba r1;

    cout << "Robot 1" << endl;
    r1.displayPosition();

    cout << "Robot 2" << endl;
    Roomba r2;
    r2.displayPosition();

    cout << "Robot 3" << endl;
    Roomba r3;
    r3.displayPosition();

    return 0;
}