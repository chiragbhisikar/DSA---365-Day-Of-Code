// 88. Merge Sorted Array
// Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
// Output: [1,2,2,3,5,6]

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
void printArray(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    vector<int> ans;
    int num1Ptr = 0, num2Ptr = 0;

    while (num1Ptr < m && num2Ptr < n)
    {
        if (nums1[num1Ptr] == nums2[num2Ptr])
        {
            ans.push_back(nums1[num1Ptr]);
            num1Ptr++;
            ans.push_back(nums2[num2Ptr]);
            num2Ptr++;
        }
        else if (nums1[num1Ptr] < nums2[num2Ptr])
        {
            ans.push_back(nums1[num1Ptr]);
            num1Ptr++;
        }
        else if (nums1[num1Ptr] > nums2[num2Ptr])
        {
            ans.push_back(nums2[num2Ptr]);
            num2Ptr++;
        }
    }

    while (num1Ptr < m)
    {
        ans.push_back(nums1[num1Ptr]);
        num1Ptr++;
    }

    while (num2Ptr < n)
    {
        ans.push_back(nums2[num2Ptr]);
        num2Ptr++;
    }
    printArray(ans);
}

int main()
{
    vector<int> arr1;
    vector<int> arr2;

    arr1.push_back(1);
    arr1.push_back(2);
    arr1.push_back(3);

    arr2.push_back(2);
    arr2.push_back(5);
    arr2.push_back(6);

    merge(arr1, 3, arr2, 3);
    return 0;
}