/*
This is the demo program for date class.
It lets the user enter a date, then displays it in multiple format.
*/

#include <iostream>
#include "Date.h"

using namespace std;

int main()
{

    Date today;

    int m, d, y;

    do
    {
        cout << "Enter the day:(1-31)";
        cin >> d;
    } while (d < 1 || d > 31);

    do
    {
        cout << "Enter the month:(1-12)";
        cin >> m;
    } while (m < 1 || m > 12);

    do
    {
        cout << "Enter the year:";
        cin >> y;
    } while (y < 0);

    // set the date
    today.setDay(d);
    today.setMonth(m);
    today.setYear(y);

    // display the date in three format
    today.printddmmyyd();
    today.printddmmyyl();
    today.printmmddyy();

    return 0;
}