#ifndef SOCCERTEAM_H
#define SOCCERTEAM_H

#include "TeamPerson.h"

class SoccerTeam
{
private:
    TeamPerson headcoach;
    TeamPerson asscoach;

public:
    SoccerTeam() {};
    SoccerTeam(TeamPerson p1, TeamPerson p2)
    {
        headcoach = p1;
        asscoach = p2;
    }

    void setHeadCoach(TeamPerson hc) { headcoach = hc; }
    void setAssCoach(TeamPerson ac) { asscoach = ac; }

    TeamPerson getHeadCoach() const { return headcoach; }
    TeamPerson getAssCoach() const { return asscoach; }

    void displaySoccoerTeam() const
    {
        cout << "Head Coach: " << endl;
        headcoach.displayerPlayerInfo();
        cout << "Assistant Coach: " << endl;
        asscoach.displayerPlayerInfo();
    }
};

#endif
