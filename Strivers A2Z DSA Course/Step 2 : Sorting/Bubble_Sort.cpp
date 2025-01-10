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

void sort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        bool isSorted = true;
        for (int j = 0; j < (n - i - 1); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                isSorted = false;
                swap(arr[j], arr[j + 1]);
            }
        }
        if (isSorted)
        {
            break;
        }
    }
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