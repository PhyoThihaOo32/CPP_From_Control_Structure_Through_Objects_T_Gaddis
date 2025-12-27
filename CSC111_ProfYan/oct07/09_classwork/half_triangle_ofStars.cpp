#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

    for (int i = 1; i <= 10; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "*";
            for (int z = j; z > 0; z--)
            {
                cout << " ";
            }
        }

        cout << endl;
    }

    return 0;
}