// 724. Find Pivot Index
// https://leetcode.com/problems/find-pivot-index/

#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << "\t";
    }
    cout << "\n";
}

int pivotIndex(vector<int> &nums)
{
    int total = 0;
    int leftSum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        total += nums[i];
    }

    for (int i = 0; i < nums.size(); i++)
    {
        int rightSum = total - leftSum - nums[i];

        if (rightSum == leftSum)
        {
            return i;
        }
        leftSum = leftSum + nums[i];
    }

    return -1;
}

int main()
{
    vector<int> arr;
    // nums = [1,7,3,6,5,6]
    // Output : 3
    arr.push_back(1);
    arr.push_back(7);
    arr.push_back(3);
    arr.push_back(6);
    arr.push_back(5);
    arr.push_back(6);

    // Input: nums = [2,1,-1]
    // Output: 0
    // Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
    // Right sum = nums[4] + nums[5] = 5 + 6 = 11

    // arr.push_back(2);
    // arr.push_back(1);
    // arr.push_back(-1);
    // Left sum = 0 (no elements to the left of index 0)
    // Right sum = nums[1] + nums[2] = 1 + -1 = 0

    // Input: nums = [1,2,3]
    // Output: -1
    // arr.push_back(1);
    // arr.push_back(2);
    // arr.push_back(3);

    // Input: nums = [-1,-1,-1,-1,-1,0]
    // Output: 2
    // arr.push_back(-1);
    // arr.push_back(-1);
    // arr.push_back(-1);
    // arr.push_back(-1);
    // arr.push_back(-1);
    // arr.push_back(0);
    cout << pivotIndex(arr) << endl;
    return 0;
}