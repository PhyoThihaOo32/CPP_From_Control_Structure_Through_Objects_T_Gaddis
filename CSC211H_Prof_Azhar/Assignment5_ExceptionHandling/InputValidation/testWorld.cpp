/*
This main() function is used for unit testing the World class.
It:
1. Prompts the user to enter three coin locations (x, y).
2. Validates that each coordinate is within the range [0, 9].
3. Stores the validated coordinates into the World object's
   internal Point array using world.set().
4. Calls world.print() to verify that the data was stored correctly.

Focus: input validation, object interaction, and testing
class functionality.
*/

#include <iostream>
#include "point.h"
#include "world.h"

using namespace std;

int main()
{
    World world;

    int x, y;
    for (int i = 0; i < 3; i++)
    {
        cout << "Coin " << i + 1 << endl;
        do
        {
            cout << "Enter x Coordinate: ";
            cin >> x;
        } while (x < 0 || x > 9);

        do
        {
            cout << "Enter y Coordinate: ";
            cin >> y;

        } while (y < 0 || y > 9);
        world.set(i, x, y);
    }

    world.print();

    return 0;
}