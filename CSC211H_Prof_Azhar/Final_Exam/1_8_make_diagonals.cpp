/*
Write a function called make_diagonals that receives two parameters: an 8 by 8 array of integers called two_dim, and an array of 8 integers called one_dim.
The function will copy the array one_dim into BOTH the diagonals of the array two_dim.
*/

#include <iostream>

using namespace std;

void make_diagonals(int two_dim[8][8], int one_dim[])
{
    // diagonal [0][0] [1][1] [2][2]
    // reverse diagonal [0][7] [1][6] [2][5]

    for (int i = 0; i < 8; i++)
    {
        two_dim[i][i] = one_dim[i];
        two_dim[i][7 - i] = one_dim[i];
    }
}
/*
To point the two dimensional the ptr need to know the column of that 2D array.
For example array[8][8] - mean each row has 8 int elements
*ptr will point to each column(each element in the row)
int (*ptr)[8] mean ptr is the pointer to the array of 8 integers.
*/
void print(int (*ptr)[8])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << ptr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    const int SIZE = 8;
    int two_dim[SIZE][SIZE] = {0};
    int one_dim[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8};

    make_diagonals(two_dim, one_dim);
    print(two_dim);

    return 0;

    return 0;
}