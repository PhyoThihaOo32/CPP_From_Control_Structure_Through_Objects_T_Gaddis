/*
Consider this data sequence: “fish bird reptile reptile bird bird bird mammal fish”.
Let’s define a SINGLETON to be a data element that is not repeated immediately before or
after itself in the sequence. So, here there are four SINGLETONs
(the first appearance of “fish”, the first appearance of “bird”, “mammal”, and
the second appearance of “fish”).

Write some code that uses a loop to read a sequence of words,
terminated by the “xxxxx”.
The code assigns to the variable n the number of SINGLETONs that were read.
(For example in the above data sequence it would assign 4 to n).
Assume that n has already been declared but not initialized.
Assume that there will be at least one word before the terminating “xxxxx”.
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{

    string cur, pre, next;
    cin >> pre;
    cin >> cur;

    int n = 0;

    if (cur == "xxxxx")
    {
        n = 1; // only one word before sentinel
    }
    else
    {
        while (cin >> next && next != "xxxxx")
        {
            if (cur != pre && cur != next)
            {
                n++;
            }
            pre = cur;
            cur = next;
        }

        // check first word
        if (pre != cur)
        {
            n++;
        }
        // check last word before "xxxxx"
        if (cur != pre)
        {
            n++;
        }
    }

    return 0;
}