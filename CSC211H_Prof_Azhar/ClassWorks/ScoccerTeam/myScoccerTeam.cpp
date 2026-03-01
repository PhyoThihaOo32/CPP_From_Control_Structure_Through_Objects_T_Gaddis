#include <iostream>
using namespace std;

#include "SoccerTeam.h"
#include "TeamPerson.h"

int main()
{
    SoccerTeam teamCalifornia;
    TeamPerson headCoach;
    TeamPerson asstCoach;

    headCoach.setFullName("Bob Hob");
    headCoach.setPlayerNumber(1);
    asstCoach.setFullName("Alice Smith");
    asstCoach.setPlayerNumber(2);

    teamCalifornia.setHeadCoach(headCoach);
    teamCalifornia.setAssCoach(asstCoach);

    cout << "Head Coach: " << teamCalifornia.getHeadCoach().getFullName()
         << ", Number: " << teamCalifornia.getHeadCoach().getPlayerNumber() << endl;
    cout << "Assistant Coach: " << teamCalifornia.getAssCoach().getFullName()
         << ", Number: " << teamCalifornia.getAssCoach().getPlayerNumber() << endl;

    return 0;
}