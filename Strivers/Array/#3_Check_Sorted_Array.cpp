#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int isSorted(int n, int arr[])
{
    for (int i = 0; i < (n - 1); i++)
    {
        if (!(arr[i] <= arr[i + 1]))
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n = 5;
    int arr[5] = {1, 2, 3, 4, 5};
    cout << "Array Is " << ((isSorted(n, arr) == 1) ? "Sorted" : "Not Sorted") << endl;

    n = 5;
    int arr1[5] = {1, 2, 3, 5, 4};
    cout << "Array Is " << ((isSorted(n, arr1) == 1) ? "Sorted" : "Not Sorted") << endl;

    return 0;
}