// https://www.naukri.com/code360/problems/first-and-last-position-of-an-element-in-sorted-array_1082549?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2&leftPanelTabValue=PROBLEM

// First and Last Position of an Element In Sorted Array

// Sample Input 1:
// 8 2
// n = 8
// key = 2
// 0 0 1 1 2 2 2 2
// Sample output 1:
// 4 7

#include <iostream>
#include <vector>
using namespace std;
int binarySearch(vector<int> &arr, int k, bool isFirstOccurence)
{
    int start = 0, end = arr.size() - 1;
    int ans = -1;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == k)
        {
            ans = mid;
            if (isFirstOccurence)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        else if (arr[mid] < k)
        {
            start = mid + 1;
        }
        else if (arr[mid] > k)
        {
            end = mid - 1;
        }
    }
    return ans;
}

void firstAndLastPosition(vector<int> &arr, int n, int k)
{
    int firstIndex = binarySearch(arr, k, true);
    int lastIndex = binarySearch(arr, k, false);

    cout << "{" << firstIndex << ", " << lastIndex << "}" << endl;
}

int main()
{
    vector<int> arr;
    arr.push_back(0);
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(2);
    arr.push_back(2);
    arr.push_back(2);

    firstAndLastPosition(arr, arr.size(), 2);
    return 0;
}
