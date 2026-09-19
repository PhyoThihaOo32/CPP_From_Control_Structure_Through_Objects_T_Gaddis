#ifndef PERSONTYPE_H
#define PERSONTYPE_H

#include <string>
#include <iostream>

using namespace std;

class personType
{
private:
    string firstName;
    string lastName;

public:
    // function to output the first name and last name ( eg: Micheal Jordan)
    void print() const;

    // function to set firstName and lastName
    void setName(string first, string last);

    // function to return first name
    string getFirstName() const;

    // function to return last name
    string getLastName() const;

    // constructor
    personType(string first = "", string last = "");
};

void personType::print() const
{
    cout << firstName << " " << lastName;
}

void personType::setName(string first, string last)
{
    firstName = first;
    lastName = last;
}

string personType::getFirstName() const
{
    return firstName;
}

string personType::getLastName() const
{
    return lastName;
}

personType::personType(string first, string last) : firstName(first), lastName(last)
{
}

#endif