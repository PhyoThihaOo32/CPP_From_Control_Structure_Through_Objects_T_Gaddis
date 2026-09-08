// implementation file for Robot class

#include "Robot.h"
#include <iostream>

using namespace std;

Robot::Robot(): Creature(){
    num_vacuumed = 0;
}

// vacuum up the dirt 
void Robot::vacuum(){
    cout << "shrooop!" << endl;
    num_vacuumed++;
}

// the robot is busy there is dirt and need to vacuum
bool Robot::busy(int num_spots){
    return num_vacuumed < num_spots ? true : false;
}

// robot sing happy birthday song
void Robot::speak(){
    cout << "Sol Sol La Sol Do Ti Sol Sol La Sol Re Do Sol Sol (Higher)Sol Mi Do Ti La Fa Fa Mi Do Re Do" << endl;
}