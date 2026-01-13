// specification file for time class

#ifndef TIME_H
#define TIME_H

class Time
{
private:
    int hour, minute, second;

public:
    Time()
    {
        hour = 0;
        minute = 0;
        second = 0;
    }

    Time(int h, int m, int s)
    {
        hour = h;
        minute = m;
        second = s;
    }

    // accessor function
    int getHour() const { return hour; }
    int getMinute() const { return minute; }
    int getSecond() const { return second; }
};

#endif