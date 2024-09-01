#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int getSecondLargest(int arr[], int n)
{
    int max = arr[0];
    int secondLargest = -1;

    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
        {
            secondLargest = max;
            max = arr[i];
        }
        else if (arr[i] < max && secondLargest < arr[i])
        {
            secondLargest = arr[i];
        }
    }
    cout << "Second Largest Element Is " << secondLargest << endl;

    return secondLargest;
}

int getSecondSmallest(int arr[], int n)
{
    int min = arr[0], secondSmallest = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (min > arr[i])
        {
            secondSmallest = min;
            min = arr[i];
        }
        else if (arr[i] != min && secondSmallest > arr[i])
        {
            secondSmallest = arr[i];
        }
    }
    return secondSmallest;
}

void getSecondOrderElements(int n, int arr[])
{
    int min = INT_MAX, max = arr[0];
    int secondSmallest = getSecondSmallest(arr, n), secondLargest = getSecondLargest(arr, n);

    cout << secondLargest << "\t" << secondSmallest << endl;
}

int main()
{
    // int arr[5] = {1, 2, 3, 7, 5};
    // int arr[4] = {3, 4, 5, 2};
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    getSecondOrderElements(10, arr);
    return 0;
}