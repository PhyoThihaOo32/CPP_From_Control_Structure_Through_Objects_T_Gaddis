#ifndef ROBOT_H
#define ROBOT_H

#include "point.h"
#include <string>

enum orientation_type
{
   NORTH = 0,
   EAST,
   SOUTH,
   WEST

};

class Robot
{
private:
   Point point;
   orientation_type direction;

public:
   void init();
   void print() const;
   void setOrientation(orientation_type);

   Point getPoint() const;
   orientation_type getOrientation() const;

   // get direction in string
   std::string getDirection() const;

   bool forward();

   void turnCW();
   void turnAntiCW();

   bool eastEnd();
   bool westEnd();
   bool northEnd();
   bool southEnd();

   void zig();
   void zag();
};

#endif

/*
=========================================================
Robot Class Documentation
=========================================================

Overview:
The Robot class simulates a robot moving inside a 10x10
grid world (coordinates 0–9). The robot maintains its
current position using a Point object and its current
orientation using an enum (NORTH, EAST, SOUTH, WEST).

---------------------------------------------------------
Header File: robot.h
---------------------------------------------------------

Enum:
orientation_type
- Represents the robot's direction.
- Values:
  NORTH = 0
  EAST  = 1
  SOUTH = 2
  WEST  = 3

Data Members (Private):
- Point point
  Stores the robot’s current (x, y) location.

- orientation_type direction
  Stores the robot’s current facing direction.

Public Members:

1. void init()
   - Initializes robot at (0,0).
   - Sets initial direction to EAST.

2. void print() const
   - Prints robot’s current position and direction.

3. void setOrientation(orientation_type)
   - Sets the robot’s direction manually.

4. Point getPoint() const
   - Returns the robot’s current position.

5. bool forward()
   - Moves the robot one step forward in the current direction.
   - Prevents moving outside the grid (0–9).
   - Returns true if move successful.
   - Returns false if robot hits boundary.

6. void turnCW()
   - Rotates robot clockwise.
   - Uses modular arithmetic to wrap direction (0–3).

7. void turnAntiCW()
   - Rotates robot counter-clockwise.
   - Wraps direction using modular arithmetic.

8. bool eastEnd(), westEnd(), northEnd(), southEnd()
   - Check whether robot is at corresponding grid boundary.

9. void zig()
   - Called when robot hits EAST edge.
   - Turns clockwise, moves one step SOUTH,
     then turns clockwise again (faces WEST).

10. void zag()
    - Called when robot hits WEST edge.
    - Turns anti-clockwise, moves one step SOUTH,
      then turns anti-clockwise again (faces EAST).

---------------------------------------------------------
Implementation Details:
---------------------------------------------------------

Movement Logic:
- NORTH: increase y
- EAST:  increase x
- SOUTH: decrease y
- WEST:  decrease x

Boundary Conditions:
- Grid limits are [0, 9] for both x and y.
- Robot position is clamped at edges.
- forward() prevents out-of-bounds movement.

Direction Wrapping:
- Clockwise:     (dir + 1) % 4
- Counterclockwise: (dir + 3) % 4

=========================================================
*/