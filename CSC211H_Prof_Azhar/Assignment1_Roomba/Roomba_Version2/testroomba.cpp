#include <iostream>
#include "roomba.cpp"

using namespace std;

int main()
{

    Roomba roomba1(3, 3, 15, 15, -15, -15);
    Roomba roomba2(0, 0, 10, 10, -10, -10);
    Roomba roomba3(2, 2, 20, 20, -20, -20);

    roomba2.runRoomba();

    return 0;
}