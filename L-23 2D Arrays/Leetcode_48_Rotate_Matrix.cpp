// https://leetcode.com/problems/rotate-image/description/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void printArray(int arr[4][4], int row, int col)
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

void rotateMatrix(int arr[][4], int size)
{
    // Not Optimal
    // int ans[3][3] = {0};
    // int row = size - 1;
    // for (int i = 0; i < size; i++)
    // {
    //     for (int j = 0; j < size; j++)
    //     {
    //         ans[j][row] = arr[i][j];
    //     }
    //     row--;
    // }

    // Optimal

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }

    int row = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size / 2; j++)
        {
            swap(arr[row][j], arr[row][size - j - 1]);
        }
        row++;
    }
    printArray(arr, 4, 4);
}
int main()
{
    // int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int arr[4][4] = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    rotateMatrix(arr, 4);
    return 0;
}