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
void rotateArray(int arr[], int n)
{
    /*

    // My Approach
    for(int i = 0; i < n-1; i++){
        swap(arr[i],arr[i+1]);
    }

    return arr;
    */

    int temp = arr[0];

    for (int i = 0; i < n; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[n - 1] = temp;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    print(arr, 5);
    rotateArray(arr, 5);
    print(arr, 5);
    return 0;
}