#include "MilTime.h"

using namespace std;

MilTime::MilTime(int milHour, int milSec): Time(milHour/100, milHour % 100, milSec), milHour(milHour), milSec(milSec){}

void MilTime::setTime(int milHour, int milSec){

    this->milHour = milHour;
    this->milSec = milSec;
    
    int hour, min, sec;
    hour = milHour / 100;
    min = milHour % 100;
    sec = milSec;
    Time::setTime(hour, min, sec);
}

int MilTime::getMilHour()const{
    return milHour;
}

int MilTime::getMilSec() const{
    return milSec;
}

void MilTime::showTime()const{
    cout << milHour << " : " << milSec << endl;
}



