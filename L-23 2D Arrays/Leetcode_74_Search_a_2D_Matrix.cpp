// https://leetcode.com/problems/search-a-2d-matrix/description/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
bool searchMatrix(vector<vector<int>> &matrix, int row, int col, int target)
{
    int start = 0;
    int end = (row * col) - 1;
    int mid = (start + end) / 2;

    while (start <= end)
    {
        int element = matrix[mid / col][mid % col];

        if (element == target)
        {
            return true;
        }
        else if (element < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = (start + end) / 2;
    }
    return false;
}
int main()
{

    return 0;
}