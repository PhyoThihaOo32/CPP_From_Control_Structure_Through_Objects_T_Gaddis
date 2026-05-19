/*
Dynamic Array Vs Regular Array

Dynamic array is created during runtime using new keyword.
Advantages:
1. size can be decided while the program is running
2. therefore more flexible than a fixed-size regular array
3. useful when we do not know the number of elements ahead of time
4. memory is allocated only as and when need
5. can be created on the heap, so it can store large data than local stack arrays

*/

#include <iostream>

using namespace std;

int main()
{
    int size;
    cin >> size;

    int *arr = new int[size];
}