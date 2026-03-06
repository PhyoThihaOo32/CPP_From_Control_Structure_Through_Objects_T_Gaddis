/*
at() return a reference to the element at specified location, with bound checking
if pos is not within the range of the container, an exception of type std::out_of_range is thrown
*/

#include <iostream>
#include <vector>
#include <chrono>
#include <stdexcept>
#include <cstddef>

using namespace std;

void showTime();

int main()
{

    std::vector<int> data{1, 2, 3, 4, 5};

    data.at(1) = 6; // set element 1 to 6

    // read element at 3
    cout << "Element at index 3 " << data.at(3) << endl;
    cout << "Size of vector " << data.size() << endl;

    try
    {
        return data.at(10);
    }
    catch (const out_of_range &e)
    {
        cout << e.what() << endl;
    }

    return 0;
}

void showTime()
{
    const auto time_now = chrono::system_clock::now();
    const time_t t_c = chrono::system_clock::to_time_t(time_now);

    cout << "Current Time: " << ctime(&t_c);
}