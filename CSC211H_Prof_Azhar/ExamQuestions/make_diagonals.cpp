#include <iostream>

using namespace std;

void make_diagonals(int two_dim[8][8], int one_dim[8]);
void printMatrix(int two_dim[8][8]);

int main()
{
    int two_dim[8][8] = {0};
    int one_dim[8] = {1, 2, 3, 4, 5, 6, 7, 8};

    make_diagonals(two_dim, one_dim);
    printMatrix(two_dim);

    return 0;
}

void make_diagonals(int two_dim[8][8], int one_dim[8])
{
    for (int i = 0; i < 8; i++)
    {
        two_dim[i][i] = one_dim[i];
        two_dim[i][7 - i] = one_dim[i];
    }
}

void printMatrix(int two_dim[8][8])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << two_dim[i][j] << " ";
        }
        cout << endl;
    }
}