/*
=========================================================
Program: look-for (Robot Coin Search Game)
=========================================================

Description:
This program simulates a treasure hunting game on a 10x10
grid world where three robots search for three hidden coins.

• One robot is controlled by the user.
• Two robots are controlled by the computer.
• The first robot to find all three coins wins.

The coin locations are provided through command-line
arguments as three coordinate pairs:
(x1 y1 x2 y2 x3 y3)

---------------------------------------------------------
Program Structure
---------------------------------------------------------

1. Input Validation
   validateInput()
   - Ensures command-line arguments are numeric
   - Ensures coordinates are within range [0,9]
   - Stores valid values into a vector.

2. World Initialization
   putThreeCoins()
   - Stores the validated coordinates into the
     World object's internal Point array.

3. Robot Initialization
   - All robots start at position (0,0)
   - Default orientation is EAST.

4. Game Loop
   - The user robot and two computer robots take turns.
   - Computer robots perform random actions.

5. Robot Actions
   Robots may:
   - Move forward
   - Turn clockwise
   - Turn anticlockwise
   - Perform zig movement
   - Perform zag movement

6. Coin Detection
   findCoin()
   - Checks if a robot's position matches a coin.
   - If found:
       • coin counter increments
       • coin location is invalidated (-1,-1).

7. Boundary Detection
   atBoundary()
   - Prints messages when a robot reaches the
     north, south, east, or west edge.

8. Game End
   - The game ends when any robot finds 3 coins.
   - Winner and move counts are displayed.

---------------------------------------------------------
Additional Features
---------------------------------------------------------

• Move tracking for each robot
• Score saving to "scores.txt"
• Command logging to "commands.txt"
• Multiple matches supported

---------------------------------------------------------
Concepts Demonstrated
---------------------------------------------------------

• Object-Oriented Programming (Robot, World, Point)
• Command-line argument processing
• File I/O using fstream
• Random number generation
• Modular function design
• Vector usage
• Game loop logic
• State tracking and validation

=========================================================
*/