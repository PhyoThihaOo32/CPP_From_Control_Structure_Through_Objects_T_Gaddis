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

public:
    Player(string);
    void makeGuess();
    void addPoints(int);
    string getName() const;
    string getGuess() const;
    int getPoints() const;
};

#endif