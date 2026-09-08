#include <iostream>

using namespace std;

class Time
{
protected:
    int hour;
    int minute;
    int second;

public:
    Time(int h, int m, int s) : hour(h), minute(m), second(s)
    {
    }

    void printTime()
    {
        cout << hour << ":" << minute << ":" << second << endl;
    }

    bool operator==(const Time &t)
    {
        return (hour == t.hour && minute == t.minute && second == t.second) ? true : false;
    }
};

int main()
{

    Time t1(1, 1, 1), t2(1, 1, 1);

    if (t1 == t2)
        cout << "Same Clock!" << endl;

    return 0;
}