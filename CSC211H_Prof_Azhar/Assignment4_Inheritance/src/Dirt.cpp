// implementation file of the Dirt Class

#include "Dirt.h"
#include <iostream>

using namespace std;

Dirt::Dirt() {
    gone = false;
}

void Dirt::disappear(){
    cout << "poof!" << endl;
    gone = true;
}