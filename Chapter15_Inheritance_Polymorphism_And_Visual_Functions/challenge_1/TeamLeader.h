#ifndef TEAMLEADER_H
#define TEAMLEADER_H

#include "ProductionWorker.h"

using namespace std;

class TeamLeader: public ProductionWorker{
    private:
        double monthlyBonus;
        int reqTrainingHour;
        int attTrainingHour;
    public:
        TeamLeader();
        TeamLeader(double, int, int);
        TeamLeader(string, int, int, int , double, double, int, int);

        double getMonthlyBonus()const;
        int getReqTrainingHour() const;
        int getAttTrainingHour() const;

        void setMonthlyBonus(double);
        void setReqTrainingHour(int);
        void setAttTrainingHour(int);

        void printInfo() const override;

};

#endif