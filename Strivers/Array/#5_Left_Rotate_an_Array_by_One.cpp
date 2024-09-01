#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> rotateArray(vector<int> &arr, int n)
{
    // My Approach
    for (int i = 0; i < n - 1; i++)
    {
        swap(arr[i], arr[i + 1]);
    }

    return arr;
}

int main()
{

    return 0;
}