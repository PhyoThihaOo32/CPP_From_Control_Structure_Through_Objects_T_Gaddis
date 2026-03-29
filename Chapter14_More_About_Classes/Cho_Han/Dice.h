// Specification file for the Dice class

#ifndef DICE_H
#define DICE_H

class Dice
{
private:
    int side;
    int value;

public:
    Dice(int = 6);
    void roll();
    int getSides();
    int getValue();
};

#endif