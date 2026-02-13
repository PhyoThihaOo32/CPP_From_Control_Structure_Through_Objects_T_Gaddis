#ifndef TEAMPERSON_H
#define TEAMPERSON_H

#include <string>
#include <iostream>

using namespace std;

class TeamPerson
{
private:
    string fullName;
    int playerNumber;

public:
    TeamPerson() : fullName(""), playerNumber(0) {}
    TeamPerson(string name, int num) : fullName(name), playerNumber(num) {}

    void setFullName(string name) { fullName = name; }
    void setPlayerNumber(int num) { playerNumber = num; }

    string getFullName() const { return fullName; }
    int getPlayerNumber() const { return playerNumber; }

    void displayerPlayerInfo() const
    {
        cout << "Name: " << fullName << endl
             << "Number: " << playerNumber << endl;
    }
};

#endif
