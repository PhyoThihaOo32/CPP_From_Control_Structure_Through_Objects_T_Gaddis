#ifndef POINT_H
#define POINT_H

class Point
{
private:
    int x, y; // x and y co-ordinates

public:
    Point() : x(0), y(0) {}
    void print() const;
    void set(int, int); // mutator
    int getX() const;   // accessor
    int getY() const;

    bool operator==(const Point &) const;
};

#endif
