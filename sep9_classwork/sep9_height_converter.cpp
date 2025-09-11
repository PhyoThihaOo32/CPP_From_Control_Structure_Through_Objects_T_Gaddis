/*
This progream ask user for height in inches
And convert and print it into ft and inches accordingly.
*/

#include <iostream>

using namespace std;

int main()
{

    int user_height_inches, height_ft, height_inch;

    // ask user's height in inches
    cout << "How tall are you? Enter in inches: " << endl;
    cin >> user_height_inches;

    height_ft = user_height_inches / 12;   // calculating feets
    height_inch = user_height_inches % 12; // calculating inches

    // showing result to the console
    cout << "You are " << height_ft << " fts and " << height_inch << " inches ("
         << height_ft << "'" << height_inch << "\")" << " tall." << endl;

    return 0;
}