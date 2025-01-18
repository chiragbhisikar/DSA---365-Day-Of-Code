#include <bits/stdc++.h>

using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

void reverse(int arr[], int start, int end)
{
    while (start <= end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}
void rotateArray(int arr[], int n, int k)
{
    // 1 2 3 4 5 6 7 k = 3 => ans = 4 5 6 7 1 2 3
    // For Reversing First Part arr = 3 2 1 4 5 6 7
    // For Reversing Last Part arr = 3 2 1 7 6 5 4
    // For Reversing All Element Of An Array arr = 4 5 6 7 3 2 1
    // ans = arr

    k = k % n;
    // For Reversing First Part
    reverse(arr, 0, k - 1);
    // For Reversing Last Part
    reverse(arr, k, n - 1);
    // For Reversing All Element Of An Array
    reverse(arr, 0, n - 1);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    print(arr, 5);
    rotateArray(arr, 5, 3);
    print(arr, 5);
    return 0;
}