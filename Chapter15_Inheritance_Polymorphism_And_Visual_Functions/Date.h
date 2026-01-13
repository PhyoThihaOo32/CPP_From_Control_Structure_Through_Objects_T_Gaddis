// specification file for date class

#ifndef DATE_H
#define DATE_H

class Date
{
private:
    int day, month, year;

public:
    Date()
    {
        day = 1;
        month = 1;
        year = 1900;
    }

    Date(int d, int m, int y)
    {
        day = d;
        month = m;
        year = y;
    }

    // accessor
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }
};

#endif