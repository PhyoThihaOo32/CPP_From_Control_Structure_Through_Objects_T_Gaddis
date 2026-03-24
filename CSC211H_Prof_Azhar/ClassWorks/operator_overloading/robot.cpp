#include "robot.h"

MyRobot::MyRobot()
{
    cout << "Calling the constructor" << endl;
    // robotX=0;
    // robotY=0;
    robotLocation.set(0, 0);
}

MyRobot::MyRobot(MyRobot &r1)
{
    this->setName(r1.getName());

    //  this->setXPosition(r1.getXPosition());
    // this->setYPosition(r1.getYPosition());
    this->robotLocation.set(r1.getXPosition(), r1.getYPosition());
    // robotX = r1.getXPosition();
    // this->getYPosition() = r1.getYPosition();

    // robotLocation = r1.robotLocation;

    cout << "Copy constructor is called" << endl;
}

MyRobot::MyRobot(int x, int y)
{
    cout << "Calling the constructor with two arguments" << endl;
    // robotX=x;
    // robotY=y;
    robotLocation.set(x, y);
}

MyRobot::MyRobot(point myPoint)
{
    // int a= myPoint.getX();
    // int b= myPoint.getY();
    // robotLocation.set(a,b);

    robotLocation.set(myPoint.getX(),
                      myPoint.getY());
}

MyRobot::MyRobot(string a, point myPoint)
{
    name = a;
    robotLocation.set(myPoint.getX(),
                      myPoint.getY());
}
// destructor
MyRobot::~MyRobot()
{
    cout << "Calling the destructor" << endl;
}
// return robot name
string MyRobot::getName()
{
    return name;
}
// set Robot name
void MyRobot::setName(string n)
{

    name = n;
}
// get Robot's x position
int MyRobot::getXPosition()
{
    // return robotX;
    return robotLocation.getX();
}
// get Robot's y position
void MyRobot::setYPosition(int n)
{
    // return robotY;
    robotLocation.setY(n);
}

// get Robot's x position
void MyRobot::setXPosition(int m)
{
    robotLocation.setX(m);
}
// get Robot's y position
int MyRobot::getYPosition()
{
    // return robotY;
    return robotLocation.getY();
}

bool MyRobot::operator==(MyRobot &r1)
{
    bool status = false;

    if (this->getXPosition() == r1.getXPosition() && this->getYPosition() == r1.getYPosition())
    {
        status = true;
    }

    return status;
}

void MyRobot::operator=(MyRobot &r1)
{
    this->setName(r1.getName());

    //  this->setXPosition(r1.getXPosition());
    // this->setYPosition(r1.getYPosition());
    this->robotLocation.set(r1.getXPosition(), r1.getYPosition());
    // robotX = r1.getXPosition();
    // this->getYPosition() = r1.getYPosition();

    // robotLocation = r1.robotLocation;
    cout << "Assigment Operator is called" << endl;
}

void MyRobot::print()
{
    cout << "Robot Name: " << getName() << endl;

    cout << "Robot X Poistion " << robotLocation.getX() << endl;
    cout << "Robot Y Poistion " << robotLocation.getY() << endl;
}
