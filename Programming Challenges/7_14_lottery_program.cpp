#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void generateRandomNumArray(int[], int);
int *getUserNumArray();
bool checkLotteryNum(const int *, const int *, int, int &);

int main()
{
    const int SIZE = 5;
    int lottery[SIZE];
    int sameNumCount;
    bool isWinner;

    generateRandomNumArray(lottery, SIZE);

    cout << "Lottery numbers: ";
    for (int num : lottery)
        cout << num << " ";
    cout << endl;

    int *userNum = getUserNumArray();

    cout << "Your numbers: ";
    for (int i = 0; i < SIZE; i++)
        cout << userNum[i] << " ";
    cout << endl;

    isWinner = checkLotteryNum(lottery, userNum, SIZE, sameNumCount);

    if (isWinner)
        cout << "🎉 OMG You Win the Grand Prize!" << endl;
    else
        cout << "Sorry — you didn't win. Matches: " << sameNumCount << endl;

    delete[] userNum; // prevent memory leak

    return 0;
}

void generateRandomNumArray(int array[], int size)
{
    srand(time(0));

    for (int i = 0; i < size; i++)
        array[i] = rand() % 10; // 0–9
}

int *getUserNumArray()
{
    int *pArray = new int[5];

    for (int i = 0; i < 5; i++)
    {
        cout << "Enter digit " << i + 1 << " (0–9): ";
        cin >> pArray[i];

        while (pArray[i] < 0 || pArray[i] > 9)
        {
            cout << "Invalid. Enter 0–9: ";
            cin >> pArray[i];
        }
    }

    return pArray;
}

bool checkLotteryNum(const int *array1, const int *array2, int size, int &count)
{
    count = 0;

    for (int i = 0; i < size; i++)
    {
        if (array1[i] == array2[i])
            count++;
    }

    return (count == size); // win if all match
}

/*
==================== FIXES APPLIED ====================

1️Random number range fixed
--------------------------------
OLD:
(rand() % 9) + 1  → generates numbers 1–9

BUT assignment requires 0–9

FIX:
rand() % 10

Now correctly generates digits from 0 to 9.

-------------------------------------------------------

2️Added missing header <ctime>
--------------------------------
srand(time(0)) requires <ctime>

Without it → compile warning/error.

FIX:
#include <ctime>

-------------------------------------------------------

3️Input validation added
--------------------------------
User could enter numbers outside 0–9.

FIX:
Loop now checks input and asks again if invalid.

Prevents incorrect data.

-------------------------------------------------------

4️Memory leak fixed
--------------------------------
getUserNumArray() uses new int[5]
but memory was never freed.

FIX:
delete[] userNum;

Added at end of main().

-------------------------------------------------------

5️Logic bug in checkLotteryNum()
--------------------------------
OLD behavior:
Loop stopped at first mismatch → incorrect match count.

Example:
Lottery: 1 2 3 4 5
User:    1 9 3 9 5
Count should be 3, but old code returned 1.

FIX:
Removed break;
Loop now checks all elements.

-------------------------------------------------------

6️Win condition corrected
--------------------------------
OLD:
win variable toggled inside loop → unreliable.

FIX:
win = (count == size);

Now user wins ONLY if all digits match.

-------------------------------------------------------

7️Improved clarity of variable names
--------------------------------
sameNumCount now properly updated
and reflects actual number of matches.

-------------------------------------------------------

8️Program now follows assignment rules exactly
--------------------------------
✔ Random digits 0–9
✔ Count matching digits
✔ Detect grand prize correctly
✔ Display correct results
✔ No memory leak
✔ Safe input

======================================================
*/