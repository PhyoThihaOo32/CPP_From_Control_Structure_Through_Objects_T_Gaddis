#ifndef FEETINCHES_H
#define FEETINCHES_H

#include <iostream>

using namespace std;

class FeetInches
{
private:
    int feet;
    int inch;
    void simplify();

public:
    FeetInches(int f = 0, int i = 0)
    {
        feet = f;
        inch = i;
        simplify();
    }

    // mutator function
    void setFeet(int f)
    {
        feet = f;
    }

    void setInch(int i)
    {
        inch = i;
        simplify();
    }

    // accessor function
    int getFeet() const
    {
        return feet;
    }

    int getInch() const
    {
        return inch;
    }

    // overloaded operator functions
    FeetInches operator+(const FeetInches &);
    FeetInches operator-(const FeetInches &);
    FeetInches &operator+=(const FeetInches &);
    FeetInches &operator++();
    FeetInches operator++(int);
    bool operator>(const FeetInches &);
    bool operator<(const FeetInches &);
    bool operator==(const FeetInches &);

    // object conversation
    // conversion functions do not have an explicit return type,
    // because the type they convert to is the return type.
    operator double();
    operator int();

    // friend functions
    friend ostream &operator<<(ostream &, const FeetInches &);
    friend istream &operator>>(istream &, FeetInches &);

    /*
    Why they need to be friend (if defined outside)
    Here’s the key part:
    •	These operator functions live outside the class (they are global functions).
    •	But they still need access to private members like feet and inch.
    So you declare them as friend inside the class to give them access:
    */
};

#endif