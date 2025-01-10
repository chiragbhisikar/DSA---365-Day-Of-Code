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

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int left = low, right = high;

    while (left < right)
    {
        while (arr[left] <= pivot && left <= high - 1)
        {
            left++;
        }

        while (arr[right] > pivot && right >= low + 1)
        {
            right--;
        }

        if (left < right)
        {
            swap(arr[left], arr[right]);
        }
    }

    swap(arr[low], arr[right]);

    return right;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int partitionIndex = partition(arr, low, high);

        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}
void sort(int arr[], int n)
{
    quickSort(arr, 0, n - 1);
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