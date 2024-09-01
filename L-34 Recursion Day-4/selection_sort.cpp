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
void sortArray(int arr[], int n)
{
    if (n == 0 || n == 1)
        return;

    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[max] < arr[i])
        {
            max = i;
        }
    }
    swap(arr[max], arr[n - 1]);
    sortArray(arr, n - 1);
}

int main()
{
    int arr[5] = {2, 1, 4, 5, 3};
    printArray(arr, 5);
    sortArray(arr, 5);
    printArray(arr, 5);

    return 0;
}