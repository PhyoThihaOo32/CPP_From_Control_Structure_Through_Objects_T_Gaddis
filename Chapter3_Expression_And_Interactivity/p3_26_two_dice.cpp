/*
This program roll two dice and print the outcome
*/

#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time() and seed

int main()
{

    // Constants to set the range
    const int MAX_RANGE = 6;
    const int MIN_RANGE = 1;

    // Declare and Initialized the Variables
    unsigned dice1, dice2;

    // Get the system time
    unsigned seed = time(0);

    // Seed the random number generator
    srand(seed);

    // Rolling the Dices

    dice1 = (rand() % (MAX_RANGE - MIN_RANGE + 1)) + MIN_RANGE;
    dice2 = (rand() % (MAX_RANGE - MIN_RANGE + 1)) + MIN_RANGE;

    // Print the result to the console
    std::cout << "Rolling Rolling ... " << std::endl;
    std::cout << "Dice 1: " << dice1 << std::endl;
    std::cout << "Dice 2: " << dice2 << std::endl;

    return 0;
}