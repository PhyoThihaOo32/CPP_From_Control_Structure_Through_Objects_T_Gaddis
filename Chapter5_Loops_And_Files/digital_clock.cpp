/*
This program demonstrate the nested loop - simulation the digital clock.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

    cout << fixed << right;
    cout.fill('0');

    for (int hour = 0; hour < 24; hour++)
    {

        for (int minute = 0; minute < 60; minute++)
        {
            for (int second = 0; second < 60; second++)
            {
                cout << setw(2) << hour << ":";
                cout << setw(2) << minute << ":";
                cout << setw(2) << second << endl;
            }
        }
    }

    return 0;
}