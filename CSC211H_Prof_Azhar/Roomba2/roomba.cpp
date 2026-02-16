#include <iostream>
#include "roomba.h"

using namespace std;

Roomba::Roomba() : x(0), y(0), limitN(10), limitE(10), limitS(-10), limitW(-10) {}

// construct will initialize x and y values(x,y) - set the values are within the limits - if not set to default 0
// initialize the limits - within range - if out of range limit are set to default
Roomba::Roomba(int xvalue, int yvalue, int N, int E, int S, int W)
{
    // check the limits
    N >= 10 &&N <= 50 ? limitN = N : limitN = 10;
    S <= -10 &&S >= -50 ? limitS = S : limitS = -10;
    E >= 10 &&E <= 50 ? limitE = E : limitE = 10;
    W <= -10 &&W >= -50 ? limitW = W : limitW = -10;

    // check and set if xvalue and yvalue is within limit
    xvalue >= limitW &&xvalue <= limitE ? x = xvalue : x = 0;
    yvalue >= limitS &&yvalue <= limitN ? y = yvalue : y = 0;
}

// user can manually set the limits
// the function will validate the input
void Roomba::setLimits()
{
    do
    {
        cout << "Set North Limit(Range : 10 - 50 inclusive) ";
        cin >> limitN;
    } while (limitN < 10 || limitN > 50); // must be non-negaive integer

    do
    {
        cout << "Set East Limit(Range: 10 - 50 inclusive): ";
        cin >> limitE;
    } while (limitE < 10 || limitE > 50);

    do
    {
        cout << "Set South Limit:(Range: (-10) - (-50) inclusive: ";
        cin >> limitS;
    } while (!(limitS <= -10 && limitS >= -50));

    do
    {
        cout << "Set West Limit: (Range (-10) - (-50) inclusive: )";
        cin >> limitW;
    } while (limitW < -50 || limitW > -10);
}

// get user input (x and y value)
// validate the userinput - to be within the limit
void Roomba::setPosition()
{
    do
    {
        cout << "Enter X-ordinate: ";
        cin >> x;
    } while (!(x >= limitW && x <= limitE)); // DeMorgan'law

    do
    {
        cout << "Enter Y-ordinate: ";
        cin >> y;
    } while (y < limitS || y > limitN);
}

void Roomba::displayLimits() const
{
    cout << "North Limit:\t " << limitN << endl
         << "East Limit:\t " << limitE << endl
         << "South Limit:\t " << limitS << endl
         << "West Limit:\t " << limitW << endl;
}

void Roomba::displayPosition() const
{
    cout << "Roomba is at Position: ( " << x << ", " << y << " )" << endl;
}

void Roomba::showPrompt() const
{
    cout << "Enter the direction to move to robot: " << endl
         << "n: to move forward. " << endl
         << "N: to move forward to the wall." << endl
         << "e: to move right. " << endl
         << "E: to move right to the wall." << endl
         << "s: to move backward. " << endl
         << "S: to move backward to the wall." << endl
         << "w: to move left. " << endl
         << "W: to move left to the wall." << endl
         << "C: to move back to the center." << endl
         << "Q or q to Quit." << endl;
}

void Roomba::moveForward()
{
    cout << "Moving Forward..." << endl;
    y++;
    if (y > limitN) // not moving beyond the limit
    {
        cout << "Can't go further.\nRoomba is bumping up against the wall." << endl;
        y = limitN;
    }
}

void Roomba::moveBackward()
{
    cout << "moving backward...\n";
    y--;
    if (y < limitS)
    {
        cout << "Can't go further.\nRoomba is bumping up against the wall." << endl;
        y = limitS;
    }
}
void Roomba::moveRight()
{
    cout << "moving right..." << endl;
    x++;
    if (x > limitE)
    {
        cout << "Can't go further.\nRoomba is bumping up against the wall." << endl;
        x = limitE;
    }
}
void Roomba::moveLeft()
{
    cout << "moving left..." << endl;
    x--;
    if (x < limitW)
    {
        cout << "Can't go further.\nRoomba is bumping up against the wall." << endl;
        x = limitW;
    }
}

void Roomba::moveCenter()
{
    cout << "Roomba moving slowly back to the center..." << endl;
    x = 0;
    y = 0;
}

void Roomba::moveForwardToWall()
{
    bool isMoving = true;
    while (isMoving)
    {
        y++;
        displayPosition();
        if (y >= limitN)
        {
            cout << "Roomba Hit the Wall. And Stop." << endl;
            y = limitN;
            isMoving = false;
        }
    }
}
void Roomba::moveBackwardToWall()
{
    bool isMoving = true;
    while (isMoving)
    {
        y--;
        displayPosition();
        if (y <= limitS)
        {
            cout << "Roomba Hit the Wall. And Stop." << endl;
            y = limitS;
            isMoving = false;
        }
    }
}
void Roomba::moveRightToWall()
{
    bool isMoving = true;
    while (isMoving)
    {
        x++;
        displayPosition();
        if (x >= limitE)
        {
            cout << "Roomba Hit the Wall. And Stop." << endl;
            x = limitE;
            isMoving = false;
        }
    }
}
void Roomba::moveLeftToWall()
{
    bool isMoving = true;
    while (isMoving)
    {
        x--;
        displayPosition();
        if (x <= limitW)
        {
            cout << "Roomba Hit the Wall. And Stop." << endl;
            x = limitW;
            isMoving = false;
        }
    }
}

void Roomba::runRoomba()
{
    cout << "Roomba is Ready." << endl;
    displayPosition();
    cout << "The Boundaries are as below" << endl;
    cout << "---------------------------" << endl;
    displayLimits();

    // Promt the user to enter commands
    // the robot to go north, south, east and west and enter Q to quit
    char direction;
    showPrompt();
    do
    {

        cin >> direction;
        switch (direction)
        {
        case 'n':
            moveForward();
            displayPosition();
            break;
        case 'N':
            moveForwardToWall();
            break;
        case 'e':
            moveRight();
            displayPosition();
            break;
        case 'E':
            moveRightToWall();
            break;
        case 's':
            moveBackward();
            displayPosition();
            break;
        case 'S':
            moveBackwardToWall();
            break;
        case 'w':
            moveLeft();
            displayPosition();
            break;
        case 'W':
            moveLeftToWall();
            break;
        case 'c':
        case 'C':
            moveCenter();
            displayPosition();
            break;
        case 'Q':
        case 'q':
            cout << "Roomba Stopped. And Program Terminated." << endl;
            break;
        default:
            cout << "Invalid Input.";
            break;
        }

    } while (direction != 'Q' && direction != 'q');
}