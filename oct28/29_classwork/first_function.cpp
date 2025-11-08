#include <iostream>

using namespace std;

// prototype - basically the header followed by semicolum.
void print_greeting();

int main()
{
    print_greeting();
    for (int i = 1; i < 4; i++)
    {
        print_greeting();
    }

    return 0;
}

void print_greeting()
{
    cout << "Eh...How are you?" << endl;
}
