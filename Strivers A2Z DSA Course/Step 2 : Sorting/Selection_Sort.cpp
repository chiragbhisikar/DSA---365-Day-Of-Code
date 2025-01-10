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
        int min = i;
        for (int j = i; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
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