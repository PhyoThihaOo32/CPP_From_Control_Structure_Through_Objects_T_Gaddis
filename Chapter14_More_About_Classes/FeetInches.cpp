// implementation file for FeetInches class

#include "FeetInches.h"
#include <cstdlib>

void FeetInches::simplify()
{
    if (inch >= 12)
    {
        feet += (inch / 12);
        inch = inch % 12;
    }
    else if (inch < 0)
    {
        feet -= ((abs(inch) / 12) + 1);
        inch = 12 - (abs(inch) % 12);
    }
}

FeetInches &FeetInches::operator+=(const FeetInches &right)
{
    inch += right.inch;
    feet += right.feet;
    simplify();

    return *this;
}

FeetInches FeetInches::operator+(const FeetInches &right)
{
    FeetInches temp;
    temp.inch = inch + right.inch;
    temp.feet = feet + right.feet;
    temp.simplify();

    return temp;
}

FeetInches FeetInches::operator-(const FeetInches &right)
{
    FeetInches temp;
    temp.inch = inch - right.inch;
    temp.feet = feet - right.feet;
    temp.simplify();
    return temp;
}

FeetInches &FeetInches::operator++()
{
    inch++;
    simplify();
    return *this;
}
/*
(++obj1) = obj2;   // works because ++obj1 returns a reference (an lvalue)
If you returned by value, the expression ++obj1 = obj2 would fail,
because a temporary copy (rvalue) can’t be assigned to.
*/

FeetInches FeetInches::operator++(int)
{
    FeetInches temp(feet, inch);
    inch++;
    simplify();
    return temp;
}

bool FeetInches::operator>(const FeetInches &right)
{
    bool status;
    if (feet > right.feet)
        status = true;
    else if (feet == right.feet && inch > right.inch)
        status = true;
    else
        status = false;

    return status;
}

bool FeetInches::operator<(const FeetInches &right)
{
    bool status;
    if (feet < right.feet)
        status = true;
    else if (feet == right.feet && inch < right.inch)
        status = true;
    else
        status = false;

    return status;
}

bool FeetInches::operator==(const FeetInches &right)
{
    bool status;
    if (feet == right.feet && inch == right.inch)
        status = true;
    else
        status = false;

    return status;
}