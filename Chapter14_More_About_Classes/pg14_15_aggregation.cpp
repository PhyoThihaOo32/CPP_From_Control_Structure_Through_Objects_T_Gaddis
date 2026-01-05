#include "Course.h"

int main()
{
    Course course("Intro to Computer Science",
                  "Kramer", "Shawn", "RH3010",
                  "Starting out with C++", "Gaddis", "Addison-Wesley");

    course.print();

    return 0;
}