// implementation file for TeamLeader Class

#include <iostream>
#include "TeamLeader.h"

using namespace std;

TeamLeader::TeamLeader(): monthlyBonus(0),  reqTrainingHour(0), attTrainingHour(0){}

TeamLeader::TeamLeader(double mbonus, int rhr, int ahr): monthlyBonus(mbonus), reqTrainingHour(rhr), attTrainingHour(ahr){}

TeamLeader::TeamLeader(string name, int number, int date, int shift, double pay_rate, double mbonus, int rhr, int ahr): ProductionWorker(name, number, date, shift, pay_rate), monthlyBonus(mbonus), reqTrainingHour(rhr), attTrainingHour(ahr){}

double TeamLeader::getMonthlyBonus()const{return monthlyBonus;}


int TeamLeader::getReqTrainingHour() const{return reqTrainingHour;}

int TeamLeader::getAttTrainingHour() const{return attTrainingHour;}

void TeamLeader::setMonthlyBonus(double bonus){
    monthlyBonus = bonus;
}

void TeamLeader::setReqTrainingHour(int rhr){
    reqTrainingHour = rhr;
}

void TeamLeader::setAttTrainingHour(int ahr){
    attTrainingHour = ahr;
}

void TeamLeader::printInfo() const{
    ProductionWorker::printInfo();
    cout << "Monthly Bonus: " << monthlyBonus << endl
         << "Required Training Hour: " << reqTrainingHour << endl
         << "Attended Training Hour: " << attTrainingHour << endl;

}
