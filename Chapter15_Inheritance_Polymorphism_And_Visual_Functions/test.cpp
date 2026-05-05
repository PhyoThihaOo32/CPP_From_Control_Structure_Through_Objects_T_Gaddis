#include <iostream>

using namespace std;

class Base{
    protected:
        int number;
    public:
        void print()const {
            cout << "Base" << endl;
        }

    
};

class Derived : public Base{
    public:
        // void print() const{
        //     cout << "Derived" << endl;
        // }

        void printNumber()const{
            cout << "Number : " << number << endl;
        }
};

class Third : public Derived{
    public:
        // void print() const{
        //     cout << "Third" << endl;
        // }
};

int main(){

    Derived d;

    // cout << d.number << endl; 

    Third t;

    t.print();

    return 0;
}

/*
Without virtual, C++ calls the nearest function in the inheritance chain. With virtual, it calls the correct function based on the actual object at runtime.
*/