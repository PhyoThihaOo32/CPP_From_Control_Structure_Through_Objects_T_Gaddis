//.cpp file
// class point definition
#include "point.h"

point::point()
{
    x = 0;
    y = 0;
}
// point::point (double a, double b)
point::point(double x, double y)
{
    this->x = x;
    this->y = y;
    // x=a;
    // y=b
}

double point::getX() { return x; }
double point::getY() { return y; }
void point::setX(int m) { x = m; }
void point::setY(int n) { y = n; }

void point::print() const
{
    cout << "(x , y): ";
    cout << "(" << x << "," << y << ")\n";
} // end of print()
void point::set(double u, double v)
{
    x = u;
    y = v;
}

bool point::operator==(point &r1)
{
    bool status = false;

    if (this->getX() == r1.getX() && this->getY() == r1.getY())
    {
        status = true;
    }
    return status;
}

double point::operator-(point &right)
{
    double distance;
    distance = sqrt(pow((this->getX() - right.getX()), 2) + pow((this->getY() - right.getY()), 2));

    return distance;
}
