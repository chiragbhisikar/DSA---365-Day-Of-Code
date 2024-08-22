// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output : [ 1, 2, 3, 6, 9, 8, 7, 4, 5 ]
// https://leetcode.com/problems/spiral-matrix/description/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
void printArray(int arr[3][3], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
}
void spiralOrder(int matrix[][3], int row, int col)
{
    int startRow = 0;
    int endingCol = col - 1;
    int startCol = 0;
    int endingRow = row - 1;
    int count = 0, total = row * col;

    while (count < total)
    {
        // Printing Starting Row
        for (int i = startCol; i <= endingCol && (count < total); i++)
        {
            cout << matrix[startRow][i] << "\t";
            count++;
        }
        startRow++;

        // Printing Last Col
        for (int i = startRow; i <= endingRow && (count < total); i++)
        {
            cout << matrix[i][endingCol] << "\t";
            count++;
        }
        endingCol--;

        // // Printing Last Row
        for (int i = endingCol; i >= startCol && (count < total); i--)
        {
            cout << matrix[endingRow][i] << "\t";
            count++;
        }
        endingRow--;

        // // Printing Starting Col
        for (int i = endingRow; i >= startRow && (count < total); i--)
        {
            cout << matrix[i][startCol] << "\t";
            count++;
        }
        startCol++;
    }
}

int main()
{
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    printArray(arr, 3, 3);
    spiralOrder(arr, 3, 3);
    return 0;
}