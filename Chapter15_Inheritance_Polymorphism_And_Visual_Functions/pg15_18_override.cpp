/*
The program demonstrates the override keyword.
*/

#include <iostream>

using namespace std;

class Base
{
public:
    virtual void print() const
    {
        cout << "Printing Base Class Function." << endl;
    }

    virtual void unique() const final
    {
        cout << "Nobody can't override me. Never!" << endl;
    }
};

class Derived : public Base
{
public:
    virtual void print() const override
    {
        cout << "Printing Derived Class Function." << endl;
    }
};

int main()
{

    Base *bPtr = new Derived();
    Derived *dPtr = new Derived();

    bPtr->print();
    (*dPtr).print();

    return 0;
}