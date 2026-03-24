#include <iostream>
#include <string>
#include "point.h"
using namespace std;

class MyRobot
{
private:
    string name;
    // int robotX;
    // int robotY;
    point robotLocation;

public:
    // default constructor
    MyRobot();
    MyRobot(MyRobot &r1);

    MyRobot(int x, int y);

    // to do sept 14th
    MyRobot(point);

    MyRobot(string a, point myPoint);

    // destructor
    ~MyRobot();

    // return robot name
    string getName();

    // set Robot name
    void setName(string n);

    // get Robot's x position
    int getXPosition();

    // get Robot's y position
    int getYPosition();

    void setXPosition(int m);
    void setYPosition(int n);

    bool operator==(MyRobot &r1);
    void operator=(MyRobot &r1);

    void print();
};
