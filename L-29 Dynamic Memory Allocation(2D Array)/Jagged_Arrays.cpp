#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int row = 4;
    int **arr = new int *[row];
    int size[4] = {3, 2, 5, 1};

    for (int i = 0; i < 4; i++)
    {
        arr[i] = new int[size[i]];
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < size[i]; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < size[i]; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}