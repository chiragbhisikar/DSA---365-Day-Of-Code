// 852. Peak Index in a Mountain Array
// https://leetcode.com/problems/peak-index-in-a-mountain-array

#include <iostream>
#include <vector>
using namespace std;
int peakIndexInMountainArray(int arr[], int size)
{
    int start = 0, end = size - 1;
    int mid = (start + end) / 2;

    while (start < end)
    {
        mid = (start + end) / 2;
        if (arr[mid] < arr[mid + 1])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }

    return mid;
}
int main()
{
    int arr[] = {0, 1, 0};
    cout << peakIndexInMountainArray(arr, 3);
    return 0;
}