#include <iostream>

int main()
{

    int x = 1, y = 2, z = 5;
    std::cout << "Average of x and y is " << (x + y) / 2.0 << std::endl;
    std::cout << static_cast<double>(y) / z << std::endl;

    return 0;
}