#ifndef DATE_H
#define DATE_H

#include <string>
using namespace std;

class Date
{
private:
    int month, day, year;

public:
    void setMonth(int);
    void setDay(int);
    void setYear(int);

    int getMonth() const;
    int getDay() const;
    int getYear() const;

    string getMonthName() const;

    void printddmmyyd() const;
    void printmmddyy() const;
    void printddmmyyl() const;
};

#endif