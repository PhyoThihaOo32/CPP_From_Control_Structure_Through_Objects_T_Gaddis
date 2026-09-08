#include "Frog.h"
#include <iostream>

using namespace std;

int main(){

    Frog frog;

    for(int i = 0; i < 10; i++){
        frog.move();
        cout << "(" << frog.getX() << "," << frog.getY() << ")" << endl;
        frog.speak();
    }


    return 0;
}