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

    for (int i = 0; i < n - 1; i++)
    {
        bool isSorted = true;
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
            isSorted = false;
        }
        if (isSorted)
        {
            return;
        }
    }
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