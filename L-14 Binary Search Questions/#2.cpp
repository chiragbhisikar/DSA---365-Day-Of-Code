// Find Pivot In An Array
// https://www.naukri.com/code360/problems/search-in-rotated-sorted-array_1082554?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2

// Sample Input 1:
// 4 3
// 8 9 4 5
// Sample output 1:
// -1

// Sample Input 2:
// 4 3
// 2 3 5 8

// Sample output 2:
// 1

#include <iostream>
#include <vector>
using namespace std;

int findPivot(vector<int> &arr, int n)
{
    int start = 0, end = n - 1;
    int mid = (start + end) / 2;

    while (start < end)
    {
        if (arr[0] <= arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
        mid = (start + end) / 2;
    }

    return start;
}

int binarySearch(vector<int> &arr, int s, int e, int key)
{
    int start = s, end = e;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        int currentElement = arr[mid];

        // cout << arr[start] << "\t" << arr[mid] << "\t" << arr[end] << endl;

        if (currentElement == key)
        {
            return mid;
        }
        else if (currentElement > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}

int search(vector<int> &arr, int n, int k)
{
    int pivot = findPivot(arr, n);
    // cout << pivot << endl;

    int ans = -1;

    // Search In Left Part
    if (arr[0] <= k && arr[pivot - 1] >= k)
    {
        ans = binarySearch(arr, 0, pivot - 1, k);
    }
    // Search In Right Part
    else
    {
        ans = binarySearch(arr, pivot, n - 1, k);
    }
    // cout << pivot << "\t" << arr[pivot - 1] << endl;

    if (ans != -1)
    {
        return ans;
    }
    return -1;
}

int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);

    cout << search(arr, arr.size(), 2);
    return 0;
}