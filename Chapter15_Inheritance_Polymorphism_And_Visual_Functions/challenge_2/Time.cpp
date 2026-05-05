#include "Time.h"

using namespace std;

void Time::setTime(int hr, int min, int sec){
    hour = hr;
    minute = min;
    second = sec;
}

void Time::showTime()const{
    cout << hour << " : " << minute << " : " << second << endl;
}