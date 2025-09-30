/*
This progream ask user for height in inches
And convert and print it into ft and inches accordingly.
*/

#include <iostream>

using namespace std;

int main()
{

    int user_ht_inches, ht_ft, ht_inch;

    // ask user's height in inches
    cout << "How tall are you? Enter in inches: " << endl;
    cin >> user_ht_inches;

    ht_ft = user_ht_inches / 12;   // calculating feets
    ht_inch = user_ht_inches % 12; // calculating inches

    // showing result to the console
    cout << "You are " << ht_ft << " fts and " << ht_inch << " inches ("
         << ht_ft << "'" << ht_inch << "\")" << " tall." << endl;

    return 0;
}