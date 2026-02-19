#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void makeLoshu();

int main()
{
    srand(time(0));
    makeLoshu();

    return 0;
}

void makeLoshu()
{
    bool isLoshu = false;

    do
    {
        int used[10] = {0};
        int randomNum[9];
        int loshu[3][3];

        // generate unique numbers
        for (int i = 0; i < 9; i++)
        {
            int num;
            do
            {
                num = rand() % 9 + 1;
            } while (used[num]);

            used[num] = 1;
            randomNum[i] = num;
        }

        int i = 0;
        for (int r = 0; r < 3; r++)
        {
            cout << "-------------\n";
            cout << "| ";
            for (int c = 0; c < 3; c++)
            {
                loshu[r][c] = randomNum[i++];
                cout << loshu[r][c] << " | ";
            }
            cout << endl;
        }
        cout << "-------------\n";

        int r1 = 0, r2 = 0, r3 = 0;
        int c1 = 0, c2 = 0, c3 = 0;

        // row sums
        for (int c = 0; c < 3; c++)
        {
            r1 += loshu[0][c];
            r2 += loshu[1][c];
            r3 += loshu[2][c];
        }

        // column sums
        for (int r = 0; r < 3; r++)
        {
            c1 += loshu[r][0];
            c2 += loshu[r][1];
            c3 += loshu[r][2];
        }

        // diagonals
        int d1 = loshu[0][0] + loshu[1][1] + loshu[2][2];
        int d2 = loshu[0][2] + loshu[1][1] + loshu[2][0];

        cout << "Row sums: " << r1 << " " << r2 << " " << r3 << endl;
        cout << "Col sums: " << c1 << " " << c2 << " " << c3 << endl;
        cout << "Diag sums: " << d1 << " " << d2 << endl;

        if (r1 == 15 && r2 == 15 && r3 == 15 &&
            c1 == 15 && c2 == 15 && c3 == 15 &&
            d1 == 15 && d2 == 15)
        {
            isLoshu = true;
            cout << "\n🎉 VALID LO SHU MAGIC SQUARE FOUND 🎉\n";
        }

    } while (!isLoshu);
}