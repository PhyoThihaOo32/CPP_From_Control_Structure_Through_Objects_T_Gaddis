#include <iostream>
#include <cstdlib>
#include <ctime>
#include "World.h"

using namespace std;

int main()
{
    // seed random generator
    srand(time(0));

    World myworld;

    int x, y;

    // place robot randomly
    x = rand() % WORLD_SIZE;
    y = rand() % WORLD_SIZE;
    myworld.setRobot(x, y);

    // place cat randomly
    x = rand() % WORLD_SIZE;
    y = rand() % WORLD_SIZE;
    myworld.setCat(x, y);

    // place some dirt spots randomly
    for (int i = 0; i < MAX_SPOTS; i++)
    {
        x = rand() % WORLD_SIZE;
        y = rand() % WORLD_SIZE;
        myworld.setSpot(x, y);
    }

    // print initial world
    cout << "\n=== Initial World ===" << endl;
    myworld.print();

    // start simulation
    cout << "\n=== Robot Roaming ===" << endl;
    myworld.robotRoam();

    // final state
    cout << "\n=== Final World ===" << endl;
    myworld.print();

    return 0;
}