#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    time_t now = time(nullptr);

    // display seconds since January 1, 1970
    cout << "Seconds since epoch: " << now << endl;

    // convert time to string using ctime()
    cout << "Current time: " << ctime(&now) << endl;

    struct tm *local_time = localtime(&now);
    int year = local_time->tm_year + 1900;
    cout << year << endl;
    int month = local_time->tm_mon + 1;
    cout << month << endl;
    int day = local_time->tm_mday;
    cout << day << endl;

    return 0;
}

/*
struct tm Member
tm_year: Year since 1900
tm_mom: Month(0-11)
tm_mday: Day of month(1-31)
tm_hour: Hours(0-23)
tm_min: Minutes(0-59)
tm_sec: Seconds(0_61)
tm_wday: Day of Week (0-6, Sunday = 0)
*/