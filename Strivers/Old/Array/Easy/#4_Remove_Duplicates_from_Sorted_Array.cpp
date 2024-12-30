#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int removeDuplicates(int arr[], int n)
{
    // First Approach Optimal For This Problem Only
    /*
       int count = 0;
       for (int i = 0; i < n; i++)
       {
           if (!(arr[i] == arr[i + 1]))
           {
               count++;
           }
       }
       return count;
    */

    // Two Pointer
    int frontPointer = 1, frontPointerElement = arr[0];

    for (int i = 0; i < n; i++)
    {
        if (frontPointerElement != arr[i])
        {
            frontPointerElement = arr[i];
            frontPointer++;
            swap(arr[i], arr[frontPointer]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;

    cout << frontPointer << endl;
    return frontPointer;
}
int main()
{
    int arr[10] = {1, 1, 1, 1, 1, 2, 2, 2, 4, 4};
    int n = 10;
    cout << removeDuplicates(arr, n) << endl;
    return 0;
}