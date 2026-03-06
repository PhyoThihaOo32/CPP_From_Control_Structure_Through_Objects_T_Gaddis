// implementation for World class
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "world.h"

using namespace std;

// This function prints out the locations of the three coins.
void World::print() const
{
    cout << "-----Hidden Coins Locations-----" << endl;
    for (int i = 0; i < COINS; i++)
    {
        points[i].print();
    }
    cout << "--------------------------------" << endl;
}

// This function sets the location of the i-th coin in the data member array to (x, y).
void World::set(int index, int x, int y)
{
    // validate the index
    if (index < 0 || index >= 3)
    {
        do
        {
            cout << "Invalid Index.(Enter 0-2)." << endl;
            cin >> index;
        } while (index < 0 || index >= 3);
    }
    points[index].set(x, y);
}

// return point object at the index
Point World::getPoint(int index) const
{
    return points[index];
}

// reset the world with random points
void World::reset()
{
    int ranX, ranY;
    do
    {
        for (int i = 0; i < 3; i++)
        {
            ranX = rand() % 10;
            ranY = rand() % 10;
            points[i].set(ranX, ranY);
        }
    } while ((points[0] == points[1]) || (points[0] == points[2]) || (points[1] == points[2]));
}