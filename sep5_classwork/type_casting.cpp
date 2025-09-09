#include <iostream>

int main()
{

    int x = 5, y = 2, z = 15;
    float result;
    result = x / y;
    std::cout << "Average of x and y is " << (x + y) / 2.0 << std::endl;
    std::cout << static_cast<double>(y) / z << std::endl;
    std::cout << "Result: " << result << std::endl;

    return 0;
}