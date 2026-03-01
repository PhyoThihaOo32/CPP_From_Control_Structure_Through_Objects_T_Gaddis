/*
For unit Testing:
1.Validate and convert command-line arguments
2.Instantiate a World object
3.Store the converted coordinates into the world's member Point array
4.Call world.print() to verify that data was stored correctly
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