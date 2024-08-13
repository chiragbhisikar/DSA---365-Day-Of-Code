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
void moveZeroes(vector<int> &nums)
{
    int nonZero = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            swap(nums[i], nums[nonZero]);
            nonZero++;
        }
    }
    printArray(nums);
}

int main()
{
    vector<int> arr;
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(0);
    arr.push_back(3);
    arr.push_back(12);

    moveZeroes(arr);
    return 0;
}