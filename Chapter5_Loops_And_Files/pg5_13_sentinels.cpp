/*
A sentinel is a special value that marks the end of a list of values[ or a value which can terminate the loop.]

This program calculate the total number of point a scoccer team has earned over a series of games.
*/

#include <iostream>

using namespace std;

int main()
{

    // variables
    int games = 1;           // counter
    double total_scores = 0; // accumulator
    double scores;

    // constant for sentinel
    const int SENTINEL = -1;

    cout << "Enter the number of points your team has earned\n"
         << "so far in the season, then enter -1 when finished.\n\n";
    cout << "Enter the point for the game: " << games << endl;
    cin >> scores;

    while (scores != SENTINEL)
    {

        // calculate the total score
        total_scores += scores;

        // count the game
        games++;

        cout << "Enter the point for the game: " << games << endl;
        cin >> scores;
    };

    cout << "Total number of scores for " << --games << " games:\t" << total_scores << endl;

    return 0;
}