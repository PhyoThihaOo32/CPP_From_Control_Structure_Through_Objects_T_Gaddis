/*
Specification file for dealer class
Class can roll the dice, report the value of the dice, and
report the total value of the dices is Cho or Han.
*/

#ifndef DEALER_H
#define DEALER_H

#include <string>
#include "Dice.h"

using namespace std;

class Dealer
{
private:
    Dice dice1;
    Dice dice2;
    int dice1Value;
    int dice2Value;

public:
    Dealer();
    void rollDice();
    string isChoHan();
    int getDice1Value();
    int getDice2Value();
};

#endif