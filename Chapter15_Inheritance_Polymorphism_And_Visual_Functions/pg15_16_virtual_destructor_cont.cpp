/*
    Demonstration: Virtual destructor ensures proper cleanup
    --------------------------------------------------------
    • When the base destructor is declared virtual,
      deleting a derived object through a base pointer
      calls BOTH destructors (derived → base).
    • This enables safe polymorphic destruction.
*/

#include <iostream>
using namespace std;

class Animal
{
public:
    Animal()
    {
        cout << "Animal Constructor Executing." << endl;
    }

    // ✅ Virtual destructor — enables dynamic (runtime) binding
    virtual ~Animal()
    {
        cout << "Animal Destructor Executing." << endl;
    }
};

class Dog : public Animal
{
public:
    Dog()
    {
        cout << "Dog Class Constructor Executing." << endl;
    }

    ~Dog()
    {
        cout << "Dog Class Destructor Executing." << endl;
    }
};

int main()
{
    // Base-class pointer points to derived-class object
    Animal *animalPtr = new Dog;

    /*
        Construction order (always base → derived):
        -------------------------------------------
        1. Animal()  → base constructor runs first
        2. Dog()     → derived constructor runs second
    */

    delete animalPtr;
    /*
        Destruction order (always derived → base):
        ------------------------------------------
        1. Dog::~Dog()     → derived destructor runs first
        2. Animal::~Animal() → then base destructor
        Because the destructor is virtual, the compiler uses
        dynamic (runtime) binding and calls both destructors.
    */
}