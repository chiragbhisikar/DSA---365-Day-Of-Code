#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void rowWiseSum(int arr[][4], int row, int col)
{
    for (int i = 0; i < col; i++)
    {
        int sum = 0;
        for (int j = 0; j < row; j++)
        {
            sum += arr[j][i];
        }
        cout << sum << "\t";
    }
    cout << endl;
}

void largestRowSum(int arr[][4], int row, int col)
{
    int maxi = 0;
    for (int i = 0; i < col; i++)
    {
        int sum = 0;
        for (int j = 0; j < row; j++)
        {
            sum += arr[j][i];
        }
        if (sum > maxi)
        {
            maxi = sum;
        }
        // cout << sum << "\t";
    }
    // cout << endl;
    cout << maxi << endl;
}

void colWiseSum(int arr[][4], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum += arr[i][j];
        }
        cout << sum << "\t";
    }
    cout << endl;
}

void largestColSum(int arr[][4], int row, int col)
{
    int maxi = 0;
    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum += arr[i][j];
        }
        if (sum > maxi)
        {
            maxi = sum;
        }
    }
    cout << maxi << endl;
}
int main()
{
    int arr[3][4] = {{1, 2, 3, 4}, {4, 5, 6, 7}, {7, 8, 9, 10}};

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[j][i] << "\t";
        }
        cout << endl;
    }

    rowWiseSum(arr, 3, 4);
    colWiseSum(arr, 3, 4);

    largestRowSum(arr, 3, 4);
    largestColSum(arr, 3, 4);
    return 0;
}