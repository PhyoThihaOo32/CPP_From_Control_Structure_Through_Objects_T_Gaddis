/*
This program demonstrates the order in which base and derived class constructors and
destructors are called.
*/

#include <iostream>

using namespace std;

class BaseClass
{
    // note: You can’t create this object when its constructor is private.
public:
    BaseClass()
    {
        cout << "This is BaseClass Constructor." << endl;
    }

    ~BaseClass()
    {
        cout << "This is BaseClass Destructor." << endl;
    }
};

class DerivedClass : public BaseClass
{
public:
    DerivedClass()
    {
        cout << "This is DerivedClass Constructor." << endl;
    }

    ~DerivedClass()
    {
        cout << "This is DerivedClass Destructor." << endl;
    }
};

int main()
{
    cout << "Instantiating the DerivedClass Object..." << endl;
    DerivedClass derived;

    cout << "Exiting main..." << endl;
    return 0;
}