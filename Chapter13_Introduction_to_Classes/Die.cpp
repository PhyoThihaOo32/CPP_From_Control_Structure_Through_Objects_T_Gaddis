// implementation file for die class
#include "Die.h"
#include <cstdlib>
#include <ctime>

using namespace std;

Die::Die(int numSide)
{
    side = numSide;

    unsigned seed = time(0);

    // seed the random num generator
    srand(seed);

    // perform initial roll
    roll();
}

void Die::roll()
{
    // const for minium die value
    const int MIN_VALUE = 1; // minium die value

    value = (rand() % (side - MIN_VALUE + 1)) + MIN_VALUE;
    /*
      Get a random value for the die
    % (side - MIN_VALUE + 1)         keeps the result within 0 → (side−1)
    + MIN_VALUE                      shifts range to MIN_VALUE → side
    */
}

int Die::getSides()
{
    return side;
}

int Die::getValue()
{
    return value;
}