/*
This  program will run a game - where robots will look for three hidden coins - the robots who find all three coins will win.
*/

#include <iostream>
#include "robot.h"
#include "world.h"
#include "point.h"
#include <vector>
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */

using namespace std;

void validateInput(int, char **, vector<int> &);
void putThreeCoins(World &, vector<int> &);
void displayPrompt();
void findCoin(Robot &, World &, int &);
void atBoundary(Robot &);
void computerRobot(Robot &, World &, int &);

int main(int argc, char **argv)
{
    vector<int> coordinates;
    World world;
    int user_coin = 0;
    int computer1_coin = 0;
    int computer2_coin = 0;
    // char input;
    bool isFound = true;
    int userInput;
    Robot robot, computer_robot1, computer_robot2;
    srand(time(NULL));

    validateInput(argc, argv, coordinates);
    putThreeCoins(world, coordinates);
    world.print();
    robot.init();
    computer_robot1.init();
    computer_robot2.init();

    displayPrompt();
    do
    {
        userInput = (rand() % 5) + 1;
        cout << "- - - - - - - - - - - - - - - - - - - - - - - -" << endl;
        cout << "                  Your Turn                    " << endl;
        cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
        // cin >> input;
        switch (userInput)
        {
        case 1:
            robot.forward();
            atBoundary(robot);
            robot.print();
            findCoin(robot, world, user_coin);
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
            robot.print();
            findCoin(robot, world, user_coin);
            break;
        case 5:
            robot.zag();
            robot.print();
            findCoin(robot, world, user_coin);
            break;
        }

        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "           I am Computer Robot 1      " << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        computerRobot(computer_robot1, world, computer1_coin);
        cout << "========================================" << endl;
        cout << "           I am Computer Robot 2        " << endl;
        cout << "========================================" << endl;
        computerRobot(computer_robot2, world, computer2_coin);

        if (user_coin == 3)
        {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "You found all the coins!!" << endl;
            cout << "~~~~~~~~YOU WIN!~~~~~~~~~" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            isFound = false;
        }
        else if (computer1_coin == 3)
        {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "Computer1 found all the coins!!" << endl;
            cout << "~~~~~~~~~~YOU LOSE!~~~~~~~~~~~~" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            isFound = false;
        }
        else if (computer2_coin == 3)
        {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "Computer2 found all the coins!!" << endl;
            cout << "~~~~~~~~~~YOU LOSE!~~~~~~~~~~~~" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            isFound = false;
        }
    } while (isFound);

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
         << "q: To Quit the Game" << endl;
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
        world.set(2, -1, -1);
        cout << "I Found the coin at ";
        robot.getPoint().print();
        cout << "I am so Lucky!" << endl;
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

void computerRobot(Robot &robot, World &world, int &coin)
{
    int action = (rand() % 5) + 1;

    switch (action)
    {
    case 1:
        robot.forward();
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
        robot.print();
        findCoin(robot, world, coin);
        break;
    case 5:
        robot.zag();
        robot.print();
        findCoin(robot, world, coin);
        break;
    }
}
