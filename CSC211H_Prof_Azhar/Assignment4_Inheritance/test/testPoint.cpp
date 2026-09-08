// unit test for point class

#include "Point.h"
#include <iostream>

using namespace std;

int main(){

    Point p1, p2(2,2);

    p1.print();
    p2.print();

    p1.set(23,3);
    p1.print();

    return 0;
}