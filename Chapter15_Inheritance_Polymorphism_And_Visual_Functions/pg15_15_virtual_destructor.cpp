/*
Note: When you write a class with a destructor and that class could potentially become a base class,
you should always declare the destructor virtual. This is because the compiler will perform static binding
on the destructor if it is not declared virtual. This can lead to problems when a base class pointer or
reference variable references a derived class object.
If the derived class has it own destructor, it will not execute when the object is destroyed or goes out of scope.
Only the base base class destructor will execute.
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

    ~Animal()
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
        cout << "Dog Class Destrutor Executing." << endl;
    }
};

int main()
{
    Animal *animalPtr = new Dog;

    delete animalPtr;
}