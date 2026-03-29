// implementation file for the dealer class

#include "Dealer.h"
#include "Dice.h"
#include <string>

using namespace std;

// constructor
Dealer::Dealer()
{
    dice1Value = 0;
    dice2Value = 0;
}

void Dealer::rollDice()
{
    dice1.roll();
    dice2.roll();

    dice1Value = dice1.getValue();
    dice2Value = dice2.getValue();
}

string Dealer::isChoHan()
{
    string result;
    int sum = dice1Value + dice2Value;

    if (sum % 2 == 0)
    {
        result = "Cho(Even)";
    }
    else
    {
        result = "Han(Odd)";
    }

    return result;
}

int Dealer::getDice1Value()
{
    return dice1Value;
}

int Dealer::getDice2Value()
{
    return dice2Value;
}