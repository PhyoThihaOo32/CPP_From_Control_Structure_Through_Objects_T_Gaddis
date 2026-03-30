/*
Specification file for Player class
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <string>

using namespace std;

class Player
{
private:
    string name;
    string guess;
    int points;
    bool human;

public:
    Player(const string &, bool = false);
    void makeGuess();
    void addPoints(int);
    string getName() const;
    string getGuess() const;
    int getPoints() const;
    bool isHuman() const;
};

#endif
