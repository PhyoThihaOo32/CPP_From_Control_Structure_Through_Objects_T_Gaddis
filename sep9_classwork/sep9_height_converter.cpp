/*
This progream ask user for height in inches
And convert into ft and inches accordingly
*/

#include <iostream>

using namespace std;

int main()
{

    int user_height_inches, height_ft, height_inch;

    cout << "How tall are you? Enter in inches: " << endl;
    cin >> user_height_inches;

    height_ft = user_height_inches / 12;
    height_inch = user_height_inches % 12;

    cout << "You are " << height_ft << " fts and " << height_inch << " inches ("
         << height_ft << "'" << height_inch << "\")" << " tall." << endl;

    return 0;
}