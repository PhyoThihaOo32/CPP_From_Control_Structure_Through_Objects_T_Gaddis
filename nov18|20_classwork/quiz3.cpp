#include <iostream>
using namespace std;

char printSign(float);
int getAvg(int, int);
bool isEndMark(char);
void swap(float &, float &);

int main()
{
    float user_num, extra_num = 1;
    char user_char;

    cout << "Enter a float number: ";
    cin >> user_num;
    cout << "Sign of " << user_num << " is " << printSign(user_num) << endl;

    cout << "Average of 11 and 12 is " << getAvg(11, 12) << endl;

    cout << "Enter a character: ";
    cin >> user_char;
    cout << (isEndMark(user_char) ? "That is an end mark." : "Not an end mark.") << endl;

    swap(user_num, extra_num);
    cout << "After swapping:\nUser num: " << user_num << "\nExtra num: " << extra_num << endl;

    return 0;
}

char printSign(float num)
{
    if (num < 0)
        return '-';
    if (num > 0)
        return '+';
    return '0';
}

int getAvg(int a, int b)
{
    return (a + b) / 2;
}

bool isEndMark(char c)
{
    return (c == '?' || c == '.' || c == '!');
}

void swap(float &x, float &y)
{
    float temp = x;
    x = y;
    y = temp;
}