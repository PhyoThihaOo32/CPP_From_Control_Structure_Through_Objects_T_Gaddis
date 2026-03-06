/*
This  program will run a game - where robots will look for three hidden coins - the robots who find all three coins will win.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "robot.h"
#include "world.h"
#include "point.h"
#include <vector>

using namespace std;

// function prototypes
void validateInput(int, char **, vector<int> &);
void putThreeCoins(World &, vector<int> &);
void displayPrompt();
bool findCoin(Robot &, World &, int &);
void atBoundary(Robot &);
void playComputerRobot(Robot &, World &, int &, int &, int &, int &);
bool playUserRobot(fstream &, fstream &, fstream &, Robot &, World &, int &, int &, int &, int &);
void saveCommands(fstream &, Robot &, int &);
void showcurrentScores(fstream &);
void showOverallScores(fstream &);

int main(int argc, char **argv)
{
    fstream currentScoresFile("currentScores.txt", ios::out | ios::trunc | ios::in);
    fstream commandFiles("commands.txt", ios::out);
    fstream overallGamePlay("overallGamePlayed.txt", ios::out | ios::app | ios::in);

    vector<int> coordinates;      // to store CLI arguments
    World world1, world2, world3; // create three indentical parallel world

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

    // Get the timestamp for the current date and time
    time_t timestamp;
    time(&timestamp);

    // valid the CLI arguments
    validateInput(argc, argv, coordinates);

    // put the location of three coins in World 3 object
    putThreeCoins(world1, coordinates);
    putThreeCoins(world2, coordinates);
    putThreeCoins(world3, coordinates);

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

            isContinue = playUserRobot(commandFiles, currentScoresFile, overallGamePlay, user_robot, world1, user_coin, ttl_player_coins, user_moveCount, ttl_user_moves);
            playComputerRobot(computer_robot1, world2, robot1_coin, ttl_robot1_coins, robot1_moveCount, ttl_robot1_moves);
            playComputerRobot(computer_robot2, world3, robot2_coin, ttl_robot2_coins, robot2_moveCount, ttl_robot2_moves);

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

        currentScoresFile << "-----------------------------------" << endl
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
        if (playAgain == 'Y' || playAgain == 'y')
        {
            // reset the hidden locations
            world1.reset();
            world2 = world1;
            world3 = world1;
            cout << "Coins are hidden somewhere ......." << endl;
            cout << "New Game Start!" << endl;
        }
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
                    // Display the date and time represented by the timestamp
                    << ctime(&timestamp) << endl
                    << "----------------------------------------------" << endl
                    << "----------------------------------------------" << endl;

    // close all files
    currentScoresFile.close();
    overallGamePlay.close();
    commandFiles.close();

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
         << "6. Show Current Game Scores." << endl
         << "7. Show Overall Game History." << endl
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

void playComputerRobot(Robot &robot, World &world, int &coin, int &ttl_coins, int &moveCount, int &ttl_moves)
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

bool playUserRobot(fstream &save_file, fstream &scoreFile, fstream &overallGamePlay, Robot &robot, World &world, int &coin, int &ttl_coins, int &moveCount, int &ttl_moves)
{
    int input;
    cout << "- - - - - - - - - - - - - - - - - - - - - - - -" << endl;
    cout << "                  Player's Turn                    " << endl;
    cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;

    // validate user input
    while (!(cin >> input) || input < 0 || input > 7)
    {
        cin.clear();
        cin.ignore(1000, '\n');
    }

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
    case 6:
        cout << "Here is the Current Game Scores." << endl;
        showcurrentScores(scoreFile);
        break;
    case 7:
        cout << "Here is the All Game History." << endl;
        showOverallScores(overallGamePlay);
        break;
    case 0:
        return false;
    }

    cout << "- - - - - - - - - - - - - - - - - - - - - - - -" << endl;
    cout << "                 * * * * * * *                 " << endl;
    cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
    saveCommands(save_file, robot, input);
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

// this function will show the player current games scores
// function will take ref of fstream object as parameter
void showcurrentScores(fstream &file)
{

    file.seekg(0);
    string data;
    cout << "-------------------------------" << endl;
    cout << "Who is Winning! Who is Gaining?" << endl;
    cout << "-------------------------------" << endl;
    if (file)
    {
        // read from the file
        getline(file, data);
        while (file)
        {
            cout << data << endl;
            // read next item
            getline(file, data);
        }
        file.clear();
    }
    else
    {
        cout << "Can't open the file." << endl;
    }
}

// this function show all the game history that have been played
void showOverallScores(fstream &file)
{
    file.seekg(0);
    string data;
    while (getline(file, data))
    {
        cout << data << endl;
    }
    file.clear();
}

/*
=========================================================
Program: Robot Coin Hunter Game
=========================================================

Overview:
This program simulates a treasure hunting game where
three robots search a 10x10 Cartesian grid for three
hidden coins. The first robot that successfully finds
all three coins wins the game.

The program demonstrates object-oriented programming,
file handling, command-line argument processing,
randomized robot movement, and game state tracking.

---------------------------------------------------------
Program Inputs
---------------------------------------------------------

The coordinates of the three hidden coins are provided
through command-line arguments when the program starts.

Example:

    ./lookfor 1 2 4 5 7 8

This represents three coin locations:

    Coin 1 → (1,2)
    Coin 2 → (4,5)
    Coin 3 → (7,8)

The program validates the command-line arguments to ensure:

• All arguments are numeric values
• Exactly six values are provided
• All coordinates are within the valid range [0,9]

---------------------------------------------------------
Game World
---------------------------------------------------------

The grid environment is represented by a World class.

Three identical world objects are created:

    world1 → used by the player robot
    world2 → used by computer robot 1
    world3 → used by computer robot 2

Each robot searches in its own independent world so that
finding a coin in one world does not affect the other
robots. When a robot finds a coin, the coin location is
set to (-1,-1) to mark it as collected.

---------------------------------------------------------
Robots
---------------------------------------------------------

Three robots participate in the game:

1. Player Robot
   Controlled by user commands.

2. Computer Robot 1
   Moves automatically using random actions.

3. Computer Robot 2
   Moves automatically using random actions.

All robots start at the same initial position:

    (0,0) facing EAST.

---------------------------------------------------------
Player Commands
---------------------------------------------------------

The player can control their robot using the following
commands:

1 → Move Forward
2 → Turn Clockwise
3 → Turn Anti-Clockwise
4 → Zig Movement
5 → Zag Movement
6 → Display Current Game Scores
7 → Display Overall Game History
0 → Quit the Game

---------------------------------------------------------
Coin Detection
---------------------------------------------------------

After every movement, the robot's current position is
compared with the stored coin locations.

If a robot reaches a coin location:

• The robot’s coin counter increases
• A message is displayed indicating the coin was found
• The coin location in the world is reset to (-1,-1)

---------------------------------------------------------
Winning Condition
---------------------------------------------------------

The game ends when any robot collects three coins.

When the game ends, the program displays:

• The winning robot
• Number of coins collected
• Number of moves made

---------------------------------------------------------
File Handling
---------------------------------------------------------

The program uses three files to record gameplay data.

1. commands.txt
   Stores all commands entered by the player along with
   the robot's position and direction after each move.

2. currentScores.txt
   Stores temporary scoreboard information during the
   current game session. This file allows the player to
   view the current statistics while the game is running.

3. overallGamePlayed.txt
   Stores permanent historical records of completed
   game sessions including:

   • Total matches played
   • Total wins per robot
   • Total coins collected
   • Total moves performed
   • Date and time of the game session

---------------------------------------------------------
Timestamp Logging
---------------------------------------------------------

The program records the date and time of the game session
using the C++ time library.

A timestamp is generated when the program starts:

    time_t timestamp;
    time(&timestamp);

At the end of the program, the timestamp is written to
the overallGamePlayed.txt file using:

    ctime(&timestamp)

This allows the game history file to record when each
session was played.

Example output:

    Tue Mar 11 21:42:13 2026

---------------------------------------------------------
Program Flow
---------------------------------------------------------

1. Validate command-line arguments
2. Store coordinates in a vector
3. Initialize three world objects
4. Initialize three robots
5. Display available commands
6. Start the main game loop
7. Robots move and search for coins
8. Coin detection updates statistics
9. Display current scores when requested
10. End game when a robot finds three coins
11. Save final statistics and timestamp to history file

---------------------------------------------------------
Key Programming Concepts Demonstrated
---------------------------------------------------------

• Object-Oriented Programming
• Class interaction (Robot, World, Point)
• Command-line argument validation
• File input/output using fstream
• Random number generation
• Input validation and error handling
• Parallel game worlds
• Game state tracking
• Modular program structure
• Timestamp logging using the C++ time library

=========================================================
*/