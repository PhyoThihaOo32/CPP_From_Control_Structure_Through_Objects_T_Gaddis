/*
The program simulates the game of Cho-Han.
*/

#include <iostream>
#include <string>
#include "Dealer.h"
#include "Player.h"
#include "Dice.h"

using namespace std;

// function prototype
void roundResults(Dealer &, Player &, Player &);
void checkGuess(Player &, Dealer &);
void displayGrandWinner(const Player &, const Player &);

int main()
{

    const int MAX_ROUNDS = 5;
    string player1Name, player2Name;

    // get players Names
    cout << "Enter the first player's name: ";
    cin >> player1Name;
    cout << "Enter the second player's name: ";
    cin >> player2Name;

    // create the dealer
    Dealer dealer;

    // create the two players
    Player player1(player1Name);
    Player player2(player2Name);

    // play the round and bet
    for (int i = 0; i < MAX_ROUNDS; i++)
    {
        cout << "Now playing round " << i + 1 << " ." << endl;

        // roll the dice
        dealer.rollDice();

        // player makes guess
        player1.makeGuess();
        player2.makeGuess();

        // check the winner of the round
        roundResults(dealer, player1, player2);
    }

    // display the winner
    displayGrandWinner(player1, player2);

    return 0;
}

// the round result function determines the result of the current round
void roundResults(Dealer &dealer, Player &p1, Player &p2)
{
    // show the dice value
    cout << "The dealer rolled " << dealer.getDice1Value()
         << " and " << dealer.getDice2Value() << endl;

    // show the result (cho or han)
    cout << "Result: " << dealer.isChoHan() << endl;

    // check each player's guess and award points
    checkGuess(p1, dealer);
    checkGuess(p2, dealer);
}

// check a player's guess against the dealer's result
void checkGuess(Player &player, Dealer &dealer)
{
    const int POINT = 1;

    // get the player's guess
    string playerGuess = player.getGuess();

    // get the dealer's result
    string dealerResult = dealer.isChoHan();

    // display the player result
    cout << "Player " << player.getName() << " gussed "
         << player.getGuess() << endl;

    if (playerGuess == dealerResult)
    {
        player.addPoints(POINT);
        cout << "Awarding " << POINT << " point(s) to "
             << player.getName() << endl;
    }
}

void displayGrandWinner(const Player &p1, const Player &p2)
{
    cout << "Game Over. Here are the result." << endl;

    // display player 1 result
    cout << p1.getName() << " :"
         << p1.getPoints() << " points." << endl;

    // display player 2 result
    cout << p2.getName() << " :"
         << p2.getPoints() << " points." << endl;

    // determine the winner
    if (p1.getPoints() > p2.getPoints())
    {
        cout << p1.getName() << " is the winner." << endl;
    }
    else if (p2.getPoints() > p1.getPoints())
    {
        cout << p2.getName() << " is the winner." << endl;
    }
    else
    {
        cout << "Both players are tied." << endl;
    }
}