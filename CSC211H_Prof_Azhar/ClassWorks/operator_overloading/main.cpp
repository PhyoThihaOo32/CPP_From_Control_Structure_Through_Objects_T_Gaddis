/**
Program Descrition:
Design a MyRobot class with the following:
name, color, type, builtyear, robotX, robotY and print function
Programmer: Dr Azhar
Date: Sept 13th, Sept 14h
**/

#include <iostream>
#include <string>
#include "robot.h"

using namespace std;

/*
//Robot class
class MyRobot
{
  private:
    string name;
    int robotX;
    int robotY;
  public:
  //default constructor
    MyRobot()
    {
        cout<<"Calling the constructor"<<endl;
      robotX=0;
      robotY=0;
    }

      MyRobot(int x, int y)
    {
        cout<<"Calling the constructor with two arguments"<<endl;
      robotX=x;
      robotY=y;
    }
    //destructor
    ~MyRobot()
    {
       cout<<"Calling the destructor"<<endl;

    }
    //return robot name
    string getName()
    {
      return name;
    }
    //set Robot name
    void setName(string n)
    {

      name=n;

    }
    //get Robot's x position
    int getXPosition()
    {
      return robotX;

    }
    //get Robot's y position
    int getYPosition()
    {
      return robotY;

    }
    void print()
    {
        cout<<"Robot Name: "<<getName()<<endl;
        cout<<"Robot X Poistion " << getXPosition()<<endl;
        cout<<"Robot Y Poistion " << getYPosition()<<endl;

    }

};*/
int main()
{
    cout << "Robot World!\n";
    MyRobot ev3(10, 10);
    ev3.setName("EV3 Robot");
    // ev3.print();
    MyRobot ev4(10, 10);
    ev4.setName("EV4 Robot");
    // ev4.print();
    MyRobot k5 = ev4; /*copy constructor is calle when you creating a new object assinging from the new object*/
    ev4 = ev3;        /*assignment operator is called when you are assigning a new value to an excisiting object*/

    point myPoint1;
    myPoint1.print();

    point myPoint2;
    myPoint2.print();

    if (myPoint1 == myPoint2)
    {
        cout << "Same location" << endl;
    }
    else
    {
        cout << "Not Same location" << endl;
    }

    cout << "Distance : " << myPoint2 - myPoint1 << endl;

    point myPoint3(30, 40);
    point myPoint4(50, 60);

    cout << "Distance : " << myPoint4 - myPoint3 << endl;

    MyRobot ev5(myPoint2);
    ev5.print();

    MyRobot ev6("ev6", myPoint2);
    ev6.print();

    if (ev5 == ev6)
    {
        cout << "They are at the same location" << endl;
    }
    else
        cout << ev4.getName() << " and " << ev3.getName() << " are not at the same location" << endl;
    ev4.print();
    ev5 = ev4;
    ev5.print();
}
