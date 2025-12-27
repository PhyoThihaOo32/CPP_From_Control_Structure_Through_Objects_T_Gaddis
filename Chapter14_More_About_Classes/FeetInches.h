#ifndef FEETINCHES_H
#define FEETINCHES_H

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
};

#endif