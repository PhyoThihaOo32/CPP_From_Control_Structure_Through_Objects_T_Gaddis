#ifndef ROOMBA_H
#define ROOMBA_H

#include <iostream>

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

    Roomba(int, int, int, int, int, int);

    // mutator functions
    void setLimits();
    void setPosition();

    // display function
    void displayPosition() const;
    void displayLimits() const;
    void showPrompt() const;

    // beheavior functions
    void moveForward();
    void moveBackward();
    void moveRight();
    void moveLeft();
    void moveCenter();

    void moveForwardToWall();
    void moveBackwardToWall();
    void moveRightToWall();
    void moveLeftToWall();

    // run roomba!
    void runRoomba();
};

#endif