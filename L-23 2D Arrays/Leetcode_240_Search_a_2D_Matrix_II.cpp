// https://leetcode.com/problems/search-a-2d-matrix-ii/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool searchMatrix(int matrix[][5], int row, int col, int target)
{
    // int row = matrix.size(), col = matrix[0].size();
    int rowIndex = 0, colIndex = col - 1;

    while (rowIndex < row && colIndex >= 0)
    {
        int element = matrix[rowIndex][colIndex];

        if (element == target)
        {
            return true;
        }
        if (element < target)
        {
            rowIndex++;
        }
        else
        {
            colIndex--;
        }
    }
    return false;
}

int main()
{
    int matrix[5][5] = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    cout << searchMatrix(matrix, 5, 5, 5) << endl;

    return 0;
}