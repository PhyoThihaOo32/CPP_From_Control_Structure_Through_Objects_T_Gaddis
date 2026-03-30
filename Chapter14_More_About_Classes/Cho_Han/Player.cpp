// implementation file for the player class

#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include "Player.h"

using namespace std;

Player::Player(const string &n, bool isHuman)
{
    name = n;
    guess = "";
    points = 0;
    human = isHuman;
}

// player will make a guess
void Player::makeGuess()
{
    const int MIN_VALUE = 0;
    const int MAX_VALUE = 1;

    int guessNum;

    if (human)
    {
        int choice = 0;
        while (true)
        {
            cout << name << ", make your call at the table:" << endl;
            cout << "  1) Cho (Even)" << endl;
            cout << "  2) Han (Odd)" << endl;
            cout << "Enter 1 or 2: ";

            if (cin >> choice && (choice == 1 || choice == 2))
            {
                guessNum = choice - 1;
                break;
            }

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter only 1 or 2." << endl;
        }
    }
    else
    {
        // computer player makes a random guess, either 0 or 1
        guessNum = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
    }

    if (guessNum == 0)
    {
        guess = "Cho (Even)";
    }
    else
    {
        guess = "Han (Odd)";
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

bool Player::isHuman() const
{
    return human;
}
