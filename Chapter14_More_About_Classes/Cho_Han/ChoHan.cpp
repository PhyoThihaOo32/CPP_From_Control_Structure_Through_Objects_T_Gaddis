/*
Cho-Han game with one human player, two computer players, and a dealer.
*/

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <cstdlib>
#include <ctime>
#include "Dealer.h"
#include "Player.h"

using namespace std;

// function prototypes
void displayFestivalIntro();
void playMusicCue(bool, const string &);
void roundResults(Dealer &, vector<Player *> &);
void checkGuess(Player &, Dealer &);
void displayScoreboard(const vector<Player *> &);
void displayGrandWinner(const vector<Player *> &);

int main()
{
    const int MAX_ROUNDS = 5;
    string humanName;
    char musicChoice;
    bool musicOn = false;

    // seed randomness once for the whole program
    srand(static_cast<unsigned>(time(nullptr)));

    displayFestivalIntro();

    cout << "Traveler, what is your name? ";
    getline(cin, humanName);
    if (humanName.empty())
    {
        humanName = "Sakura";
    }

    cout << "Enable festival music cues (terminal bell)? (y/n): ";
    cin >> musicChoice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    musicOn = (musicChoice == 'y' || musicChoice == 'Y');

    // create the dealer and players
    Dealer dealer;
    Player humanPlayer(humanName, true);
    Player cpu1("Aiko");
    Player cpu2("Kenji");

    vector<Player *> players;
    players.push_back(&humanPlayer);
    players.push_back(&cpu1);
    players.push_back(&cpu2);

    cout << endl;
    cout << "Dealer Master Hideo welcomes all players to the lantern table." << endl;
    cout << "Opponents tonight: Aiko and Kenji." << endl;
    cout << "First to earn glory over " << MAX_ROUNDS << " rounds wins." << endl;
    cout << endl;

    for (int round = 1; round <= MAX_ROUNDS; round++)
    {
        cout << "==========================" << endl;
        cout << "Round " << round << " of " << MAX_ROUNDS << endl;
        cout << "==========================" << endl;

        playMusicCue(musicOn, "Taiko rhythm: don... don...");

        dealer.rollDice();

        for (size_t i = 0; i < players.size(); i++)
        {
            players[i]->makeGuess();
        }

        roundResults(dealer, players);
        cout << endl;
    }

    playMusicCue(musicOn, "Shamisen finale...");
    displayGrandWinner(players);

    return 0;
}

void displayFestivalIntro()
{
    cout << "===============================================" << endl;
    cout << "      KAWAII CHO-HAN FESTIVAL NIGHT" << endl;
    cout << "===============================================" << endl;
    cout << "Paper lanterns glow, lucky charms sway, and" << endl;
    cout << "the dealer invites you to a traditional game of" << endl;
    cout << "Cho (even) and Han (odd)." << endl;
    cout << endl;
}

void playMusicCue(bool musicOn, const string &cue)
{
    if (musicOn)
    {
        cout << '\a';
        cout << "[Festival Music] " << cue << endl;
    }
}

// determine the result of the current round
void roundResults(Dealer &dealer, vector<Player *> &players)
{
    int die1 = dealer.getDice1Value();
    int die2 = dealer.getDice2Value();
    int total = die1 + die2;

    cout << endl;
    cout << "Dealer reveals the dice: " << die1
         << " and " << die2
         << " (total " << total << ")" << endl;

    cout << "Round result: " << dealer.isChoHan() << endl;
    cout << endl;

    for (size_t i = 0; i < players.size(); i++)
    {
        checkGuess(*players[i], dealer);
    }

    cout << endl;
    displayScoreboard(players);
}

// check a player's guess against the dealer's result
void checkGuess(Player &player, Dealer &dealer)
{
    const int POINT = 1;

    string playerGuess = player.getGuess();
    string dealerResult = dealer.isChoHan();

    if (player.isHuman())
    {
        cout << player.getName() << " guessed " << playerGuess << "." << endl;
    }
    else
    {
        cout << player.getName() << " (computer) guessed " << playerGuess << "." << endl;
    }

    if (playerGuess == dealerResult)
    {
        player.addPoints(POINT);
        cout << "  Lucky hit! " << player.getName()
             << " receives " << POINT << " point." << endl;
    }
    else
    {
        cout << "  No point this round." << endl;
    }
}

void displayScoreboard(const vector<Player *> &players)
{
    cout << "Scoreboard under the lanterns:" << endl;
    for (size_t i = 0; i < players.size(); i++)
    {
        cout << "  " << players[i]->getName()
             << ": " << players[i]->getPoints() << " point(s)" << endl;
    }
}

void displayGrandWinner(const vector<Player *> &players)
{
    int bestScore = players[0]->getPoints();
    vector<string> winners;

    for (size_t i = 0; i < players.size(); i++)
    {
        if (players[i]->getPoints() > bestScore)
        {
            bestScore = players[i]->getPoints();
        }
    }

    for (size_t i = 0; i < players.size(); i++)
    {
        if (players[i]->getPoints() == bestScore)
        {
            winners.push_back(players[i]->getName());
        }
    }

    cout << "===============================================" << endl;
    cout << "Final Results" << endl;
    cout << "===============================================" << endl;
    for (size_t i = 0; i < players.size(); i++)
    {
        cout << players[i]->getName()
             << ": " << players[i]->getPoints() << " point(s)" << endl;
    }
    cout << endl;

    if (winners.size() == 1)
    {
        cout << "Festival Champion: " << winners[0] << "!" << endl;
    }
    else
    {
        cout << "It is a tie between ";
        for (size_t i = 0; i < winners.size(); i++)
        {
            cout << winners[i];
            if (i + 2 == winners.size())
            {
                cout << " and ";
            }
            else if (i + 1 < winners.size())
            {
                cout << ", ";
            }
        }
        cout << "!" << endl;
    }

    cout << "Arigato for playing at the Cho-Han festival table." << endl;
}
