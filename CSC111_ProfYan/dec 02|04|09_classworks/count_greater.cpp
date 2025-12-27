#include <iostream>

using namespace std;

int count_greater(const float[], float, int);

int main()
{

    float ranNum[] = {12.5, 7.8, 19.2, 3.4, 15.6, 8.9, 21.0, 5.5, 13.3, 10.1};

    int passNum = count_greater(ranNum, 5, 10);

    cout << "Couning Number more than 5: " << passNum << endl;

    return 0;
}

int count_greater(const float array[], float value, int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (value < array[i])
        {
            count++;
        }
    }

    return count;
}
