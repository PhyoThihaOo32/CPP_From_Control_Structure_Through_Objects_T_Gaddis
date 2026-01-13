/*
This program demonstrate a class with the multiple inheritance.
*/

#include "DateTime.h"

using namespace std;

int main()
{

    DateTime emptyDay;

    emptyDay.showDateTime();

    DateTime johnBirthday(12, 19, 1998, 11, 19, 11);

    johnBirthday.showDateTime();

    return 0;
}
