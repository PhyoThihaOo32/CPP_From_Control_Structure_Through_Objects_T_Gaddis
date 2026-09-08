// unit test for cat

#include "Cat.h"
#include <iostream>

using namespace std;

int main(){

    Cat pepito;
    direction dir = east;

    pepito.move();

    pepito.move(dir);

    pepito.speak();

    return 0;
}