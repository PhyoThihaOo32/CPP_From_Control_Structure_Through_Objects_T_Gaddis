/*
   This program is modified version of "roomba.cpp 31-jan-2019/dr. azhar based on work Dr. sklar".
   This program demonstrates a simple robot (called "roomba") wandering around in a simulated room.
   The robot can move in any of four directions - based on user input - (forward, backward, left or right) within a grid.
   Robot can move one point per command(N/E/S/W) or all the way to (N/E/S/W) - will stop at the boundary.
*/

#include <iostream>
using namespace std;

void display(int &, int &);    //  display the x and y co-ordinates
void moveForward(int &, int);  // move one point forward(North)
void moveBackward(int &, int); // move one point backward(South)
void moveRight(int &, int);    // move one point to right(East)
void moveLeft(int &, int);     // move one point to left(West)

// behavior function for each direction
// roomba will move all the way to N/E/S/W until it hits the limit and - stop
void moveForwardToWall(int &, int &, int);
void moveBackwardToWall(int &, int &, int);
void moveRightToWall(int &, int &, int);
void moveLeftToWall(int &, int &, int);

// back to the center(0,0)
void moveCenter(int &, int &);

// run roomba
void runRoomba(int &, int &, int, int, int, int);

int main()
{

    // size/boundary of the room 10 * 10 - set up manually
    const int LIMITN = 10, LIMITS = -10,
              LIMITE = 10, LIMITW = -10;

    // put robot at the center of the plane
    int x = 0, y = 0;

    // run the roomba
    runRoomba(x, y, LIMITN, LIMITE, LIMITS, LIMITW);

    return 0;
}

// function take two integer reference parameters - and display the (x, y coordinate)
void display(int &x, int &y)
{
    cout << "Roomba is at location ("
         << x << "," << y << ")\n";
}

// function take two parameters (one integer reference - y-ordinate, and int - North Limit)
// increase y by one - y only increase up to the limit.
void moveForward(int &y, int limitN)
{

    cout << "Moving Forward..." << endl;
    y++;
    if (y > limitN) // not moving beyond the limit
    {
        cout << "Can't go further.\nRoomba is bumping up against the wall." << endl;
        y = limitN;
    }
}

// function take two parameters (one integer reference - y-ordinate, and int - South Limit)
// decrease y by one - but only decrease up to the limit.
void moveBackward(int &y, int limitS)
{

    cout << "moving backward...\n";
    y--;
    if (y < limitS)
    {
        cout << "Can't go further.\nRoomba is bumping up against the wall." << endl;
        y = limitS;
    }
}

// function take two parameters (one integer reference - x-ordinate, and int - East Limit)
// increase x by one - x only increase up to the limit.
void moveRight(int &x, int limitE)
{
    cout << "moving right..." << endl;
    x++;
    if (x > limitE)
    {
        cout << "Can't go further.\nRoomba is bumping up against the wall." << endl;
        x = limitE;
    }
}

// function take two parameters (one integer reference - y-ordinate, and int - West Limit)
// decrease x by one - only decrease up to the limit.
void moveLeft(int &x, int limitW)
{
    cout << "moving left..." << endl;
    x--;
    if (x < limitW)
    {
        cout << "Can't go further.\nRoomba is bumping up against the wall." << endl;
        x = limitW;
    }
}

// robot will move all the way to the North limit
// function take three prameters (two int references x and y and int - North Limit )
// increase y to the limit - display the location by each move
void moveForwardToWall(int &x, int &y, int limitN)
{
    bool isMoving = true;
    while (isMoving)
    {
        y++;
        display(x, y);
        if (y >= limitN)
        {
            cout << "Roomba Hit the Wall. And Stop." << endl;
            y = limitN;
            isMoving = false;
        }
    }
}

// robot will move all the way to the South limit
// function take three prameters (two int references x and y and int - South Limit )
// decrease y to the limit - display the location by each move
void moveBackwardToWall(int &x, int &y, int limitS)
{
    bool isMoving = true;
    while (isMoving)
    {
        y--;
        display(x, y);
        if (y <= limitS)
        {
            cout << "Roomba Hit the Wall. And Stop." << endl;
            y = limitS;
            isMoving = false;
        }
    }
}

// robot will move all the way to the East limit
// function take three prameters (two int references x and y and int - East Limit )
// increase x to the limit - display the location by each move
void moveRightToWall(int &x, int &y, int limitE)
{
    bool isMoving = true;
    while (isMoving)
    {
        x++;
        display(x, y);
        if (x >= limitE)
        {
            cout << "Roomba Hit the Wall. And Stop." << endl;
            x = limitE;
            isMoving = false;
        }
    }
}

// robot will move all the way to the West limit
// function take three prameters (two int references x and y and int - West Limit )
// decrease x to the limit - display the location by each move
void moveLeftToWall(int &x, int &y, int limitW)
{
    bool isMoving = true;
    while (isMoving)
    {
        x--;
        display(x, y);
        if (x <= limitW)
        {
            cout << "Roomba Hit the Wall. And Stop." << endl;
            x = limitW;
            isMoving = false;
        }
    }
}

// move to the center(0,0)
void moveCenter(int &x, int &y)
{
    // check if the robot is at the center
    if (x == 0 && y == 0)
    {
        cout << "Roomba is at the center already." << endl;
    }
    // if not put the robot back to the center
    else
    {
        cout << "Slowly Moving back to the center...beep..Beep!" << endl;
        x = 0, y = 0;
    }
}

// the main function to run the roomba
// function take six paramters (two integer references (x, y co-ordinates), four intergers - N/E/S/W Limits)
// user can interact with the robot
void runRoomba(int &x, int &y, int limitN, int limitE, int limitS, int limitW)
{
    // Promt the user to enter commands
    // the robot to go north, south, east and west and enter Q to quit
    char direction;
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
    do
    {

        cin >> direction;
        switch (direction)
        {
        case 'n':
            moveForward(y, limitN);
            display(x, y);
            break;
        case 'N':
            moveForwardToWall(x, y, limitN);
            break;
        case 'e':
            moveRight(x, limitE);
            display(x, y);
            break;
        case 'E':
            moveRightToWall(x, y, limitE);
            break;
        case 's':
            moveBackward(y, limitS);
            display(x, y);
            break;
        case 'S':
            moveBackwardToWall(x, y, limitS);
            break;
        case 'w':
            moveLeft(x, limitW);
            display(x, y);
            break;
        case 'W':
            moveLeftToWall(x, y, limitW);
            break;
        case 'c':
        case 'C':
            moveCenter(x, y);
            display(x, y);
            break;
        case 'Q':
        case 'q':
            cout << "Robot Stop. And Program Terminated." << endl;
            break;
        default:
            cout << "Invalid Input.";
            break;
        }

    } while (direction != 'Q' && direction != 'q');
}
