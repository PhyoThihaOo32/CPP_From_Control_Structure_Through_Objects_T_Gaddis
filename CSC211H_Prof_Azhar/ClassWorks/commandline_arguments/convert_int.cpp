#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
    vector<int> numbers;

    for (int i = 1; i < argc; i++)
    {
        numbers.push_back(atoi(argv[i]));
    }

    for (int n : numbers)
    {
        cout << n << " ";
    }

    return 0;
}