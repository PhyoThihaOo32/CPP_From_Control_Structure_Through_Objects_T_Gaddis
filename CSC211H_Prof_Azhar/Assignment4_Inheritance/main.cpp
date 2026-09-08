#include <iostream>
#include "World.h"

using namespace std;


int main() {
  World myworld;
  int x, y;

  // initialize random number generator
  srand( time( NULL ));

  // place the robot and the spots in random locations in the world
  x = rand() % WORLD_SIZE;
  y = rand() % WORLD_SIZE;
  myworld.setRobot( x, y );
  x = rand() % WORLD_SIZE;
  y = rand() % WORLD_SIZE;
  myworld.setCat( x, y );
  myworld.print();

  // let the robot roam around until it finds and cleans all the spots
  cout << "\nRobot roaming..." << endl;
  myworld.robotRoam();
  cout << "\nOh My Goodness, what a clean world we live in :-)\n\n";


} // end of main()

