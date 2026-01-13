/*
This program has subtle error in the virtual functions.
*/

#include <iostream>

using namespace std;

class Base
{
public:
    virtual void print(int arg) const
    {
        cout << "Printing Base Class Function." << endl;
    }
};

class Derived : public Base
{
public:
    virtual void print(double arg) const
    {
        cout << "Printing Derived Class Function." << endl;
    }
};

int main()
{

    Base *bPtr = new Derived();
    Derived *dPtr = new Derived();

    bPtr->print(99);
    (*dPtr).print(100.0);

    return 0;
}