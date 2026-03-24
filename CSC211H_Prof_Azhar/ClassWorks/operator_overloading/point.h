#include <iostream>
#include <cmath>
using namespace std;
class point
{
private:
    double x, y;

public:
    // default
    point();

    // to do sept 14th
    point(double x, double y);

    void print() const;
    double getX();
    double getY();
    void setX(int m);
    void setY(int n);
    void set(double u, double v);
    bool operator==(point &r1);
    double operator-(point &r1);
}; // end of class--don’t forget semi-colon!
