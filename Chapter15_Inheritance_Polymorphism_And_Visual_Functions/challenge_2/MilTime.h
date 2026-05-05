/*
MilTime Class convert time in military(24Hr) format to the standard time format used by the Time Class.
*/

#ifndef MILTIME_H
#define MILTIME_H

#include "Time.h"



class MilTime : public Time{
    private:
        int milHour;
        int milSec;
    public:
        // constructor accept time in military format and convert to standard time (store it in hr, min, sec)
        MilTime(int, int);

        void setTime(int, int); // accepts arg to be store in milhr and milsec and convert to std time format

        int getMilHour()const;

        int getMilSec() const;

        void showTime()const override;

        ~MilTime(){}


};

#endif