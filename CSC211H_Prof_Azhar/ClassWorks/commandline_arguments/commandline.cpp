#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

int main(int argc, char *argv[])
{
    vector<char> vect;
    vector<int> pureNumbers;

    for (int i = 0; i < argc; i++)
    {
        for (int j = 0; argv[i][j] != '\0'; j++)
        {
            vect.push_back(argv[i][j]);
        }
    }

    for (int i = 0; i < vect.size(); i++)
    {
        if (isdigit(vect[i]))
        {
            pureNumbers.push_back(vect[i] - '0');
        }
    }

    for (int n : pureNumbers)
    {
        cout << n << " ";
    }

    return 0;
}