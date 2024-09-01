// Binary Search Using Recursion

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}
// int binarySearch(int arr[], int size, int key)
// {
//     printArray(arr, size);
//     if (size == 1)
//     {
//         if (arr[0] == key)
//         {
//             return arr[0];
//         }
//         return 0;
//     }

//     int mid = (0 + size) / 2;

//     if (arr[mid] == key)
//     {
//         return arr[mid];
//     }
//     // Search Right Part
//     else if (arr[mid] < key)
//     {
//         int remainingPart = binarySearch(arr + (mid + 1), mid, key);
//         return remainingPart;
//     }
//     // Search Left Part
//     else
//     {
//         int remainingPart = binarySearch(arr, mid, key);
//         return remainingPart;
//     }
// }

int binarySearch(int arr[], int start, int end, int key)
{
    if (start > end)
    {
        return -1;
    }
    int mid = (start + end) / 2;

    if (arr[mid] == key)
    {
        return mid;
    }
    // Search Right Part
    else if (arr[mid] < key)
    {
        start = mid + 1;
        int remainingPart = binarySearch(arr, start, end, key);
        return remainingPart;
    }
    // Search Left Part
    else
    {
        end = mid - 1;
        int remainingPart = binarySearch(arr, start, end, key);
        return remainingPart;
    }
}
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    cout << binarySearch(arr, 0, 5, 5) << endl;
    cout << "========================================" << endl;
    cout << binarySearch(arr, 0, 5, 1) << endl;
    cout << "========================================" << endl;
    cout << binarySearch(arr, 0, 5, 2) << endl;
    cout << "========================================" << endl;
    cout << binarySearch(arr, 0, 5, 10) << endl;

    return 0;
}