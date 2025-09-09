/*
This Program demostrate random number
*/

#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

int main()
{

    // Get the system time
    unsigned seed = time(0); // passing 0 as the argument
                             // time function returns the number of seconds thathave elapsed since midnight Jan1, 1970

    // Seed the random generator
    srand(seed);

    // setting rang
    int minRange = 0;
    int maxRange = 100;
    int rand_range;

    // Display three random numbers

    std::cout << rand() << " " << rand() << " " << rand() << std::endl;

    // Displaying random number within range 0-100
    rand_range = (rand() % (maxRange - minRange + 1)) + minRange;

    std::cout << rand_range << std::endl;

    return 0;
}