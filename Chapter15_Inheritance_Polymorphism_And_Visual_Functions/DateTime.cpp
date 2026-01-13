// implementation file for the DateTime class

#include <iostream>
#include <string>
#include "DateTime.h"

using namespace std;

DateTime::DateTime() : Date(), Time() {}

/*
The order of the base class constructor calls appear in the list does not matter. They are
always called in the order of inheritance. That is, they are always called in the order
they are listed in the first line of the declaration.
    class DateTime : public Date, public Time
Because Date is listed before Time in the DateTime class declaration, the Date constructor will
always be called first. If the class use destructors, they are always called in reverse order of
inheritance.
*/

DateTime::DateTime(int day, int month, int year, int hour, int min, int second)
    : Date(day, month, year), Time(hour, min, second) {}

void DateTime::showDateTime() const
{
    cout << getMonth() << "/" << getDay() << "/" << getYear() << endl;
    cout << getHour() << "/" << getMinute() << "/" << getSecond() << endl;
}