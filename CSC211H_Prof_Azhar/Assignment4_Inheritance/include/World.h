/*
World Class
*/

#ifndef WORLD_H
#define WORLD_H

#include "Robot.h"
#include "Dirt.h"
#include "Cat.h"
#include "Frog.h"

class World
{
private:
  Robot rosie;
  Dirt spots[MAX_SPOTS];
  int num_spots;
  Cat felix;
  Frog sponge;

public:
  World() { num_spots = 0; }
  void setRobot(int x, int y);
  void setCat(int x, int y);
  void setFrog(int , int );
  void setSpot(int x, int y);
  int findSpot(int x, int y) const;
  void robotRoam();
  void print() const;
};

#endif
