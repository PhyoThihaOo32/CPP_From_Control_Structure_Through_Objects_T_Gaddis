/*
Destructor: A destructor is a special member function of a class that is automatically called
when an object is destroyed.
It is mainly used to release resources such as dynamic memory, files or other system resources.

Properties:
1. same name as the class but start with ~
2. no return type
3. takes no parameter
4. cannot be overloaded
5. called automatically when the object is goes out of scope

*/

#include <memory>

class Student
{
private:
    std::unique_ptr<int> sPtr;

public:
    ~Student()
    {
    }
};