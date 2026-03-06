/*
This  program will run a game - where robots will look for three hidden coins - the robots who find all three coins will win.
*/

#include <iostream>
#include <fstream>
#include <string>
#include "robot.h"
#include "world.h"
#include "point.h"
#include <vector>
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */

using namespace std;

// function prototypes
void validateInput(int, char **, vector<int> &);
void putThreeCoins(World &, vector<int> &);
void displayPrompt();
bool findCoin(Robot &, World &, int &);
void atBoundary(Robot &);
void playComputerRobot(Robot &, World, int &, int &, int &, int &);
bool playUserRobot(fstream &, Robot &, World, int &, int &, int &, int &);
void saveCommands(fstream &, Robot &, int &);
void showHighScores(fstream &);

int main(int argc, char **argv)
{
    fstream highScoreFiles("high_scores.txt", ios::out | ios::app);
    fstream commandFiles("commands.txt", ios::out | ios::app);
    fstream overallGamePlay("overallGamePlayed.txt", ios::out);

    vector<int> coordinates; // to store CLI arguments
    World world;

    // total matches record and total wins
    int total_matches = 0;
    int user_win = 0,
        robot1_win = 0,
        robot2_win = 0;

    // overall coins for records
    int ttl_player_coins = 0,
        ttl_robot1_coins = 0,
        ttl_robot2_coins = 0;

    // to count the moves
    int ttl_user_moves = 0;
    int ttl_robot1_moves = 0;
    int ttl_robot2_moves = 0;

    // flags - to repeat the game
    char playAgain;

    // declare three robots
    Robot user_robot, computer_robot1, computer_robot2;

    // initialized three robots - each at (0,0) facing East
    user_robot.init();
    computer_robot1.init();
    computer_robot2.init();

    // seeds time
    srand(time(NULL));

    // valid the CLI arguments
    validateInput(argc, argv, coordinates);

    // put the location of three coins in World object
    putThreeCoins(world, coordinates);

    // echo the locations (for test)
    world.print();

    // display commands to user
    displayPrompt();

    do
    {
        // flags
        bool searching = true;
        bool isContinue = true;

        // to count the coins
        int user_coin = 0;
        int robot1_coin = 0;
        int robot2_coin = 0;

        // to count the moves
        int user_moveCount = 0;
        int robot1_moveCount = 0;
        int robot2_moveCount = 0;

        total_matches++;
        // start the program
        while (isContinue && searching)
        {

            isContinue = playUserRobot(commandFiles, user_robot, world, user_coin, ttl_player_coins, user_moveCount, ttl_user_moves);
            playComputerRobot(computer_robot1, world, robot1_coin, ttl_robot1_coins, robot1_moveCount, ttl_robot1_moves);
            playComputerRobot(computer_robot2, world, robot2_coin, ttl_robot2_coins, robot2_moveCount, ttl_robot2_moves);

            if (user_coin >= 3)
            {
                cout << "Awesome!You Win." << endl;
                cout << "Your Coin: " << user_coin << endl;
                cout << "Your Move Count: " << user_moveCount << endl;
                user_win++;
                searching = false;
            }
            if (robot1_coin >= 3)
            {
                cout << "Robot 1 Win." << endl;
                cout << "Robot Coin: " << robot1_coin << endl;
                cout << "Robot1 Move Count: " << robot1_moveCount << endl;
                robot1_win++;
                searching = false;
            }
            if (robot2_coin >= 3)
            {
                cout << "Robot 2 Win." << endl;
                cout << "Robot Coin: " << robot2_coin << endl;
                cout << "Robot 2 Move Count: " << robot2_moveCount << endl;
                robot2_win++;
                searching = false;
            }
        }

        highScoreFiles << "-----------------------------------" << endl
                       << "Total Matches Played: " << total_matches << endl
                       << "Player Wins: " << user_win << endl
                       << "Player Coins " << ttl_player_coins << endl
                       << "Player Moves: " << ttl_user_moves << endl
                       << "-----------------------------------" << endl
                       << "Robot1 Wins: " << robot1_win << endl
                       << "Robot1 Coins: " << ttl_robot1_coins << endl
                       << "Robot1 Moves: " << ttl_robot1_moves << endl
                       << "-----------------------------------" << endl
                       << "Robot2 Wins: " << robot2_win << endl
                       << "Robot2 Coins: " << ttl_robot2_coins << endl
                       << "Robot2 Moves: " << ttl_robot2_moves << endl
                       << "-----------------------------------" << endl;

        cout << "Play Again!? Y/N " << endl;
        cin >> playAgain;
        // if (playAgain == 'Y' || playAgain == 'y')
        // {
        //     // reset the hidden locations
        //     world.reset();
        //     world.print();
        //     highScoreFiles << "New Game Start!" << endl;
        // }
    } while (playAgain != 'N');

    overallGamePlay << "-----------------------------------------------" << endl
                    << "---------------Last Game Data -----------------" << endl
                    << "Total Matches Played: " << total_matches << endl
                    << "Player Wins: " << user_win << endl
                    << "Player Coins " << ttl_player_coins << endl
                    << "Player Moves: " << ttl_user_moves << endl
                    << "----------------------------------------------" << endl
                    << "Robot1 Wins: " << robot1_win << endl
                    << "Robot1 Coins: " << ttl_robot1_coins << endl
                    << "Robot1 Moves: " << ttl_robot1_moves << endl
                    << "----------------------------------------------" << endl
                    << "Robot2 Wins: " << robot2_win << endl
                    << "Robot2 Coins: " << ttl_robot2_coins << endl
                    << "Robot2 Moves: " << ttl_robot2_moves << endl
                    << "----------------------------------------------" << endl
                    << "----------------------------------------------" << endl;

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
    cout << "Hello Treasure Hunters! Welcome. " << endl
         << "Three coins are hidden somewhere in this Cartesian plane." << endl
         << "Will you able to find them?" << endl
         << "Enter The Following Commands To Control Your Robot" << endl
         << "1. Move Forward." << endl
         << "2. Turn Clockwise." << endl
         << "3. Turn AntiClockwise." << endl
         << "4. Zig." << endl
         << "5. Zag." << endl
         << "6. Show Scores." << endl
         << "7. Show Highest Scores." << endl
         << "0: To Quit the Game" << endl;
}

bool findCoin(Robot &robot, World &world, int &coin)
{
    bool coinFound = false;
    if (robot.getPoint() == world.getPoint(0))
    {
        coin++;
        cout << "I Found the coin at ";
        robot.getPoint().print();
        cout << "I am so Lucky!" << endl;
        world.set(0, -1, -1);
        coinFound = true;
    }
    else if (robot.getPoint() == world.getPoint(1))
    {
        coin++;
        cout << "I Found the coin at ";
        robot.getPoint().print();
        cout << "I am so Lucky!" << endl;
        world.set(1, -1, -1);
        coinFound = true;
    }
    else if (robot.getPoint() == world.getPoint(2))
    {
        coin++;
        cout << "I Found the coin at ";
        robot.getPoint().print();
        cout << "I am so Lucky!" << endl;
        world.set(2, -1, -1);
        coinFound = true;
    }
    return coinFound;
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

void playComputerRobot(Robot &robot, World world, int &coin, int &ttl_coins, int &moveCount, int &ttl_moves)
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
        ttl_moves++;
        atBoundary(robot);
        robot.print();
        findCoin(robot, world, coin) ? ttl_coins++ : ttl_coins;
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
        ttl_moves++;
        robot.print();
        findCoin(robot, world, coin) ? ttl_coins++ : ttl_coins;
        break;
    case 5:
        robot.zag();
        moveCount++;
        ttl_moves++;
        robot.print();
        findCoin(robot, world, coin) ? ttl_coins++ : ttl_coins;
        break;
    }
}

bool playUserRobot(fstream &file, Robot &robot, World world, int &coin, int &ttl_coins, int &moveCount, int &ttl_moves)
{
    int input;
    cout << "- - - - - - - - - - - - - - - - - - - - - - - -" << endl;
    cout << "                  Player's Turn                    " << endl;
    cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
    do
    {
        cin >> input;
    } while (input < 0 || input > 7);

    switch (input)
    {
    case 1:
        robot.forward();
        moveCount++;
        ttl_moves++;
        atBoundary(robot);
        robot.print();
        findCoin(robot, world, coin) ? ttl_coins++ : ttl_coins;
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
        ttl_moves++;
        robot.print();
        findCoin(robot, world, coin) ? ttl_coins++ : ttl_coins;
        break;
    case 5:
        robot.zag();
        moveCount++;
        ttl_moves++;
        robot.print();
        findCoin(robot, world, coin) ? ttl_coins++ : ttl_coins;
        break;
    case 0:
        return false;
    }

    cout << "- - - - - - - - - - - - - - - - - - - - - - - -" << endl;
    cout << "                 * * * * * * *                 " << endl;
    cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
    saveCommands(file, robot, input);
    return true;
}

// this function will save the user commands, and the robot positions
// function will take the fstream ref, Robot ref, int as parameters
void saveCommands(fstream &file, Robot &robot, int &command)
{
    if (!file)
    {
        cout << "Warning!Command File is not open." << endl
             << "Datas will not be saved." << endl;
    }
    else
    {
        char c = command + '0';
        file.put(static_cast<char>(c));
        file << "( " << robot.getPoint().getX() << ", " << robot.getPoint().getY() << ")" << endl;
        file << robot.getDirection() << endl;
    }
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