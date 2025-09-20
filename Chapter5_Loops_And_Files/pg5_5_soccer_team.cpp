/*
This program calculate the number of soccer teams that a youth league may create from the
number of available players. Input Validation is demostrated with the while loop.
*/

#include <iostream>

using namespace std;

int main()
{

    // constants for min and max players allowed
    const int MIN_PLAYER = 9,
              MAX_PLAYER = 15;

    // variables
    int players,          // numbers of avaliable players
        teamPlayers,      // numbers of desired players per team
        numTeams,         // numbers of team
        leftover_players; // number of players left over

    char user_option;

    // get the number of players per team
    cout << "How many player do you wish per team?" << endl;
    cin >> teamPlayers;

    // validate the input
    while (teamPlayers < MIN_PLAYER || teamPlayers > MAX_PLAYER)
    {
        // explain the error
        cout << "You should have at least " << MIN_PLAYER
             << " but no more than " << MAX_PLAYER << " per team.\n";

        // get input again
        cout << "How many player do you wish per team?" << endl;
        cin >> teamPlayers;
    }

    // get the number of players available
    cout << "How many players are available?\n";
    cin >> players;

    // validate the input
    while (players <= MIN_PLAYER)
    {
        cout << "There should be at least " << MIN_PLAYER << " to make a team.\n";
        cin >> players;
    }

    // calculate the number of teams
    numTeams = players / teamPlayers;

    // calculate the number of leftover player
    leftover_players = players % teamPlayers;

    // display the results
    cout << "There will be " << numTeams << " teams with "
         << leftover_players << " players left over.\n";

       return 0;
}