#include <iostream>

using namespace std;

class myClass
{
public:
    myClass()
    {
        cout << "Constructor";
    }
    ~myClass()
    {
        cout << "Destructor";
    }
};

int main()
{

    myClass *ptr = new myClass();
    delete ptr;

    return 0;
}