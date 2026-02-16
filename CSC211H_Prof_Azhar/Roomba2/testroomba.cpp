#include <iostream>
#include "roomba.cpp"

using namespace std;

int main()
{

    Roomba roomba1;
    Roomba roomba2(0, 0, 10, 10, -10, -10);

    roomba2.runRoomba();

    return 0;
}