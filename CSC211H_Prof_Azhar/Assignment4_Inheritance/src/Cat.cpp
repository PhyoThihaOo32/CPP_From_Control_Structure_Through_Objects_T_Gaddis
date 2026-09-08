// implementation file for cat class

#include "Cat.h"

#include <iostream>

using namespace std;

void Cat::move(){
    direction d;
    d = static_cast<direction>(rand() % 4);
    move(d);
}

// overriding the creature move function - so cat can move 2 steps in any direction
void Cat::move(direction d){
    int x = getX();
    int y = getY();

    // find new x and y coordinate
    // find a new x and y coordinate
  switch( d ) {
  case north:
    y = (y + 2) % WORLD_SIZE;
    break;
  case south:
    y = (y - 2);
    if ( y < 0 ) {
      y = WORLD_SIZE;
    }
    break;
  case east:
    x = (x + 2) % WORLD_SIZE;
    break;
  case west:
    x = (x - 2) % WORLD_SIZE;
    if ( x < 0 ) {
      x = WORLD_SIZE;
    }
    break;
    }
    //set the location of the cat to those coordinates
    set(x, y);

}

void Cat::speak(){
    cout << "Meow!(Feed me)" << endl;
}