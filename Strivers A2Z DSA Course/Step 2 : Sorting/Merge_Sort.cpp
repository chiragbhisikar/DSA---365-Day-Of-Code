#include <bits/stdc++.h>

using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int arr[], int low, int mid, int high)
{
    vector<int> temp;
    int left = low, right = mid + 1;

    // left -> [low ... mid] & right -> [mid + 1 ... high]

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low, index = 0; i <= high; i++, index++)
    {
        arr[i] = temp[index];
    }
    
    temp.clear();
}

void mergeSort(int arr[], int low, int high)
{
    if (low == high)
        return;

    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);

    merge(arr, low, mid, high);
}

void sort(int arr[], int n)
{
    mergeSort(arr, 0, n - 1);
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    int n = 5;

    print(arr, n);
    sort(arr, n);
    print(arr, n);
    return 0;
}