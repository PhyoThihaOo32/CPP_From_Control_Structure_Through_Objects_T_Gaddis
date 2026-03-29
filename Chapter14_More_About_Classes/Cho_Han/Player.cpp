// implementation file for the player class

#include <string>
#include <cstdlib>
#include <ctime>
#include "Player.h"

using namespace std;

Player::Player(string n)
{
    // seed the random number generator
    srand(time(0));

    name = n;
    guess = "";
    points = 0;
}

// player will make a guess
void Player::makeGuess()
{

    const int MIN_VALUE = 0;
    const int MAX_VALUE = 1;

    // guess random number, either 0 or 1
    int guessNum = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;

    // convert the random number to Cho or Han
    if (guessNum == 0)
    {
        guess = "Cho(Even)";
    }
    else
    {
        guess = "Han(Odd)";
    }
}

void Player::addPoints(int newPoints)
{
    points += newPoints;
}

string Player::getName() const
{
    return name;
}

string Player::getGuess() const
{
    return guess;
}

int Player::getPoints() const
{
    return points;
}
