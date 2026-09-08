#include "Frog.h"

void Frog::move(){
    int x, y;

    // frog jump randomly inside the world
    x = (rand() % (WORLD_SIZE  +1));
    y = (rand() % (WORLD_SIZE + 1));

    set(x, y);
}

void Frog::speak(){
    cout << "Frog!" << endl;
}

