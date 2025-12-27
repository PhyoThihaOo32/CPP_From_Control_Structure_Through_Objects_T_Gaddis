// specification file for the car class

#ifndef CAR_H
#define CAR_H

#include <string>

using namespace std;

class Car
{
private:
    int yearModel;
    string make;
    int speed;

public:
    Car(int, string);

    // accessor function
    int getYearModel() const;
    string getMake() const;
    int getSpeed() const;

    // accelerate function will add 5 to speed everytime we call it
    void accelerate();

    // break function will substract 5 from speed everytime we call the function
    void decelerate();
};

#endif