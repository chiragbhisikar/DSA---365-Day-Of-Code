// Print Like A Wave

// The sine wave for the matrix:-
// 1 2
// 3 4
// will be [1, 3, 4, 2].
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void wavePrint(int arr[][4], int nRows, int mCols)
{
    for (int i = 0; i < mCols; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < nRows; j++)
            {
                cout << arr[j][i] << "\t";
            }
        }
        else
        {
            for (int j = (nRows - 1); j >= 0; j--)
            {
                cout << arr[j][i] << "\t";
            }
        }
    }
}

int main()
{
    int arr[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    wavePrint(arr, 3, 4);
    return 0;
}