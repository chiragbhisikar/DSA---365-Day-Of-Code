#include <iostream>
#include <bits/stdc++.h>

using namespace std;
bool isPresent(int arr[3][4], int target, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] == target)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    // int arr[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int arr[3][4] = {{1, 2, 3, 4}, {4, 5, 6, 7}, {7, 8, 9, 10}};

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[j][i] << "\t";
        }
        cout << endl;
    }

    int target = 0;
    cout << "Search : ";
    cin >> target;

    if (isPresent(arr, target, 3, 4))
    {
        cout << "Element Is Present!" << endl;
    }
    else
    {
        cout << "Element Is Not Present!" << endl;
    }
    return 0;
}