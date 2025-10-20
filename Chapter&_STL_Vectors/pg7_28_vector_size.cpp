/*
Vectors can report the number of elements they contain - by using size memeber function.
*/

#include <iostream>
#include <vector>

using namespace std;

void getValues(vector<int> &);
void showValues(vector<int>);

int main()
{

    vector<int> numbers;
    getValues(numbers);
    showValues(numbers);

    return 0;
}

void getValues(vector<int> &numbers)
{
    int user_number;
    cout << "Enter integer values (type any letter to quit):\n";

    while (cin >> user_number)
    {
        numbers.push_back(user_number);
    }
}

void showValues(vector<int> numbers)
{
    for (int i = 0; i < numbers.size(); i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;
}
