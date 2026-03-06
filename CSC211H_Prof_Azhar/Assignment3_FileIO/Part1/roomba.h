#ifndef ROOMBA_H
#define ROOMBA_H

#include <fstream>

using namespace std;

class Roomba
{
private:
    int x;
    int y;
    int limitN; // For simplicity, dimensions will be limited to the range 10x10 to 50x50
    int limitE;
    int limitS;
    int limitW;

public:
    // default constructor - setting x and y co-ordinate to zero - limits at 10 * 10
    Roomba();

    // constructor - to initialize x and y coordinate - N/E/S/W LIMITs
    Roomba(int, int, int, int, int, int);

    // mutator functions
    void setLimits();
    void setPosition();

    // display functions
    void displayPosition() const; // display current position in(x,y) coordinate
    void displayLimits() const;   // display the N/E/S/W Limits (the 2D dimension)
    void showPrompt() const;      // display prompt to control roomba

    // beheavior functions
    void moveForward();  // move one unit north
    void moveBackward(); // move one unit south
    void moveRight();    // move one unit east
    void moveLeft();     // move one unit west
    void moveCenter();   // move center (0,0)

    void moveForwardToWall();  // move north bound and stop at boundary
    void moveBackwardToWall(); // move south bound and stop at boundary
    void moveRightToWall();    // move east bound and stop at boundary
    void moveLeftToWall();     // move west bound and stop at boundary

    void runRoomba();          // run roomba! - user can interact with roomba
    void runRoomba(fstream &); // improved version - that can saved the commands
};

#endif