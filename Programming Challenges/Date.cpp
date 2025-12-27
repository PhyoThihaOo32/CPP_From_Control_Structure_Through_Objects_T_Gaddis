#include "Date.h"
#include <iostream>
using namespace std;

void Date::setMonth(int m) { month = m; }
void Date::setDay(int d) { day = d; }
void Date::setYear(int y) { year = y; }

int Date::getMonth() const { return month; }
int Date::getDay() const { return day; }
int Date::getYear() const { return year; }

string Date::getMonthName() const
{
    static const string monthNames[12] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"};

    if (month >= 1 && month <= 12)
        return monthNames[month - 1];
    else
        return "Invalid Month";
}

void Date::printddmmyyd() const
{
    cout << day << "/" << month << "/" << year << endl;
}

void Date::printmmddyy() const
{
    cout << getMonthName() << " " << day << ", " << year << endl;
}

void Date::printddmmyyl() const
{
    cout << day << " " << getMonthName() << " " << year << endl;
}