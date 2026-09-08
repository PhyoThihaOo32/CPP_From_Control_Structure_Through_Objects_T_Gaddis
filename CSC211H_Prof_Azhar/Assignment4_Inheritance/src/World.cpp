// implementation file for World class

#include "World.h"
#include <iostream>


using namespace std;

void World::setRobot(int x, int y){
    rosie.set(x, y);
}

void World::setCat(int x, int y){
    felix.set(x, y);
}

void World::setFrog(int x, int y){
  sponge.set(x, y);
}

void World::setSpot(int x, int y){
    if(num_spots+1 < MAX_SPOTS){
        spots[num_spots++].set(x,y);
    }
}

int World::findSpot(int x, int y) const{
    bool found = false;
  int  index = 0;
  while (( ! found ) && ( index < num_spots )) {
    if (( x == spots[index].getX() ) && 
        ( y == spots[index].getY() )){
      found = true;
    }
    index++;
  }
  if ( found ) {
    return( index );
  }
  else {
    return( -1 );
  }
} // end of findSpot()


// make the robot roam around. if it finds a spot, it vacuums it up.
// it does this as long as it is "busy", i.e., as long as there are spots
// in the world that need to be cleaned.
void World::robotRoam() {
  int index;
  felix.move();
  setSpot( felix.getX(), felix.getY() );
  setSpot(sponge.getX(), sponge.getY());
  felix.speak();
  sponge.speak();
  while ( rosie.busy( num_spots ) ) {
    rosie.move();
    rosie.speak();
    rosie.print();
    if (( index = findSpot( rosie.getX(), rosie.getY() )) > 0 ) {
      rosie.vacuum();
      spots[index].disappear();
    }
    felix.move();
    setSpot( felix.getX(), felix.getY() );
    felix.speak();

    sponge.move();
    setSpot(sponge.getX(), sponge.getY());
    sponge.speak();
  }  
} // end of robotRoam()


// printing the world is printing the location of the objects in the
// world. we use their print methods to do this.
void World::print() const {
  cout << "\nRosie is at: ";
  rosie.print();
  cout << "\nThe spots are at: " << endl;
  for( int i=0; i<num_spots; i++ ) {
    spots[i].print();
  }
} // end of print()


