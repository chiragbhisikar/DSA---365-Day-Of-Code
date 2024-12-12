#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

int partition(int arr[], int start, int end)
{
    int pivot = arr[start];

    // find how many elements are lesser than pivot and count it
    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }

    // placed pivot at right place
    int pivotIndex = start + count;
    swap(arr[start], arr[pivotIndex]);

    // sorting left and right place
    int left = start, right = end;
    while (left < pivotIndex && right > pivotIndex)
    {
        while (arr[left] <= pivot)
        {
            left++;
        }

        while (arr[right] > pivot)
        {
            right--;
        }

        if (left < pivotIndex && right > pivotIndex)
        {
            swap(arr[left++], arr[right--]);
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }

    // create partition first
    int p = partition(arr, start, end);

    // call quicksort for left
    quickSort(arr, start, p - 1);

    // call quicksort for right
    quickSort(arr, p + 1, end);
}

int main()
{
    int arr[6] = {2, 1, 4, 5, 3, 2};
    int n = 6;
    quickSort(arr, 0, n - 1);
    printArray(arr, n);
    return 0;
}