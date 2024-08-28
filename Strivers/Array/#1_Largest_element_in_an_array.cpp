#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int largestElement(int arr[10], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max <= arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 60, 100, 99, 1111, 22};
    cout << "Largest Element In Array Is " << largestElement(arr, 10) << endl;
    return 0;
}