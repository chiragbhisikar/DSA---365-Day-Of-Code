#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int row, col;
    cin >> row >> col;

    // Create 2D Array
    int **arr = new int *[row];
    for (int i = 0; i < col; i++)
    {
        arr[i] = new int[row];
        //  *(arr + i) = new int[row];
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    // releasing array
    for (int i = 0; i < col; i++)
    {
        delete[] (arr[i]);
    }
    delete[] (arr[row]);

    int *oneD = new int[row];
    delete[] oneD;

    int *n = new int;
    delete n;

    return 0;
}