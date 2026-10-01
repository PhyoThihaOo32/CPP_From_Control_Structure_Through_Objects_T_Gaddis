#include <iostream>
#include "linkedStackType.h"

using namespace std;

int main()
{

    linkedStackType<int> stack;

    for (int i = 0; i < 10; i++)
    {
        stack.push(i);
    }

    // normal print
    stack.print();

    cout << endl;
    // reverse print
    stack.reversePrint();

    return 0;
}