// unit test for robot class
// don't forgot to compile the file that contains the implementation of Point


#include "Robot.h"
#include <iostream>

using namespace std;

int main(){

    Robot ro;
    int spots;

    ro.vacuum();

    cout << "How many spots?" << endl;
    cin >> spots;

    // if ro is busy she will sing
    if(ro.busy(spots)){
        ro.speak();
    }
    else{
        cout << "Not Busy at all." << endl;
    }
    return 0;
}

