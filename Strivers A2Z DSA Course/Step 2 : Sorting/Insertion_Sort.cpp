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
        int element = arr[i];
        int j = i - 1;
        while (j >= 0 && element < arr[j])
        {
            swap(arr[j + 1], arr[j]);
            j--;
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