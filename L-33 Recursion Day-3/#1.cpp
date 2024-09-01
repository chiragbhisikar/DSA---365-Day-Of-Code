// isSorted Array
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isSorted(int arr[], int size)
{
    if (size == 1 || size == 0)
    {
        return true;
    }

    if (arr[0] > arr[1])
    {
        return false;
    }
    else
    {
        bool remainingPart = isSorted(arr + 1, size - 1);
        return remainingPart;
    }
}
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    cout << (isSorted(arr, 5) ? "Sorted" : "Not Sorted") << endl;
    return 0;
}