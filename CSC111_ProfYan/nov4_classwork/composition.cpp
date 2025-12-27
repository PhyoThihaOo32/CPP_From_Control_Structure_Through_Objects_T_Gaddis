#include <iostream>

using namespace std;

int min(int, int);

int main()
{
    int a, b, c;
    cout << "Type  3 values: " << endl;
    cin >> a >> b >> c;

    cout << min(a, b);

    return 0;
}

int min(int x, int y)
{
    int min;
    if (x < y)
    {
        min = x;
    }
    else
        min = y;
    return min;
}