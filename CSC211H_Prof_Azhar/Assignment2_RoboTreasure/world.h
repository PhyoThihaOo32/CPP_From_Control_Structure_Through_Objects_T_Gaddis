#ifndef WORLD_H
#define WORLD_H

#include "point.h"

class World
{
private:
  static const int COINS = 3;
  point points[COINS]; // array of three points objects
public:
  void print() const;
  void set(int, int, int);
  point getPoint(int) const;
};

#endif

/*
=========================================================
World Class Documentation
=========================================================

Overview:
The World class represents the robot's grid world and
stores the locations of three hidden coins.

It maintains an internal array of Point objects,
where each Point represents a coin’s (x, y) coordinate.

---------------------------------------------------------
Header File: world.h
---------------------------------------------------------

Data Members (Private):

- static const int COINS = 3
  Defines the fixed number of coins in the world.

- Point points[COINS]
  An array of three Point objects used to store
  the coordinates of the hidden coins.

Public Members:

1. void set(int index, int x, int y)
   - Sets the location of the coin at the given index.
   - Stores (x, y) into the corresponding Point object.
   - Validates that index is within valid range [0, 2].

2. void print() const
   - Displays all stored coin locations.
   - Calls Point::print() for each coin.

3. Point getPoint(int index) const
   - Returns the Point object at the specified index.
   - Used to retrieve coin positions for comparison
     or robot coin-detection logic.

---------------------------------------------------------
Implementation File: world.cpp
---------------------------------------------------------

- print()
  Iterates through the array of coins and prints
  their coordinates.

- set()
  Validates index and assigns coordinates to the
  specified Point in the array.

- getPoint()
  Returns the Point object stored at the index.

=========================================================
*/