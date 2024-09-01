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

void merge(int arr[], int start, int end)
{
    int mid = (start + end) / 2;

    int leftArrayLength = mid - start + 1;
    int rightArrayLength = end - mid;

    int *leftArray = new int[leftArrayLength];
    int *rightArray = new int[rightArrayLength];

    int mainArrayIndex = start;
    for (int i = 0; i < leftArrayLength; i++)
    {
        leftArray[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid + 1;
    for (int i = 0; i < rightArrayLength; i++)
    {
        rightArray[i] = arr[mainArrayIndex++];
    }

    // merge 2 sorted arrays

    int leftPointer = 0;
    int rightPointer = 0;
    mainArrayIndex = start;

    while (leftPointer < leftArrayLength && rightPointer < rightArrayLength)
    {
        if (leftArray[leftPointer] < rightArray[rightPointer])
        {
            arr[mainArrayIndex++] = leftArray[leftPointer++];
        }
        else
        {
            arr[mainArrayIndex++] = rightArray[rightPointer++];
        }
    }

    while (leftPointer < leftArrayLength)
    {
        arr[mainArrayIndex++] = leftArray[leftPointer++];
    }

    while (rightPointer < rightArrayLength)
    {
        arr[mainArrayIndex++] = rightArray[rightPointer++];
    }

    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort(int arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = (start + end) / 2;

    // left part sort
    mergeSort(arr, start, mid);

    // right part sort
    mergeSort(arr, mid + 1, end);

    // merge
    merge(arr, start, end);
}

int main()
{
    int arr[5] = {2, 5, 1, 6, 9};
    // int arr[5] = {2, 1, 5, 4, 3};
    int n = 5;
    mergeSort(arr, 0, n - 1);

    printArray(arr, n);
    return 0;
}