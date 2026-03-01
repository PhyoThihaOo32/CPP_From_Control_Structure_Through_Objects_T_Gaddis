#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> numbers;

    for (int i = 0; i < 5; i++)
    {
        numbers.push_back(i);
    }

    // begin() end()
    vector<int>::iterator it;
    for (it = numbers.begin(); it != numbers.end(); it++)
    {
        cout << *it << " ";
    }

    // element access
    


    return 0;
}