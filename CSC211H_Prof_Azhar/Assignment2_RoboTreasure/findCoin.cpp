/*
Program simulates a robot moving through a 2D world grid(10 * 10)
As it traverses each cell, it checks whether a coin is present.

When a coin is found, it prints a message with the robot’s
current location and celebrates the discovery.

The program also counts the total number of moves made.
At the end, it displays how many moves the robot performed.

*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include "point.h"
#include "world.h"
#include "robot.h"

using namespace std;

void validateInput(int, char **, vector<int> &);
void putThreeCoins(World &, vector<int> &);
void runTreasureHunterRoboBobby(Robot, World &);

int main(int argc, char *argv[])
{
    World world;
    Robot robo;
    vector<int> coordinates; // to store int(from cml args)

    // Input Validation
    validateInput(argc, argv, coordinates);

    // set the coin locations
    putThreeCoins(world, coordinates);

    // run the treasure hunter
    runTreasureHunterRoboBobby(robo, world);

    return 0;
}

/*
This function validate the input from commandline argument
-check if the argument is enter more than 1
-check if the argument isdigit not char
-check if the number are in acceptable range [0,9]
-add the purifed data into vector of int
-function take three parametes int, char**, ref to vector<in>
*/

void validateInput(int argc, char **argv, vector<int> &coordinates)
{
    int temp; // temp for input validation(range check)

    // check if the user has entered 2 command-line arguments
    if (argc < 2)
    {
        cout << "You didn't enter the co-ordinates. "
             << "Please enter three (x,y) coordinates in range [0,9] (inclusive)." << endl
             << "Program Terminated." << endl;
        exit(EXIT_FAILURE);
    }

    // check the input is a number(not char)
    for (int i = 1; i < argc; i++)
    {
        for (int j = 0; argv[i][j] != '\0'; j++)
        {
            if (!isdigit(argv[i][j])) // check each elements
            {
                cout << "Invalid Input.\n"
                     << argv[i][j] << " is not a number."
                     << "Program Terminated." << endl;
                exit(EXIT_FAILURE);
            }
        }
    }

    // Check that the arguments are within the range [0, 9],
    // and convert into integers
    for (int i = 1; i < 7; i++)
    {
        temp = atoi(*(argv + i)); // convert c-string into integer
        if (temp < 0 || temp > 9)
        {
            cout << "Please enter coordinates in range [0,9] (inclusive)." << endl
                 << "Program Terminated." << endl;
            exit(EXIT_FAILURE);
        }
        else
        {
            // store the valid inputs into vector of coordinates
            coordinates.push_back(temp);
        }
    }
}

/*
This function take two arguments- World&, vector<int>&
-will initialized the world data memeber array of point with - value from vector
-that is - setting the world with hidden coin locations
*/

void putThreeCoins(World &world, vector<int> &coordinates)
{
    // set the cleaned command line arguments to world objects - that is location of 3 hidden coins
    int pointIndex = 0;
    for (int i = 0, j = 1; i < coordinates.size(); i += 2, j += 2)
    {
        // set x and y values to three points objects
        int x = coordinates.at(i);
        int y = coordinates.at(j);
        world.set(pointIndex, x, y);
        pointIndex++;
    }
}

/*
This function need alots of refractoring and cleaning---Let's just run now.
*/
void runTreasureHunterRoboBobby(Robot robo, World &world)
{
    robo.init();
    Point c1 = world.getPoint(0);
    Point c2 = world.getPoint(1);
    Point c3 = world.getPoint(2);
    Point rb = robo.getPoint();
    int cellCount = 1;
    int coins = 0;

    // echo the values
    world.print();
    robo.print();

    // transvere the cells and look for the coins
    while (robo.forward())
    {
        cellCount++;
        robo.print();
        if (robo.getPoint() == c1 || robo.getPoint() == c2 || robo.getPoint() == c3)
        {
            cout << "I found a treasure chest!" << endl;
            cout << "Location at ( " << robo.getPoint().getX()
                 << " , " << robo.getPoint().getY() << " )." << endl;
            coins++;
            if (coins == 3)
                break;
        }
        if (robo.eastEnd())
        {
            cout << "\nI am at East End.\n"
                 << endl;

            robo.zag(); // east -> north -> forward -> west
            robo.print();
            cellCount++;
            if (robo.getPoint() == c1 || robo.getPoint() == c2 || robo.getPoint() == c3)
            {
                cout << "I found a treasure chest!" << endl;
                cout << "Location at ( " << robo.getPoint().getX()
                     << " , " << robo.getPoint().getY() << " )." << endl;
                coins++; // 1 2
                if (coins == 3)
                    break;
            }
        }
        if (robo.westEnd())
        {
            cout << "\nI am at West End.\n"
                 << endl;

            robo.zig(); // west -> north -> forward -> east
            robo.print();
            cellCount++;
            if (robo.getPoint() == c1 || robo.getPoint() == c2 || robo.getPoint() == c3)
            {
                cout << "I found a treasure chest!" << endl;
                cout << "Location at ( " << robo.getPoint().getX()
                     << " , " << robo.getPoint().getY() << " )." << endl;
                coins++;
                if (coins == 3)
                    break;
            }
        }
    }
    cout << "Move Counts: " << cellCount << endl;
    cout << "Coins: " << coins << endl;
}
