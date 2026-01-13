// specification file for date time class

#ifndef DATETIME_H
#define DATETIME_H

#include <string>
#include "Date.h"
#include "Time.h"

using namespace std;

class DateTime : public Date, public Time
{
private:
public:
    // default constructor
    DateTime();

    DateTime(int, int, int, int, int, int);

    void showDateTime() const;
};

#endif