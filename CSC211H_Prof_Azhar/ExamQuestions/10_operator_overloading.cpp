/*
Consider the class below:

class Rational
{
     private:
          int numerator;
          int denominator;
     public:
          Rational () { numerator = 1; denominator = 1;}
          Rational(int ,int);
};

a) Overload the == operator so that a client of the class Rational will be able to check if two Rational objects are equal. Just give the overloaded function code.


b) Overload the operator >> so that a client can write:
      Rational f1;
      cout<<”Enter a rational number in the form  a/b “;
      cin>> f1;
*/

#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

using namespace std;

class Rational
{
private:
    int numerator;
    int denominator;

public:
    Rational()
    {
        numerator = 1;
        denominator = 1;
    }
    Rational(int, int);

    // overloaded operators
    bool operator==(const Rational &);
    friend istream &operator>>(istream &, Rational &);
};

#endif

Rational::Rational(int n, int d)
{
    if (d != 0)
    {
        numerator = n;
        denominator = d;
    }
    else
    {
        cout << "Denominator can't be zero." << endl;
        exit(0);
    }
}

bool Rational::operator==(const Rational &rational)
{
    return (numerator * rational.denominator == rational.numerator * denominator);
}

istream &operator>>(istream &istrm, Rational &rational)
{
    char slash;
    istrm >> rational.numerator >> slash >> rational.denominator;
    return istrm;
}