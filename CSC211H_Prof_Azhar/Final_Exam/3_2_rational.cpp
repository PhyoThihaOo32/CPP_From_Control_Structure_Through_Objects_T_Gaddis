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
    bool operator==(const Rational &);
    friend istream &operator>>(istream &in, Rational &);
    friend ostream &operator<<(ostream &out, const Rational &);
};

bool Rational::operator==(const Rational &r)
{
    return (numerator * r.denominator == denominator * r.numerator) ? true : false;
}

istream &operator>>(istream &in, Rational &r)
{
    cout << "Numerator: ";
    in >> r.numerator;
    cout << "Denominator: ";
    in >> r.denominator;
    return in;
}

ostream &operator<<(ostream &out, const Rational &r)
{
    out << "Numerator: " << r.numerator << endl
        << "Denominator: " << r.denominator << endl;
    return out;
}