/*
This  program will run a game - where robots will look for three hidden coins - the robots who find all three coins will win.
*/

#include <iostream>
#include "robot.h"
#include "world.h"
#include "point.h"
#include <vector>
#include <cstdlib> /* srand, rand */
#include <ctime>   /* time */

using namespace std;

// function prototypes
void validateInput(int, char **, vector<int> &);
void putThreeCoins(World &, vector<int> &);
void displayPrompt();
void findCoin(Robot &, World &, int &);
void atBoundary(Robot &);
void playComputerRobot(Robot &, World &, int &, int &);
bool playUserRobot(Robot &, World &, int &, int &);

// void changePoint(World &world)
// {
//     world.set(0, -1, -1);
//     cout << "Inside change point" << endl;
//     world.print();
// }
// void changeWorld(World world)
// {
//     changePoint(world);
//     cout << "Inside change world." << endl;
//     world.print();
// }

int main(int argc, char **argv)
{
    vector<int> coordinates; // to store CLI arguments
    World world1, world2, world3;

    // to count the coins
    int user_coin = 0;
    int robot1_coin = 0;
    int robot2_coin = 0;

    // to count the moves
    int user_moveCount = 0;
    int robot1_moveCount = 0;
    int robot2_moveCount = 0;

    // flags
    bool searching = true;
    bool isContinue = true;

    // declare three robots
    Robot user_robot, computer_robot1, computer_robot2;
    // seeds time
    srand(time(NULL));

    // valid the CLI arguments
    validateInput(argc, argv, coordinates);
    // put the location of three coins in World object
    putThreeCoins(world1, coordinates);
    putThreeCoins(world2, coordinates);
    putThreeCoins(world3, coordinates);

    // cout << "outside" << endl;
    // world.print();
    // changeWorld(world);
    // cout << "outside" << endl;
    // world.print();

    // echo the locations (for test)
    // world.print();

    // initialized three robots - each at (0,0) facing East
    user_robot.init();
    computer_robot1.init();
    computer_robot2.init();

    // world.getPoint(0);
    // world.print();
    // world.set(0, -1, -1);
    // world.print();

    // display commands to user
    displayPrompt();

    // start the program - just one time for now
    while (isContinue && searching)
    {

        isContinue = playUserRobot(user_robot, world1, user_coin, user_moveCount);
        playComputerRobot(computer_robot1, world2, robot1_coin, robot1_moveCount);
        playComputerRobot(computer_robot2, world3, robot2_coin, robot2_moveCount);

        if (user_coin == 3)
        {
            cout << "Awesome!You Win." << endl;
            cout << "Your Coin: " << user_coin << endl;
            cout << "Your Move Count: " << user_moveCount << endl;
            searching = false;
        }
        if (robot1_coin == 3)
        {
            cout << "Robot 1 Win." << endl;
            cout << "Robot Coin: " << robot1_coin << endl;
            cout << "Robot1 Move Count: " << robot1_moveCount << endl;
            searching = false;
        }
        if (robot2_coin == 3)
        {
            cout << "Robot 2 Win." << endl;
            cout << "Robot Coin: " << robot2_coin << endl;
            cout << "Robot 2 Move Count: " << robot2_moveCount << endl;
            searching = false;
        }
    }

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

void displayPrompt()
{
    cout << "Enter The Following Commands To Control Your Robot" << endl
         << "1. Move Forward." << endl
         << "2. Turn Clockwise." << endl
         << "3. Turn AntiClockwise." << endl
         << "4. Zig." << endl
         << "5. Zag." << endl
         << "0: To Quit the Game" << endl;
}

void findCoin(Robot &robot, World &world, int &coin)
{

    if (robot.getPoint() == world.getPoint(0))
    {
        coin++;
        cout << "I Found the coin at ";
        robot.getPoint().print();
        cout << "I am so Lucky!" << endl;
        world.set(0, -1, -1);
    }
    else if (robot.getPoint() == world.getPoint(1))
    {
        coin++;
        cout << "I Found the coin at ";
        robot.getPoint().print();
        cout << "I am so Lucky!" << endl;
        world.set(1, -1, -1);
    }
    else if (robot.getPoint() == world.getPoint(2))
    {
        coin++;
        cout << "I Found the coin at ";
        robot.getPoint().print();
        cout << "I am so Lucky!" << endl;
        world.set(2, -1, -1);
    }
}

void atBoundary(Robot &robot)
{
    if (robot.northEnd())
    {
        cout << "~~~~~~~~~~~~~~~~~~" << endl;
        cout << "I am at North End!" << endl;
        cout << "~~~~~~~~~~~~~~~~~~" << endl;
    }
    else if (robot.eastEnd())
    {
        cout << "~~~~~~~~~~~~~~~~~~" << endl;
        cout << "I am at East End." << endl;
        cout << "~~~~~~~~~~~~~~~~~~" << endl;
    }
    else if (robot.southEnd())
    {
        cout << "~~~~~~~~~~~~~~~~~~" << endl;
        cout << "I am at South End." << endl;
        cout << "~~~~~~~~~~~~~~~~~~" << endl;
    }
    else if (robot.westEnd())
    {
        cout << "~~~~~~~~~~~~~~~~~~" << endl;
        cout << "I am at West End." << endl;
        cout << "~~~~~~~~~~~~~~~~~~" << endl;
    }
}

void playComputerRobot(Robot &robot, World &world, int &coin, int &moveCount)
{

    int action = (rand() % 5) + 1;

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "   I am Computer Robot   " << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    switch (action)
    {
    case 1:
        robot.forward();
        moveCount++;
        atBoundary(robot);
        robot.print();
        findCoin(robot, world, coin);
        break;
    case 2:
        robot.turnCW();
        robot.print();
        break;
    case 3:
        robot.turnAntiCW();
        robot.print();
        break;
    case 4:
        robot.zig();
        moveCount++;
        robot.print();
        findCoin(robot, world, coin);
        break;
    case 5:
        robot.zag();
        moveCount++;
        robot.print();
        findCoin(robot, world, coin);
        break;
    }
}

bool playUserRobot(Robot &robot, World &world, int &coin, int &moveCount)
{

    int input;
    cout << "- - - - - - - - - - - - - - - - - - - - - - - -" << endl;
    cout << "                  Your Turn                    " << endl;
    cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
    cin >> input;

    switch (input)
    {
    case 1:
        robot.forward();
        moveCount++;
        atBoundary(robot);
        robot.print();
        findCoin(robot, world, coin);
        break;
    case 2:
        robot.turnCW();
        robot.print();
        break;
    case 3:
        robot.turnAntiCW();
        robot.print();
        break;
    case 4:
        robot.zig();
        moveCount++;
        robot.print();
        findCoin(robot, world, coin);
        break;
    case 5:
        robot.zag();
        moveCount++;
        robot.print();
        findCoin(robot, world, coin);
        break;
    case 0:
        return false;
    }

    cout << "- - - - - - - - - - - - - - - - - - - - - - - -" << endl;
    cout << "                 * * * * * * *                 " << endl;
    cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
    return true;
}

/*
=========================================================
Program: look-for (Robot Coin Game)
=========================================================

Overview:
This program simulates a game where three robots (one user-controlled
and two computer-controlled) search a 10x10 grid world for three
hidden coins. The first robot to collect all three coins wins.

Coins are provided via command-line arguments as three (x,y)
coordinate pairs.

---------------------------------------------------------
Game Flow:
---------------------------------------------------------

1. Input Validation
   - validateInput() checks:
     • Correct number of command-line arguments
     • All inputs are numeric
     • All coordinates are within range [0,9]
   - Valid coordinates are stored in a vector<int>.

2. World Setup
   - putThreeCoins() stores validated coordinates
     into the World object's internal Point array.
   - world.print() displays hidden coin locations.

3. Robot Initialization
   - All robots are initialized to (0,0).
   - Direction defaults to EAST.

4. Game Loop
   - Each iteration:
       • User robot may act (currently commented).
       • Two computer robots perform random actions.
   - Robots can:
       • Move forward
       • Turn clockwise / anticlockwise
       • Perform zig / zag (edge traversal logic)

5. Coin Detection
   - findCoin() compares robot position with
     each coin location.
   - If match:
       • Coin count increments
       • Coin location is reset to (-1,-1)
         (marks coin as collected)

6. Boundary Detection
   - atBoundary() prints message when robot
     reaches any world edge.

7. Win Condition
   - Game ends when any robot collects 3 coins.
   - Prints winner and move count.

---------------------------------------------------------
Function Responsibilities:
---------------------------------------------------------

validateInput()
- Ensures safe and valid command-line input.

putThreeCoins()
- Transfers validated coordinates into World object.

displayPrompt()
- Displays available user commands.

findCoin()
- Checks if robot position matches any coin.

atBoundary()
- Prints edge notification messages.

computerRobot()
- Performs random action for AI robots.
- Updates move count and checks for coins.

userRobot()
- Handles user input and actions.
- Updates move count and checks for coins.

---------------------------------------------------------
Key Design Concepts:
---------------------------------------------------------

• Object-Oriented Design
  - Robot, World, and Point classes interact cleanly.

• Encapsulation
  - Robot manages movement.
  - World manages coin storage.
  - Point represents coordinates.

• Command-Line Processing
  - Input validation before game starts.

• State Tracking
  - Coin counts per robot.
  - Move counters.
  - Coin removal via coordinate invalidation.

• Modular Structure
  - Game logic divided into small, focused functions.

=========================================================
*/