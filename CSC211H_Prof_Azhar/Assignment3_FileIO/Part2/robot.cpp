#include <iostream>
#include "robot.h"

using namespace std;

// This function initializes the robot’s current location to (0, 0) and its current orientation to east
void Robot::init()
{
    pt.set(0, 0);
    direction = EAST;
}

/*This function prints the robot’s current location and orientation in a pretty format, such as:
I am  at  (0,0) and I am  facing east.*/

void Robot::print() const
{
    cout << "I am at ( " << pt.getX() << ", " << pt.getY() << " ) and I am facing ";

    switch (direction)
    {
    case NORTH:
        cout << "north." << endl;
        break;
    case EAST:
        cout << "east." << endl;
        break;
    case SOUTH:
        cout << "south." << endl;
        break;
    case WEST:
        cout << "west." << endl;
        break;
    default:
        break;
    }
}

// return point member
point Robot::getPoint() const
{
    return pt;
}

// return orientation_type
orientation_type Robot::getOrientation() const
{
    return direction;
}

// map enum to string
std::string Robot::getDirection() const
{
    switch (direction)
    {
    case NORTH:
        return "north";
    case EAST:
        return "east";
    case SOUTH:
        return "south";
    case WEST:
        return "west";
    }
}

// This function sets the value of the robot’s orientation data member.
void Robot::setOrientation(orientation_type orientation)
{
    direction = orientation;
}

/*
This function simulates the robot moving forward one step in the direction that it is facing.
It checks to make sure that the robot is not at the edge of its world. It returns true if the robot moves forward successfully and false if the robot is at the edge of its world and cannot move forward.
*/
bool Robot::forward()
{
    bool atEdge = true;
    int x = pt.getX();
    int y = pt.getY();
    if (direction == NORTH)
    {
        y++;
        if (y > 9)
        {

            atEdge = false;
            y = 9;
            // turnCW();
        }
    }
    else if (direction == EAST)
    {
        x++;
        if (x > 9)
        {
            atEdge = false;
            x = 9;
        }
    }
    else if (direction == SOUTH)
    {
        y--;
        if (y < 0)
        {
            atEdge = false;
            y = 0;
        }
    }
    else if (direction == WEST)
    {
        x--;
        if (x < 0)
        {
            atEdge = false;
            x = 0;
        }
    }
    pt.set(x, y);
    return atEdge;
}

// This Function changes the robot’s orientation, simulating a turn in the clockwise direction.
void Robot::turnCW()
{
    int temp = static_cast<int>(direction); // cast orientation_type to int
    temp = (temp + 1) % 4;                  // wrapping (0 - 4)
    direction = static_cast<orientation_type>(temp);
}

// This Function changes the robot’s orientation, simulating a turn in the anti-clockwise direction.
void Robot::turnAntiCW()
{
    int temp = static_cast<int>(direction);
    temp = (temp + 3) % 4; // wrap between 3 2 1 0 - then 3 2 1 0
    direction = static_cast<orientation_type>(temp);
}

// This function returns true if the robot has reached the east edge of its world.
bool Robot::eastEnd()
{
    return (pt.getX() >= 9) ? true : false;
}

// This function returns true if the robot has reached the west edge of its world.
bool Robot::westEnd()
{
    return (pt.getX() <= 0) ? true : false;
}

// This function returns true if the robot has reached the north edge of its world.
bool Robot::northEnd()
{
    return (pt.getY() >= 9) ? true : false;
}

// This function returns true if the robot has reached the south edge of its world.
bool Robot::southEnd()
{
    return (pt.getY() <= 0) ? true : false;
}

/*
This function is called when the robot has been moving east and has reached the east edge of its world, in which case it should turn clockwise, go forward one step south and turn clockwise again (where it will be heading west for its next move).
*/
void Robot::zig()
{

    turnCW();
    forward();
    turnCW();
}

/*
This function is called when the robot has been moving west and has reached  the west edge of its world, in which  case it should turn anti-clockwise, go forward one step south and turn anti-clockwise again (where it will be heading east for its next move).*
*/
void Robot::zag()
{

    turnAntiCW();
    forward();
    turnAntiCW();
}
