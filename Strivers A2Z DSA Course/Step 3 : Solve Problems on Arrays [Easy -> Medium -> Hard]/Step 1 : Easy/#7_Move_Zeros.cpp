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

void moveZeroes(int nums[], int n)
{
    int nonZero = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != 0)
        {
            swap(nums[i], nums[nonZero]);
            nonZero++;
        }
    }
}
int main()
{
    int arr[] = {1, 2, 0, 4, 5};
    print(arr, 5);
    moveZeroes(arr, 5);
    print(arr, 5);
    return 0;
}